# Correção de Instruções ADDI com Valores Negativos

## Problema Identificado

O código assembly gerado continha instruções `ADDI` com valores imediatos negativos:

```assembly
ADDI R29, R29, -8    # Problemático: valor negativo
```

Isso pode causar problemas de compatibilidade com alguns processadores MIPS que não tratam adequadamente valores negativos em campos immediate de instruções ADDI.

## Solução Implementada

### Função Auxiliar Criada

```c
void add_addi_subi_instruction(int src_reg, int dst_reg, int immediate)
```

Esta função:
- **Para valores positivos**: Usa `ADDI reg, reg, +valor`
- **Para valores negativos**: Usa `SUBI reg, reg, +|valor|`

### Transformação Aplicada

**Antes (problemático):**
```assembly
ADDI R29, R29, -8    # Valor negativo
```

**Depois (corrigido):**
```assembly
SUBI R29, R29, 8     # Valor positivo equivalente
```

## Locais Corrigidos

### 1. Prólogo de Função (`generate_function_prologue`)
- **Linha 7**: `ADDI R29, R29, -8` → `SUBI R29, R29, 8`
- **Função**: Ajuste do Stack Pointer para abrir espaço na pilha

### 2. Função `main` 
- **Linha 44**: `ADDI R29, R29, -8` → `SUBI R29, R29, 8`
- **Função**: Ajuste do Stack Pointer no prólogo da função main

### 3. Instruções Mantidas (Corretas)
- **Linha 39**: `ADDI R29, R29, 8` ✅ (valor positivo)
- **Linha 66**: `ADDI R29, R29, 8` ✅ (valor positivo)
- **Função**: Restauração do Stack Pointer no epílogo

## Equivalência Matemática

As transformações são matematicamente equivalentes:
- `ADDI R29, R29, -8` ≡ `SUBI R29, R29, 8`
- `R29 = R29 + (-8)` ≡ `R29 = R29 - 8`

## Benefícios da Correção

1. **Compatibilidade**: Evita problemas com processadores que não suportam bem immediates negativos
2. **Clareza**: Instruções mais explícitas sobre a operação (subtração vs adição negativa)
3. **Consistência**: Todas as operações usam valores positivos nos campos immediate
4. **Padronização**: Segue boas práticas de assembly MIPS

## Verificação Final

✅ **Nenhuma instrução ADDI com valor negativo** permanece no código
✅ **Todas as instruções SUBI usam valores positivos**
✅ **Funcionalidade mantida** - comportamento idêntico
✅ **71 instruções totais** geradas corretamente

## Exemplo Completo de Prólogo de Função

**Antes:**
```assembly
SUBI R2, R29, 4      # Calcula endereço para salvar RA
SW R31, 0(R2)        # Salva RA
SUBI R2, R29, 8      # Calcula endereço para salvar FP
SW R30, 0(R2)        # Salva FP
ADDI R29, R29, -8    # ❌ Problemático: ajusta SP
MOVE R30, R29        # Estabelece novo FP
```

**Depois:**
```assembly
SUBI R2, R29, 4      # Calcula endereço para salvar RA
SW R31, 0(R2)        # Salva RA
SUBI R2, R29, 8      # Calcula endereço para salvar FP
SW R30, 0(R2)        # Salva FP
SUBI R29, R29, 8     # ✅ Corrigido: ajusta SP
MOVE R30, R29        # Estabelece novo FP
```

Esta correção completa a otimização do assembler para compatibilidade total com a arquitetura de 8 bits do processador MIPS customizado.
