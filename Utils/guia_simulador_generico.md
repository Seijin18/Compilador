# GUIA DE USO DO SIMULADOR MIPS GENÉRICO

## VISÃO GERAL

O simulador MIPS foi completamente refatorado para ser genérico e funcionar com qualquer algoritmo, não apenas para o cálculo do GCD. Agora ele suporta:

### ✅ CARACTERÍSTICAS PRINCIPAIS

1. **Arquitetura Flexível**: Suporte a 8, 16, 32 bits (configurável)
2. **Entrada Configurável**: Qualquer número de valores de entrada
3. **Múltiplas Saídas**: Suporte a programas que fazem várias saídas
4. **Log Detalhado**: Debug completo da execução
5. **Interface Flexível**: Linha de comando ou modo interativo

## COMO USAR

### 1. USO BÁSICO - LINHA DE COMANDO

```bash
# Executar com arquivo assembly padrão
python mips_simulator.py

# Especificar arquivo assembly
python mips_simulator.py meu_programa.asm

# Especificar arquivo e entradas
python mips_simulator.py gcd.asm "48,18"

# Especificar arquivo, entradas e resultado esperado
python mips_simulator.py factorial.asm "5" "120"
```

### 2. MODO INTERATIVO

```bash
python mips_simulator.py
```

O simulador perguntará:
- Nome do arquivo assembly
- Valores de entrada (separados por vírgula)
- Resultado esperado (opcional)

### 3. USO PROGRAMÁTICO

```python
from mips_simulator import MIPSSimulator

# Criar simulador com entradas específicas
simulator = MIPSSimulator(input_values=[10, 5], architecture_bits=32)

# Carregar programa
simulator.load_assembly("meu_programa.asm")

# Executar
result = simulator.run(max_cycles=500)

# Obter todas as saídas
all_outputs = simulator.get_output_values()
print(f"Saídas: {all_outputs}")
```

## EXEMPLOS DE ALGORITMOS SUPORTADOS

### 1. CALCULADORA BÁSICA

**Código C-:**
```c
void main(void) {
    int a, b, op, result;
    a = input();      // Primeiro número
    b = input();      // Segundo número  
    op = input();     // Operação (1=+, 2=-, 3=*, 4=/)
    
    if (op == 1) {
        result = a + b;
    } else if (op == 2) {
        result = a - b;
    } else if (op == 3) {
        result = a * b;
    } else if (op == 4) {
        result = a / b;
    }
    
    output(result);
}
```

**Uso do Simulador:**
```bash
python mips_simulator.py calculadora.asm "15,5,1"  # 15 + 5 = 20
python mips_simulator.py calculadora.asm "15,5,2"  # 15 - 5 = 10
python mips_simulator.py calculadora.asm "15,5,3"  # 15 * 5 = 75
python mips_simulator.py calculadora.asm "15,5,4"  # 15 / 5 = 3
```

### 2. SEQUÊNCIA FIBONACCI

**Código C-:**
```c
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

void main(void) {
    int n = input();
    output(fibonacci(n));
}
```

**Uso do Simulador:**
```bash
python mips_simulator.py fibonacci.asm "8" "21"  # 8º número de Fibonacci = 21
```

### 3. PROGRAMA COM MÚLTIPLAS SAÍDAS

**Código C-:**
```c
void main(void) {
    int i = 1;
    while (i <= 5) {
        output(i * i);  // Quadrados de 1 a 5
        i = i + 1;
    }
}
```

**Uso do Simulador:**
```bash
python mips_simulator.py quadrados.asm
# Saídas esperadas: [1, 4, 9, 16, 25]
```

### 4. ORDENAÇÃO SIMPLES

**Código C-:**
```c
void main(void) {
    int a, b, temp;
    a = input();
    b = input();
    
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    
    output(a);  // Menor
    output(b);  // Maior
}
```

**Uso do Simulador:**
```bash
python mips_simulator.py sort2.asm "7,3"
# Saídas esperadas: [3, 7]
```

## INSTRUÇÕES SUPORTADAS

### ARITMÉTICAS
- `ADD rd, rs, rt` - Adição
- `SUB rd, rs, rt` - Subtração  
- `MULT rs, rt` - Multiplicação (resultado em HI:LO)
- `DIV rs, rt` - Divisão (quociente em HI, resto em LO)
- `ADDI rt, rs, imm` - Adição com imediato
- `SUBI rt, rs, imm` - Subtração com imediato

### LÓGICAS
- `AND rd, rs, rt` - E lógico
- `OR rd, rs, rt` - OU lógico
- `SLL rd, rs, shamt` - Shift left lógico
- `SRL rd, rs, shamt` - Shift right lógico
- `SLT rd, rs, rt` - Set less than

### COMPARAÇÃO E BRANCH
- `BEQ rs, rt, target` - Branch if equal
- `BNE rs, rt, target` - Branch if not equal
- `BGT rs, rt, target` - Branch if greater than
- `BLT rs, rt, target` - Branch if less than
- `BGTE rs, rt, target` - Branch if greater or equal
- `BLTE rs, rt, target` - Branch if less or equal

### SALTOS
- `J target` - Jump incondicional
- `JAL target` - Jump and link
- `JR rs` - Jump register
- `JALR rs` - Jump and link register

### MEMÓRIA
- `LW rt, offset(rs)` - Load word
- `SW rt, offset(rs)` - Store word
- `LI rt, imm` - Load immediate

### MOVIMENTAÇÃO
- `MOVE rd, rs` - Move registrador
- `MFHI rd` - Move from HI
- `MFLO rd` - Move from LO

### I/O
- `INPUT rd` - Entrada do usuário
- `OUTPUTREG rs` - Saída para display

### CONTROLE
- `HALT` - Para execução

## RECURSOS DE DEBUG

### 1. LOG DETALHADO

O simulador gera automaticamente um arquivo `execution_debug.txt` com:
- Cada instrução executada
- Estado dos registradores
- Fluxo de controle
- Operações realizadas

### 2. ESTADO DOS REGISTRADORES

Durante a execução, o simulador mostra:
- Registradores alterados
- Valores antes e depois
- Operações realizadas

### 3. DETECÇÃO DE PROBLEMAS

- **Loop Infinito**: Detecta quando PC volta ao 0 muitas vezes
- **PC Fora dos Limites**: Evita crashes por endereços inválidos
- **Divisão por Zero**: Trata divisões por zero apropriadamente

## CONFIGURAÇÕES AVANÇADAS

### 1. ARQUITETURA CUSTOMIZADA

```python
# Simulador de 16 bits
simulator = MIPSSimulator(architecture_bits=16)

# Simulador de 8 bits (compatibilidade)
simulator = MIPSSimulator(architecture_bits=8)
```

### 2. LIMITE DE CICLOS

```python
# Executar com limite personalizado
result = simulator.run(max_cycles=2000)
```

### 3. RESET E REUTILIZAÇÃO

```python
# Resetar simulador para novo programa
simulator.reset()
simulator.set_input_values([1, 2, 3])
simulator.load_assembly("novo_programa.asm")
result = simulator.run()
```

## DEBUGGING E SOLUÇÃO DE PROBLEMAS

### 1. PROGRAMA NÃO TERMINA

**Sintomas:**
- Execução interrompida por limite de ciclos
- Mensagem "Possível loop infinito"

**Soluções:**
- Verificar condições de parada em loops
- Aumentar limite de ciclos: `simulator.run(max_cycles=5000)`
- Analisar o log de debug

### 2. RESULTADO INCORRETO

**Soluções:**
- Verificar valores de entrada
- Examinar log de debug linha por linha
- Verificar lógica do programa assembly
- Testar com entradas menores

### 3. ARQUIVO NÃO ENCONTRADO

**Soluções:**
- Verificar nome do arquivo
- Certificar que arquivo está no diretório correto
- Usar caminho absoluto se necessário

### 4. ENTRADA INSUFICIENTE

**Sintomas:**
- Mensagem "INPUT: Sem mais valores"

**Soluções:**
- Fornecer todos os valores de entrada necessários
- Verificar quantos inputs o programa espera

## EXEMPLO COMPLETO

**1. Programa C- (teste.c):**
```c
int max(int a, int b) {
    if (a > b) return a;
    return b;
}

void main(void) {
    int x = input();
    int y = input();
    output(max(x, y));
}
```

**2. Compilar:**
```bash
./compiler teste.c
./assembler intermediate.txt
```

**3. Simular:**
```bash
python mips_simulator.py assembly_output.asm "42,17" "42"
```

**4. Resultado esperado:**
```
✅ Teste PASSOU! Resultado correto: 42
```

Este simulador genérico agora pode executar qualquer programa gerado pelo compilador C- customizado!
