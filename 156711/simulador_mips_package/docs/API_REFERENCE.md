# API Reference - Simulador MIPS

## 📚 Visão Geral

Esta referência documenta todas as classes, métodos e funções disponíveis no simulador MIPS. Use esta documentação para integrar o simulador em seus próprios projetos.

## 🖥️ Classe Principal: MIPSSimulator

### Constructor

```python
class MIPSSimulator:
    def __init__(self, debug=False):
        """
        Inicializa uma nova instância do simulador MIPS.
        
        Args:
            debug (bool): Ativa modo debug com saída detalhada
        """
```

### Atributos Principais

| Atributo | Tipo | Descrição |
|----------|------|-----------|
| `registers` | `list[int]` | 32 registradores MIPS (R0-R31) |
| `memory` | `list[int]` | 256 posições de memória |
| `pc` | `int` | Program Counter (0-255) |
| `halted` | `bool` | Estado de parada do simulador |
| `display` | `int` | Último valor exibido pelo OUTPUT |
| `input_values` | `list[int]` | Valores para instruções INPUT |
| `input_index` | `int` | Índice atual na lista de entrada |
| `debug` | `bool` | Modo debug ativo |

### Métodos de Carregamento

#### `load_binary_file(filename)`
```python
def load_binary_file(self, filename):
    """
    Carrega instruções de um arquivo binário.
    
    Args:
        filename (str): Caminho para arquivo com instruções binárias
        
    Returns:
        list[int]: Lista de instruções como inteiros 32-bit
        
    Raises:
        FileNotFoundError: Se arquivo não existir
        ValueError: Se formato binário for inválido
        
    Example:
        instructions = simulator.load_binary_file("program.txt")
    """
```

#### `load_instructions_from_string(binary_string)`
```python
def load_instructions_from_string(self, binary_string):
    """
    Carrega instruções de uma string binária.
    
    Args:
        binary_string (str): String com instruções separadas por linha
        
    Returns:
        list[int]: Lista de instruções convertidas
        
    Example:
        binary = "01110000000000000000000000011001\n01001000000000000000100000000000"
        instructions = simulator.load_instructions_from_string(binary)
    """
```

### Métodos de Execução

#### `run(instructions, max_cycles=10000)`
```python
def run(self, instructions, max_cycles=10000):
    """
    Executa programa completo.
    
    Args:
        instructions (list[int]): Lista de instruções para executar
        max_cycles (int): Máximo de ciclos antes de timeout
        
    Returns:
        int: Número de ciclos executados
        
    Raises:
        RuntimeError: Se timeout for atingido
        
    Example:
        instructions = simulator.load_binary_file("program.txt")
        cycles = simulator.run(instructions)
        print(f"Programa terminou em {cycles} ciclos")
    """
```

#### `step()`
```python
def step(self):
    """
    Executa uma única instrução.
    
    Returns:
        bool: True se instrução foi executada, False se halted
        
    Example:
        while not simulator.halted:
            if not simulator.step():
                break
    """
```

#### `execute_instruction(instruction)`
```python
def execute_instruction(self, instruction):
    """
    Executa uma instrução específica.
    
    Args:
        instruction (int): Instrução de 32 bits para executar
        
    Returns:
        None
        
    Example:
        # Executar NOP (0x00000000)
        simulator.execute_instruction(0x00000000)
    """
```

### Métodos de Decodificação

#### `decode_instruction(instruction)`
```python
def decode_instruction(self, instruction):
    """
    Decodifica instrução em componentes.
    
    Args:
        instruction (int): Instrução de 32 bits
        
    Returns:
        dict: Dicionário com campos decodificados
            - opcode (int): Código da operação (bits 31-26)
            - rs (int): Registrador fonte (bits 25-21) 
            - rt (int): Registrador alvo (bits 20-16)
            - rd (int): Registrador destino (bits 15-11)
            - shamt (int): Shift amount (bits 10-6)
            - funct (int): Function code (bits 5-0)
            - immediate (int): Valor imediato (bits 15-0, com sinal)
            
    Example:
        decoded = simulator.decode_instruction(0x01000020)
        print(f"Opcode: {decoded['opcode']}")
        print(f"RS: {decoded['rs']}, RT: {decoded['rt']}")
    """
```

#### `format_instruction(instruction)`
```python
def format_instruction(self, instruction):
    """
    Formata instrução para exibição legível.
    
    Args:
        instruction (int): Instrução de 32 bits
        
    Returns:
        str: String formatada com mnemônico e operandos
        
    Example:
        formatted = simulator.format_instruction(0x01000020)
        print(formatted)  # "ADD R1, R2, R3"
    """
```

### Métodos de Memória

#### `load_word(address)`
```python
def load_word(self, address):
    """
    Carrega valor de 32 bits da memória.
    
    Args:
        address (int): Endereço de memória (0-255)
        
    Returns:
        int: Valor armazenado no endereço
        
    Raises:
        IndexError: Se endereço for inválido
        
    Example:
        value = simulator.load_word(100)
    """
```

#### `store_word(address, value)`
```python
def store_word(self, address, value):
    """
    Armazena valor de 32 bits na memória.
    
    Args:
        address (int): Endereço de memória (0-255)
        value (int): Valor a ser armazenado
        
    Returns:
        None
        
    Raises:
        IndexError: Se endereço for inválido
        
    Example:
        simulator.store_word(100, 42)
    """
```

### Métodos de Debug

#### `print_state()`
```python
def print_state(self):
    """
    Imprime estado atual do simulador.
    
    Exibe:
    - Program Counter (PC)
    - Registradores com valores não-zero
    - Posições de memória com valores não-zero
    - Estado de halt
    - Último valor de display
    
    Example:
        simulator.print_state()
    """
```

#### `get_register_state()`
```python
def get_register_state(self):
    """
    Retorna estado dos registradores.
    
    Returns:
        dict: Mapeamento registrador -> valor para registradores não-zero
        
    Example:
        regs = simulator.get_register_state()
        print(f"R1 = {regs.get(1, 0)}")
    """
```

#### `get_memory_state()`
```python
def get_memory_state(self):
    """
    Retorna estado da memória.
    
    Returns:
        dict: Mapeamento endereço -> valor para posições não-zero
        
    Example:
        mem = simulator.get_memory_state()
        for addr, value in mem.items():
            print(f"MEM[{addr}] = {value}")
    """
```

## 🔍 Classe: AssemblyErrorDetector

### Constructor

```python
class AssemblyErrorDetector:
    def __init__(self):
        """
        Inicializa detector de erros para código assembly.
        """
```

### Métodos de Análise

#### `analyze_gcd_execution(binary_file, a, b, expected_result)`
```python
def analyze_gcd_execution(self, binary_file, a, b, expected_result):
    """
    Analisa execução do algoritmo GCD.
    
    Args:
        binary_file (str): Arquivo com código binário
        a (int): Primeiro parâmetro para GCD
        b (int): Segundo parâmetro para GCD  
        expected_result (int): Resultado esperado
        
    Returns:
        dict: Relatório de análise com:
            - success (bool): Se resultado está correto
            - actual_result (int): Resultado obtido
            - cycles (int): Ciclos executados
            - errors (list): Lista de erros encontrados
            - execution_trace (list): Trace da execução
            
    Example:
        detector = AssemblyErrorDetector()
        report = detector.analyze_gcd_execution("gcd.txt", 4, 6, 2)
        if not report['success']:
            print("Erros encontrados:", report['errors'])
    """
```

#### `detect_parameter_issues(simulator, cycles_trace)`
```python
def detect_parameter_issues(self, simulator, cycles_trace):
    """
    Detecta problemas com passagem de parâmetros.
    
    Args:
        simulator (MIPSSimulator): Instância do simulador
        cycles_trace (list): Trace de execução
        
    Returns:
        list: Lista de problemas detectados
        
    Example:
        issues = detector.detect_parameter_issues(simulator, trace)
        for issue in issues:
            print(f"Problema: {issue}")
    """
```

## 📊 Constantes e Mapeamentos

### Opcodes Suportados

```python
OPCODES = {
    0x00: "NOP",     # No operation
    0x01: "ADD",     # Add
    0x02: "SUB",     # Subtract  
    0x03: "MUL",     # Multiply
    0x04: "DIV",     # Divide
    0x05: "MOD",     # Modulo
    0x06: "AND",     # Bitwise AND
    0x07: "OR",      # Bitwise OR
    0x08: "XOR",     # Bitwise XOR
    0x09: "NOT",     # Bitwise NOT
    0x0A: "SLL",     # Shift left logical
    0x0B: "SRL",     # Shift right logical
    0x0C: "SRA",     # Shift right arithmetic
    0x0D: "ADDI",    # Add immediate
    0x0E: "SLT",     # Set less than
    0x0F: "SLTI",    # Set less than immediate
    0x10: "LI",      # Load immediate
    0x11: "LUI",     # Load upper immediate
    0x12: "INPUT",   # Input operation
    0x13: "OUTPUT",  # Output operation
    0x14: "HALT",    # Halt execution
    0x15: "LW",      # Load word
    0x16: "SW",      # Store word
    0x17: "MOVE",    # Move register
    0x18: "BEQ",     # Branch if equal
    0x19: "BNE",     # Branch if not equal
    0x1A: "BLT",     # Branch if less than
    0x1B: "BLE",     # Branch if less or equal
    0x1C: "BGT",     # Branch if greater than
    0x1D: "BGE",     # Branch if greater or equal
    0x1E: "J",       # Jump
    0x1F: "JAL",     # Jump and link
    0x20: "JR",      # Jump register
    # ... (43 opcodes total)
}
```

### Registradores Especiais

| Registrador | Nome | Uso |
|-------------|------|-----|
| R0 | ZERO | Sempre zero |
| R1-R28 | General | Uso geral |
| R29 | SP | Stack Pointer |
| R30 | FP | Frame Pointer |
| R31 | RA | Return Address |

## 🛠️ Funções Utilitárias

### `to_signed_32bit(value)`
```python
def to_signed_32bit(value):
    """
    Converte valor para inteiro com sinal de 32 bits.
    
    Args:
        value (int): Valor a ser convertido
        
    Returns:
        int: Valor com sinal (-2^31 a 2^31-1)
        
    Example:
        signed = to_signed_32bit(0xFFFFFFFF)  # -1
    """
```

### `sign_extend_16_to_32(value)`
```python
def sign_extend_16_to_32(value):
    """
    Estende sinal de 16 para 32 bits.
    
    Args:
        value (int): Valor de 16 bits
        
    Returns:
        int: Valor estendido para 32 bits
        
    Example:
        extended = sign_extend_16_to_32(0xFFFF)  # -1
    """
```

## 🎯 Exemplos de Uso da API

### Exemplo 1: Execução Básica

```python
from simulator_mips import MIPSSimulator

# Criar simulador
simulator = MIPSSimulator(debug=True)
simulator.input_values = [10, 20]

# Carregar e executar programa
instructions = simulator.load_binary_file("program.txt")
cycles = simulator.run(instructions)

print(f"Resultado: {simulator.display}")
print(f"Ciclos: {cycles}")
```

### Exemplo 2: Execução Passo a Passo

```python
from simulator_mips import MIPSSimulator

simulator = MIPSSimulator()
instructions = simulator.load_binary_file("program.txt")

cycle = 0
while not simulator.halted and cycle < 100:
    print(f"Ciclo {cycle}: PC={simulator.pc}")
    
    if cycle < len(instructions):
        simulator.execute_instruction(instructions[simulator.pc])
    
    cycle += 1
    
    # Parar em condição específica
    if simulator.registers[1] == 42:
        print("Valor alvo atingido!")
        break
```

### Exemplo 3: Análise de Erros

```python
from detector_erros import AssemblyErrorDetector

detector = AssemblyErrorDetector()

# Analisar GCD
report = detector.analyze_gcd_execution("gcd.txt", 48, 18, 6)

if report['success']:
    print("✅ GCD funcionando corretamente")
else:
    print("❌ Problemas encontrados:")
    for error in report['errors']:
        print(f"  - {error}")
```

### Exemplo 4: Instrumentação Customizada

```python
from simulator_mips import MIPSSimulator

class InstrumentedSimulator(MIPSSimulator):
    def __init__(self):
        super().__init__()
        self.instruction_count = {}
        self.memory_accesses = 0
    
    def execute_instruction(self, instruction):
        # Contar instrução
        decoded = self.decode_instruction(instruction)
        opcode = decoded['opcode']
        mnemonic = self.opcodes.get(opcode, f"UNK_{opcode}")
        
        self.instruction_count[mnemonic] = \
            self.instruction_count.get(mnemonic, 0) + 1
        
        # Contar acessos à memória
        if opcode in [0x15, 0x16]:  # LW, SW
            self.memory_accesses += 1
        
        # Executar instrução original
        super().execute_instruction(instruction)
    
    def print_stats(self):
        print("📊 Estatísticas de Execução:")
        print(f"Acessos à memória: {self.memory_accesses}")
        print("Instruções mais usadas:")
        sorted_instrs = sorted(
            self.instruction_count.items(), 
            key=lambda x: x[1], 
            reverse=True
        )
        for instr, count in sorted_instrs[:5]:
            print(f"  {instr}: {count}")

# Uso
sim = InstrumentedSimulator()
sim.input_values = [4, 6]
instructions = sim.load_binary_file("gcd.txt")
sim.run(instructions)
sim.print_stats()
```

## ⚠️ Tratamento de Erros

### Exceções Comuns

| Exceção | Causa | Solução |
|---------|-------|---------|
| `FileNotFoundError` | Arquivo binário não encontrado | Verificar caminho do arquivo |
| `ValueError` | Formato binário inválido | Verificar formato das instruções |
| `IndexError` | Acesso inválido à memória | Verificar endereços (0-255) |
| `RuntimeError` | Timeout de execução | Aumentar max_cycles ou verificar loops |

### Exemplo de Tratamento

```python
try:
    simulator = MIPSSimulator()
    instructions = simulator.load_binary_file("program.txt")
    cycles = simulator.run(instructions, max_cycles=5000)
    
except FileNotFoundError:
    print("❌ Arquivo não encontrado")
except ValueError as e:
    print(f"❌ Formato inválido: {e}")
except RuntimeError as e:
    print(f"❌ Erro de execução: {e}")
except Exception as e:
    print(f"❌ Erro inesperado: {e}")
```

Esta documentação da API fornece todas as informações necessárias para usar o simulador MIPS programaticamente em seus próprios projetos.
