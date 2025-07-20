# Correção para Offsets Negativos em LW/SW

## Problema Identificado

O processador MIPS customizado não suporta deslocamentos negativos nas instruções LW (Load Word) e SW (Store Word). Quando o assembler original tentava gerar instruções como:

```assembly
SW R31, -4(R29)
LW R30, -8(R29)
```

Isso causava problemas porque o campo immediate de 8 bits não pode representar valores negativos adequadamente.

## Solução Implementada

### Função Auxiliar Criada

```c
void add_load_store_with_offset(const char *mnemonic, int opcode, int base_reg, int target_reg, int offset)
```

Esta função:
1. **Para offsets positivos**: Gera a instrução LW/SW diretamente
2. **Para offsets negativos**: 
   - Primeiro executa `SUBI temp_reg, base_reg, |offset|`
   - Depois executa `LW/SW target_reg, 0(temp_reg)`

### Exemplo de Transformação

**Antes (problemático):**
```assembly
SW R31, -4(R29)    # Offset negativo não suportado
```

**Depois (corrigido):**
```assembly
SUBI R2, R29, 4     # Calcula R29 - 4 → R2
SW R31, 0(R2)       # Armazena R31 no endereço calculado
```

## Locais Corrigidos

### 1. Prólogo de Função (`generate_function_prologue`)
- `SW RA, -4(SP)` → `SUBI R2, SP, 4; SW RA, 0(R2)`
- `SW FP, -8(SP)` → `SUBI R2, SP, 8; SW FP, 0(R2)`

### 2. Epílogo de Função (`generate_function_epilogue`)
- `LW FP, -8(SP)` → `SUBI R2, SP, 8; LW FP, 0(R2)`
- `LW RA, -4(SP)` → `SUBI R2, SP, 4; LW RA, 0(R2)`

### 3. Carregamento de Variáveis (`load_variable_to_register`)
- Variáveis locais com offsets negativos do FP

### 4. Salvamento de Registradores (`flush_register`)
- Quando registradores precisam ser salvos na memória

### 5. Atribuições (`asn` operation)
- Salvamento de resultados na memória

### 6. Chamadas de Função
- Salvamento/restauração de RA em offsets específicos
- Passagem de parâmetros via pilha

## Impacto na Performance

- **Aumento de instruções**: De 63 para 71 instruções (8 instruções adicionais)
- **Aumento é justificado**: Garante compatibilidade com a arquitetura do processador
- **Cada offset negativo**: Gera uma instrução SUBI adicional
- **Registrador temporário**: Usa R2 como registrador auxiliar

## Compatibilidade

Esta correção garante que:
1. Todos os offsets são positivos ou zero
2. O assembler funciona corretamente com a limitação de 8 bits para immediate
3. A RAM de 8 bits (0-255) é totalmente utilizável
4. Não há tentativas de acesso a endereços inválidos

## Validação

O assembler corrigido foi testado com sucesso:
- ✅ Compilação sem erros
- ✅ Execução sem problemas
- ✅ Geração de 71 instruções válidas
- ✅ Todos os offsets dentro do range válido (0-255)
- ✅ Instruções LW/SW com offsets não-negativos apenas

## Arquivos Modificados

- `assembler_corrected.c`: Implementação da solução
- `assembly_output_corrected.asm`: Assembly gerado com correções
- `binary_output_corrected.txt`: Código binário corrigido

Esta correção é fundamental para o funcionamento correto do assembler com o processador MIPS customizado de 8 bits.
