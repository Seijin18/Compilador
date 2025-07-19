# Relatório de Correções - Assembler MIPS Customizado

## 📋 Problemas Identificados e Corrigidos

### 🔍 **Verificação Realizada**
Utilizando o script `full_verify.py` e a documentação `instrucoes_processador.md` como referência, foram identificados e corrigidos os seguintes problemas:

### ❌ **Problemas Encontrados**

#### 1. **Formato Incorreto para Instruções Imediatas**
**Problema**: Instruções ADDI/SUBI estavam usando o campo RD em vez de RT como destino.

**Documentação de Referência** (`instrucoes_processador.md`):
- `ADDI RT, RS, IMEDIATO` - `RT = RS + IMEDIATO` (opcode 001111)
- `SUBI RT, RS, IMEDIATO` - `RT = RS - IMEDIATO` (opcode 010000)

**Erro Específico**:
```
SUBI deve ter RD=0, atual RD=29
```

#### 2. **Uso de ADDI com Imediatos Negativos**
**Problema**: O assembler gerava `ADDI R29, R29, -4` em vez de usar a instrução SUBI apropriada.

### ✅ **Correções Implementadas**

#### 1. **Correção do Formato de Instruções Imediatas**

**ANTES**:
```c
// Formato incorreto: RS, RD, immediate
add_instruction("ADDI", OP_ADDI, SP, 0, SP, -frame_size, NULL);
```

**DEPOIS**:
```c
// Formato correto: RS, RT, immediate  
add_instruction("SUBI", OP_SUBI, SP, SP, 0, frame_size, NULL);
```

#### 2. **Substituição de ADDI Negativo por SUBI**

**ANTES**:
```assembly
1: ADDI R29, R29, -4    # Incorreto: imediato negativo
```

**DEPOIS**:
```assembly
1: SUBI R29, R29, 4     # Correto: usar SUBI
```

#### 3. **Atualização da Função `write_assembly_file`**
Adicionado suporte para formatação correta da instrução SUBI:

```c
} else if (strcmp(instr->mnemonic, "SUBI") == 0) {
    fprintf(file, "%3d: %-10s R%d, R%d, %d\n", real_line, instr->mnemonic, 
            instr->rt, instr->rs, instr->immediate);  // SUBI rt, rs, immediate
```

### 📊 **Resultados da Validação**

#### Antes das Correções:
```
INSTRUÇÕES ANALISADAS: 54
TOTAL DE ERROS: 5
❌ FALHA: 5 erro(s) encontrado(s)
```

**Erros específicos:**
- Linha 1: SUBI deve ter RD=0, atual RD=29
- Linha 4: SUBI deve ter RD=0, atual RD=30  
- Linha 12: SUBI deve ter RD=0, atual RD=29
- Linha 32: SUBI deve ter RD=0, atual RD=29
- Linha 36: SUBI deve ter RD=0, atual RD=29

#### Após as Correções:
```
INSTRUÇÕES ANALISADAS: 54
TOTAL DE ERROS: 0
🎉 SUCESSO: Todas as instruções estão codificadas corretamente!
```

### 🎯 **Funções Corrigidas**

#### 1. `setup_function_prologue()`
```c
// Alocação de frame corrigida
add_instruction("SUBI", OP_SUBI, SP, SP, 0, frame_size, NULL);

// Configuração de FP corrigida  
add_instruction("ADDI", OP_ADDI, SP, FP, 0, frame_size - 2, NULL);
```

#### 2. `setup_function_epilogue()`
```c
// Desalocação de frame corrigida
add_instruction("ADDI", OP_ADDI, SP, SP, 0, frame_size, NULL);
```

#### 3. `write_assembly_file()`
```c
// Suporte adicionado para SUBI
} else if (strcmp(instr->mnemonic, "SUBI") == 0) {
    fprintf(file, "%3d: %-10s R%d, R%d, %d\n", real_line, instr->mnemonic, 
            instr->rt, instr->rs, instr->immediate);
```

### 📝 **Assembly Gerado - Comparação**

#### ANTES (Incorreto):
```assembly
gcd:
  1: ADDI       R29, R29, -4    # ❌ Imediato negativo + formato errado
  2: SW         R31, 3(R29)
  3: SW         R30, 2(R29)  
  4: ADDI       R30, R29, 2     # ❌ Formato errado (RD em vez de RT)
```

#### DEPOIS (Correto):
```assembly
gcd:
  1: SUBI       R29, R29, 4     # ✅ SUBI com formato correto
  2: SW         R31, 3(R29)
  3: SW         R30, 2(R29)
  4: ADDI       R30, R29, 2     # ✅ ADDI com formato correto
```

### 🔧 **Verificação de Conformidade**

#### Formato das Instruções Segundo `instrucoes_processador.md`:
```
[31:26] OPCODE | [25:20] RS | [19:14] RT | [13:8] RD | [7:0] IMEDIATO
```

#### Instruções Imediatas Corrigidas:
- **ADDI (001111)**: `ADDI RT, RS, IMEDIATO` → `RT = RS + IMEDIATO`
- **SUBI (010000)**: `SUBI RT, RS, IMEDIATO` → `RT = RS - IMEDIATO`

### ✅ **Status Final**

- ✅ **Todas as 54 instruções** validadas com sucesso
- ✅ **Zero erros** de codificação
- ✅ **Conformidade total** com `instrucoes_processador.md`
- ✅ **Uso apropriado** de SUBI para operações de subtração
- ✅ **Formato correto** para todas as instruções imediatas

### 🎯 **Benefícios Alcançados**

1. **Compatibilidade**: Total conformidade com a especificação do processador
2. **Legibilidade**: Uso semântico correto de SUBI vs. ADDI
3. **Robustez**: Validação automatizada detecta problemas futuros
4. **Manutenibilidade**: Código assembly mais claro e consistente

### 📚 **Arquivos Modificados**

- `assembler_corrected.c` - Correções nas funções de geração
- `assembly_output.asm` - Assembly regenerado com correções
- `binary_output.txt` - Código binário atualizado

### 🧪 **Ferramentas de Validação**

- `full_verify.py` - Script de verificação abrangente
- `instrucoes_processador.md` - Documentação de referência oficial

---

## 🎉 Conclusão

Todas as correções foram implementadas com sucesso, resultando em um assembler que gera código 100% compatível com a especificação do processador MIPS customizado, utilizando adequadamente as instruções SUBI e ADDI conforme suas semânticas apropriadas.
