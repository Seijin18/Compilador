# Compilador 156711 - Sistema Completo

Sistema de compilação completo para o processador MIPS customizado, incluindo compilador, gerador de código intermediário e assembler avançado.

> 📚 **DOCUMENTAÇÃO COMPLETA**: Veja [`DOCUMENTACAO_SINTESE.md`](./DOCUMENTACAO_SINTESE.md) para documentação detalhada unificada da síntese (gerador de código intermediário, assembler e gerador de código binário).

## 🏗️ **Estrutura do Projeto**

### **Arquivos Principais**
- `compilador_final.exe` - Compilador principal (gera código intermediário)
- `assembler_corrected.exe` - Assembler avançado (gera assembly e código binário)

### **Código Fonte**
- `bison.y` - Gramática do parser (Bison)
- `bison.tab.c`, `bison.tab.h` - Parser gerado pelo Bison
- `funcs.c`, `funcs.h` - Funções auxiliares do compilador
- `intermediate.c`, `intermediate.h` - Gerador de código intermediário
- `assembler_corrected.c` - Assembler com todas as correções

### **Exemplos e Testes**
- `gcd.c` - Programa exemplo: Algoritmo de Euclides (GCD)
- `test_if_return.c` - Teste para estruturas condicionais
- `sort.c` - Algoritmo de ordenação
- `entrada.txt` - Arquivo de entrada de exemplo

### **Saídas Geradas**
- `intermediate.txt` - Código intermediário (quadruplas)
- `assembly_output.asm` - Código assembly legível
- `binary_output.txt` - Código binário para o processador
- `symbol_table.txt` - Tabela de símbolos
- `tree.txt` - Árvore sintática

## 🚀 **Como Usar**

### **Pipeline Completo (Recomendado)**
```powershell
# Windows - Executar pipeline completo
.\build_full.ps1 run

# Compilar arquivo específico
.\build_full.ps1 run meu_programa.c

# Compilar todos os componentes
.\build_full.ps1 build-all
```

### **Compilação Automática (Apenas Assembler)**
```bash
# Linux/Mac
./build.sh

# Windows (PowerShell)
.\build.ps1

# Makefile
make
```

### **Compilação Manual**
```bash
# Compilar o compilador
gcc -o compilador_final.exe bison.tab.c funcs.c intermediate.c -I.

# Compilar o assembler
gcc -o assembler_corrected.exe assembler_corrected.c
```

### **Uso do Sistema**
```bash
# Método Recomendado (evita problemas de encoding)
.\compilador_final.exe gcd.c | Out-File -Encoding ASCII intermediate.txt
.\assembler_corrected.exe intermediate.txt

# Método Alternativo (pode causar problemas no Windows)
.\compilador_final.exe gcd.c > intermediate.txt
.\assembler_corrected.exe intermediate.txt

# Arquivos gerados:
# - assembly_output.asm (assembly legível com labels)
# - binary_output.txt (código binário 32-bit)
# - tree.txt (árvore sintática)
# - symbol_table.txt (tabela de símbolos)
```

> **⚠️ Nota importante**: No Windows, usar `Out-File -Encoding ASCII` evita problemas de codificação de caracteres que podem impedir o assembler de processar as quadruplas corretamente.

## 🎯 **Funcionalidades**

### **Compilador**
- ✅ Parser completo com Bison
- ✅ Geração de código intermediário (quadruplas)
- ✅ Suporte a funções recursivas
- ✅ Estruturas condicionais (if/else)
- ✅ Operações aritméticas completas
- ✅ Eliminação de código inacessível

### **Assembler**
- ✅ Geração de assembly MIPS customizado
- ✅ Gerenciamento de registradores com LRU
- ✅ Passagem de parâmetros via pilha
- ✅ Chamadas de função recursivas
- ✅ Labels visíveis para funções e loops
- ✅ Otimizações de código
- ✅ Endereçamento correto de branches
- ✅ Geração de código binário

## 📊 **Exemplo de Execução**

**Entrada (`gcd.c`):**
```c
int gcd(int u, int v) {
    if (v == 0) {
        return u;
    } else {
        return gcd(v, u % v);
    }
}

int main() {
    int x, y;
    input(x);
    input(y);
    output(gcd(x, y));
}
```

**Saída (Assembly):**
```assembly
  0: J          21
gcd:
  1: LI         R1, 0
  2: LW         R2, 1(R29)
  3: BNE        R2, R1, 7
  4: LW         R3, 0(R29)
  5: MOVE       R1, R3
  6: JR         R31
L0:
  7: DIV        R3, R2
  8: MFLO       R4
  9: MULT       R4, R2
 10: MFLO       R5
 11: SUB        R6, R3, R5
 12: SW         R2, 0(R29)
 13: SW         R6, 1(R29)
 14: SW         R31, 2(R29)
 15: JAL        1
 16: LW         R31, 2(R29)
 17: MOVE       R7, R1
 18: MOVE       R1, R7
 19: JR         R31
main:
 21: INPUT      R8
 22: MOVE       R9, R8
 23: INPUT      R10
 24: MOVE       R11, R10
 25: SW         R9, 0(R29)
 26: SW         R11, 1(R29)
 27: SW         R31, 2(R29)
 28: JAL        1
 29: LW         R31, 2(R29)
 30: MOVE       R12, R1
 31: OUTPUTREG  R12
 32: JR         R31
 33: HALT
```

## 🔧 **Especificações Técnicas**

**Processador MIPS Customizado:**
- Formato de instrução: [31:26] OPCODE | [25:20] RS | [19:14] RT | [13:8] RD | [7:0] IMMEDIATE
- 32 registradores (R0-R31)
- Pilha: R29 (SP), Return Address: R31 (RA)
- Suporte completo a instruções aritméticas, lógicas, de controle e I/O

**Código Intermediário:**
- Formato de quadruplas: (operação, arg1, arg2, arg3)
- Suporte a labels e controle de fluxo
- Otimizações durante geração

## 📝 **Status do Projeto**

✅ **Compilador**: Funcional e otimizado  
✅ **Assembler**: Completo com todas as correções  
✅ **Testes**: Validados com múltiplos programas  
✅ **Documentação**: Atualizada e completa  

**Projeto finalizado e pronto para uso!** 🚀