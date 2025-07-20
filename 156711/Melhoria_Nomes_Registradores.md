# Melhoria na Legibilidade do Assembly - Nomes de Registradores Especiais

## Melhoria Implementada

O assembler foi modificado para exibir os nomes mnemônicos dos registradores especiais em vez de seus números, tornando o código assembly muito mais legível e profissional.

## Mapeamento de Registradores Especiais

| Número | Nome | Função                    | Exemplo Antes | Exemplo Depois |
|--------|------|---------------------------|---------------|----------------|
| R28    | GP   | Global Pointer           | `LI R28, 128` | `LI GP, 128`   |
| R29    | SP   | Stack Pointer            | `LI R29, 255` | `LI SP, 255`   |
| R30    | FP   | Frame Pointer            | `MOVE R30, R29` | `MOVE FP, SP` |
| R31    | RA   | Return Address           | `SW R31, 0(R2)` | `SW RA, 0(R2)` |

## Implementação Técnica

### Função Auxiliar Criada
```c
const char* get_register_name(int reg_num) {
    switch (reg_num) {
        case 28: return "GP";  // Global Pointer
        case 29: return "SP";  // Stack Pointer
        case 30: return "FP";  // Frame Pointer
        case 31: return "RA";  // Return Address
        default: {
            static char reg_name[8];
            sprintf(reg_name, "R%d", reg_num);
            return reg_name;
        }
    }
}
```

### Modificação da Função de Escrita
A função `write_assembly_file()` foi modificada para usar `get_register_name()` em todas as instruções, substituindo chamadas como:
- `fprintf(file, "R%d", reg)` → `fprintf(file, "%s", get_register_name(reg))`

## Benefícios da Melhoria

### 1. **Legibilidade Melhorada**
**Antes:**
```assembly
3: SUBI       R2, R29, 4      # Não fica claro o que é R29
4: SW         R31, 0(R2)      # Não fica claro o que é R31
7: SUBI       R29, R29, 8     # Não fica claro que é manipulação do SP
8: MOVE       R30, R29        # Não fica claro que é configuração do FP
```

**Depois:**
```assembly
3: SUBI       R2, SP, 4       # Claro que está ajustando Stack Pointer
4: SW         RA, 0(R2)       # Claro que está salvando Return Address
7: SUBI       SP, SP, 8       # Claro que está alocando espaço na pilha
8: MOVE       FP, SP          # Claro que está configurando Frame Pointer
```

### 2. **Facilita Debugging**
- Identificação imediata de operações com pilha
- Reconhecimento rápido de salvamento/restauração de RA
- Clareza nas operações com ponteiros globais

### 3. **Compatibilidade com Padrões MIPS**
- Segue convenções de nomenclatura MIPS padrão
- Facilita compreensão para desenvolvedores familiarizados com MIPS
- Melhora documentação automática do código

### 4. **Manutenção Simplificada**
- Código mais autodocumentado
- Reduz necessidade de comentários extensivos
- Facilita identificação de padrões de uso

## Exemplos de Melhoria em Contexto

### Prólogo de Função
**Antes:**
```assembly
3: SUBI       R2, R29, 4
4: SW         R31, 0(R2)
5: SUBI       R2, R29, 8
6: SW         R30, 0(R2)
7: SUBI       R29, R29, 8
8: MOVE       R30, R29
```

**Depois:**
```assembly
3: SUBI       R2, SP, 4       # Calcula posição para salvar RA
4: SW         RA, 0(R2)       # Salva Return Address
5: SUBI       R2, SP, 8       # Calcula posição para salvar FP
6: SW         FP, 0(R2)       # Salva Frame Pointer anterior
7: SUBI       SP, SP, 8       # Aloca espaço na pilha
8: MOVE       FP, SP          # Estabelece novo Frame Pointer
```

### Epílogo de Função
**Antes:**
```assembly
34: MOVE       R29, R30
35: SUBI       R2, R29, 8
36: LW         R30, 0(R2)
37: SUBI       R2, R29, 4
38: LW         R31, 0(R2)
39: ADDI       R29, R29, 8
```

**Depois:**
```assembly
34: MOVE       SP, FP          # Restaura Stack Pointer
35: SUBI       R2, SP, 8       # Calcula posição do FP salvo
36: LW         FP, 0(R2)       # Restaura Frame Pointer anterior
37: SUBI       R2, SP, 4       # Calcula posição do RA salvo
38: LW         RA, 0(R2)       # Restaura Return Address
39: ADDI       SP, SP, 8       # Desaloca espaço da pilha
```

## Registradores Mantidos como R0-R27

Os registradores R0-R27 mantêm a nomenclatura original porque:
- São registradores de propósito geral sem função específica
- Não há convenção padrão de nomes para eles
- A numeração é mais clara para identificação

## Impacto na Funcionalidade

✅ **Nenhuma alteração funcional** - apenas melhoria visual
✅ **Compatibilidade mantida** - código binário idêntico
✅ **Performance inalterada** - mudança apenas na apresentação
✅ **Legibilidade significativamente melhorada**

Esta melhoria torna o assembler mais profissional e facilita significativamente a leitura e debugging do código assembly gerado.
