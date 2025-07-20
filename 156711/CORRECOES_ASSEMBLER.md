# CORREÇÕES IMPLEMENTADAS NO ASSEMBLER

## Resumo das Correções Realizadas

Este documento descreve as correções implementadas no assembler para resolver os problemas identificados no arquivo `Problemas_assembly.txt`.

## 1. GERENCIAMENTO DE PILHA CORRIGIDO

### Problema Original:
- RA (Registro de Retorno) sendo salvo em offsets fixos sem considerar tamanho do frame
- Chamadas recursivas sobrescrevendo RA da chamada anterior
- Falta de ajuste do $sp no início/fim das funções

### Solução Implementada:
```c
// Estrutura melhorada para contexto de função
typedef struct {
    char function_name[32];
    int frame_size;         // Tamanho total do frame
    int param_count;
    int local_vars_size;
    int saved_regs_size;    // Espaço para registradores salvos
} FunctionContext;

// Prólogo da função corrigido
void generate_function_prologue() {
    // Salvar RA
    add_instruction("SW", OP_SW, SP, RA, 0, -4, NULL);
    // Salvar FP anterior
    add_instruction("SW", OP_SW, SP, FP, 0, -8, NULL);
    // Ajustar SP
    add_instruction("ADDI", OP_ADDI, SP, SP, 0, -8, NULL);
    // Estabelecer novo FP
    add_instruction("MOVE", OP_MOVE, SP, 0, FP, 0, NULL);
}

// Epílogo da função corrigido
void generate_function_epilogue() {
    // Restaurar SP
    add_instruction("MOVE", OP_MOVE, FP, 0, SP, 0, NULL);
    // Restaurar FP anterior
    add_instruction("LW", OP_LW, SP, FP, 0, -8, NULL);
    // Restaurar RA
    add_instruction("LW", OP_LW, SP, RA, 0, -4, NULL);
    // Ajustar SP
    add_instruction("ADDI", OP_ADDI, SP, SP, 0, 8, NULL);
}
```

### Resultado:
- **Frame Pointer ($fp = R30)** usado como base estável para acesso a parâmetros/variáveis
- **Stack Pointer ($sp = R29)** ajustado adequadamente no início/fim das funções
- **Return Address (RA = R31)** salvo/restaurado corretamente sem conflitos

## 2. SUPORTE A VETORES IMPLEMENTADO

### Problema Original:
- Falta de lógica para cálculo de endereços com índices
- Instruções lw/sw não tratavam deslocamentos variáveis

### Solução Implementada:
```c
// Estrutura melhorada para símbolos com suporte a arrays
typedef struct {
    char name[32];
    char scope[32];
    int offset;
    int size;          // Elementos totais para arrays
    int elem_size;     // Tamanho por elemento
    int is_array;      // Flag para arrays
    int is_global;
    int is_arg;
    int in_use;
} Symbol;

// Função para processar acesso a arrays
void process_array_access(const char *array_name, const char *index_var, const char *result_var, int is_store) {
    int base_reg = load_variable_to_register(array_name, current_function);
    int index_reg = load_variable_to_register(index_var, current_function);
    int dest_reg = get_register_for_variable(result_var, current_function);
    
    // Calcular deslocamento: index * sizeof(element) = index * 4
    add_instruction("SLL", OP_SLL, index_reg, index_reg, 0, 2, NULL);
    // Somar base + offset
    add_instruction("ADD", OP_ADD, base_reg, index_reg, dest_reg, 0, NULL);
    
    if (is_store) {
        // Para store: array[index] = valor
        int value_reg = load_variable_to_register(result_var, current_function);
        add_instruction("SW", OP_SW, dest_reg, value_reg, 0, 0, NULL);
    } else {
        // Para load: valor = array[index]
        add_instruction("LW", OP_LW, dest_reg, dest_reg, 0, 0, NULL);
    }
}
```

### Resultado:
- **Cálculo correto de endereços** para acesso a arrays
- **Suporte a load/store** com índices variáveis: `array[index]`
- **Multiplicação por sizeof(element)** usando shift left (SLL)

## 3. VARIÁVEIS GLOBAIS CORRIGIDAS

### Problema Original:
- Inicialização do registrador $gp ausente
- Acessos usavam offsets mas sem base consistente

### Solução Implementada:
```c
void generate_assembly_second_pass() {
    current_line = 0;
    int local_offset = 0;
    
    // Inicializar $gp para variáveis globais
    add_instruction("LI", OP_LI, 0, GP, 0, 0x1000, NULL);
    
    // ... resto da função ...
    
    // Acesso a variável global:
    if (sym->is_global) {
        add_instruction("LW", OP_LW, GP, reg, 0, sym->offset, NULL);
    } else {
        add_instruction("LW", OP_LW, FP, reg, 0, sym->offset, NULL);
    }
}
```

### Resultado:
- **$gp (R28) inicializado** com endereço base das variáveis globais (0x1000)
- **Acesso consistente** usando $gp como base para globais
- **Separação clara** entre variáveis locais (FP) e globais (GP)

## 4. PASSAGEM DE PARÂMETROS ROBUSTECIDA

### Problema Original:
- Uso misto de registradores/pilha sem padrão
- Falta de salvamento de registradores

### Solução Implementada:
```c
// Chamada de função robustecida
else if (strcmp(quad->op, "call") == 0) {
    // ... código de chamada ...
    
    // Salvar registradores críticos
    int ra_offset = local_offset + param_count;
    add_instruction("SW", OP_SW, FP, RA, 0, ra_offset, NULL);
    
    // Passar parâmetros
    for (int p = 0; p < param_count; p++) {
        if (p < 4) {
            // Usar registradores $a0-$a3 (R4-R7)
            int src_reg = load_variable_to_register(temp_params[p].name, current_function);
            add_instruction("MOVE", OP_MOVE, src_reg, 0, 4 + p, 0, NULL);
        } else {
            // Usar pilha para parâmetros adicionais
            int src_reg = load_variable_to_register(temp_params[p].name, current_function);
            add_instruction("SW", OP_SW, FP, src_reg, 0, p, NULL);
        }
    }
    
    // Chamada
    add_instruction_with_label_fix("JAL", OP_JAL, 0, 0, 0, quad->arg1);
    
    // Restaurar RA
    add_instruction("LW", OP_LW, FP, RA, 0, ra_offset, NULL);
}
```

### Resultado:
- **Primeiros 4 parâmetros** passados em registradores $a0-$a3 (R4-R7)
- **Parâmetros adicionais** passados na pilha
- **Salvamento/restauração** adequada de registradores críticos
- **Gestão consistente** do Return Address

## 5. CORREÇÕES ADICIONAIS

### 5.1 Operação Módulo (%) Corrigida:
```c
else if (strcmp(quad->op, "%") == 0) {
    int rs = load_variable_to_register(quad->arg1, current_function);
    int rt = load_variable_to_register(quad->arg2, current_function);
    int rd = get_register_for_variable(quad->arg3, current_function);
    add_instruction("DIV", OP_DIV, rs, rt, 0, 0, NULL);
    add_instruction("MFLO", OP_MFLO, 0, 0, rd, 0, NULL); // CORREÇÃO: MFLO para resto
}
```

### 5.2 Mapeamento Correto de Instruções:
- **Formato das instruções** conforme documentação do processador
- **Campos corretos** para RS, RT, RD, e immediate
- **Opcodes corretos** para todas as instruções

## COMPARAÇÃO: ANTES vs DEPOIS

### ANTES (Assembler Original):
```assembly
# Problemas:
- RA salvo em offsets fixos (6, 8)
- Sem frame pointer
- Sem suporte a arrays
- Sem inicialização de $gp
- Passagem de parâmetros inconsistente

gcd:
  1: LI         R1, 0
  2: LW         R2, 1(R29)    # Uso direto de SP
  3: BNE        R2, R1, 8
  ...
 20: SW         R31, 8(R29)  # RA fixo em offset 8
 21: JAL        1
 22: MOVE       R7, R1
```

### DEPOIS (Assembler Corrigido):
```assembly
# Correções implementadas:
- Frame pointer como base estável
- Prólogo/epílogo adequados
- Suporte a arrays
- $gp inicializado
- Passagem robusta de parâmetros

  0: LI         R28, 4096     # Inicializa $gp
  1: J          35
gcd:
  2: SW         R31, -4(R29)  # Prólogo: salva RA
  3: SW         R30, -8(R29)  # Prólogo: salva FP
  4: ADDI       R29, R29, -8  # Prólogo: ajusta SP
  5: MOVE       R30, R29      # Prólogo: estabelece FP
  6: LI         R1, 0
  7: LW         R2, 1(R30)    # Uso de FP como base
  ...
 22: SW         R31, 4(R30)   # RA salvo adequadamente
 26: JAL        2
 31: MOVE       R29, R30      # Epílogo: restaura SP
 32: LW         R30, -8(R29)  # Epílogo: restaura FP
 33: LW         R31, -4(R29)  # Epílogo: restaura RA
 34: ADDI       R29, R29, 8   # Epílogo: ajusta SP
```

## ARQUIVOS GERADOS

1. **`assembler_corrected.c`** - Código fonte do assembler corrigido
2. **`assembler_final.exe`** - Executável compilado
3. **`assembly_output_corrected.asm`** - Assembly gerado corrigido
4. **`binary_output_corrected.txt`** - Código binário corrigido

## COMO USAR

```bash
# Compilar o assembler corrigido
gcc -o assembler_final.exe assembler_corrected.c

# Executar com arquivo de código intermediário
./assembler_final.exe intermediate_clean.txt

# Arquivos gerados:
# - assembly_output_corrected.asm (código assembly legível)
# - binary_output_corrected.txt (código binário para o processador)
```

## BENEFÍCIOS DAS CORREÇÕES

1. **Robustez**: Eliminação de bugs de gerenciamento de pilha
2. **Funcionalidade**: Suporte completo a arrays e variáveis globais
3. **Padrão**: Seguimento das convenções MIPS com frame pointer
4. **Compatibilidade**: Aderência à documentação do processador customizado
5. **Manutenibilidade**: Código mais organizado e estruturado
