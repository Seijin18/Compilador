# Guia de Uso - Simulador MIPS

## 🚀 Início Rápido

### Instalação
Não há necessidade de instalação. Apenas certifique-se de ter Python 3.6+ instalado.

### Uso Básico

#### 1. Simulação Simples
```bash
python simulator_mips.py binary_output.txt
```

#### 2. Modo Debug
```python
from simulator_mips import MIPSSimulator

simulator = MIPSSimulator(debug=True)
instructions = simulator.load_binary_file("arquivo.txt")
simulator.run(instructions)
```

#### 3. Execução Controlada
```python
simulator = MIPSSimulator()
simulator.input_values = [4, 6]  # Valores de entrada

# Execução passo a passo
cycle = 0
while not simulator.halted and cycle < 1000:
    instruction = instructions[simulator.pc]
    simulator.execute_instruction(instruction)
    cycle += 1
    
print(f"Resultado: {simulator.display}")
```

## 📊 Análise de Resultados

### Estado do Processador
```python
# Verificar registradores
print(f"R1 = {simulator.registers[1]}")
print(f"SP = {simulator.registers[29]}")
print(f"RA = {simulator.registers[31]}")

# Verificar memória
for addr in range(256):
    if simulator.memory[addr] != 0:
        print(f"MEM[{addr}] = {simulator.memory[addr]}")
```

### Rastreamento de Execução
```python
# Habilitar debug detalhado
simulator.debug = True

# Ver cada instrução executada
while not simulator.halted:
    pc_before = simulator.pc
    instruction = instructions[simulator.pc]
    decoded = simulator.decode_instruction(instruction)
    
    print(f"PC={pc_before}: {simulator.opcodes[decoded['opcode']]}")
    simulator.execute_instruction(instruction)
```

## 🛠️ Casos de Uso Avançados

### 1. Teste de Assemblador

```python
def test_assembler_output(binary_file):
    """Testa se o assemblador gera código correto"""
    simulator = MIPSSimulator(debug=True)
    simulator.input_values = [4, 6]
    
    instructions = simulator.load_binary_file(binary_file)
    simulator.run(instructions, max_cycles=1000)
    
    # Verificar resultado esperado
    expected = 2  # GCD(4,6) = 2
    actual = simulator.display
    
    if actual == expected:
        print("✅ Assemblador funcionando corretamente")
        return True
    else:
        print(f"❌ Erro: esperado {expected}, obtido {actual}")
        return False
```

### 2. Detecção de Bugs

```python
from detector_erros import AssemblyErrorDetector

def find_assembler_bugs():
    """Detecta bugs específicos no assemblador"""
    detector = AssemblyErrorDetector()
    
    # Analisa o código assembly gerado
    simulator = MIPSSimulator(debug=True)
    simulator.input_values = [4, 6]
    
    instructions = simulator.load_binary_file("binary_output.txt")
    
    # Executa com análise
    detector.analyze_gcd_calls(simulator, instructions)
    
    # Relatório de bugs encontrados
    detector.print_report()
```

### 3. Benchmark de Performance

```python
def benchmark_code(binary_file, inputs_list):
    """Faz benchmark do código com diferentes entradas"""
    results = []
    
    for inputs in inputs_list:
        simulator = MIPSSimulator()
        simulator.input_values = inputs
        
        instructions = simulator.load_binary_file(binary_file)
        
        start_time = time.time()
        cycles = simulator.run(instructions, max_cycles=10000)
        end_time = time.time()
        
        results.append({
            'inputs': inputs,
            'output': simulator.display,
            'cycles': cycles,
            'time': end_time - start_time
        })
    
    return results

# Exemplo de uso
test_cases = [(4, 6), (12, 8), (100, 25), (17, 13)]
results = benchmark_code("binary_output.txt", test_cases)

for result in results:
    print(f"GCD{result['inputs']} = {result['output']} ({result['cycles']} ciclos)")
```

## 🔧 Configurações Avançadas

### Modificação de Memória
```python
# Inicializar memória com valores específicos
simulator.memory[0] = 10
simulator.memory[1] = 20

# Verificar overflow de memória
if any(simulator.memory[i] != 0 for i in range(100, 256)):
    print("⚠️ Uso de memória fora do esperado")
```

### Customização de INPUT
```python
# INPUT interativo
class InteractiveSimulator(MIPSSimulator):
    def execute_input(self, rd):
        value = int(input(f"Digite valor para R{rd}: "))
        self.registers[rd] = value
        
# INPUT de arquivo
def load_inputs_from_file(filename):
    with open(filename, 'r') as f:
        return [int(line.strip()) for line in f]

simulator.input_values = load_inputs_from_file("inputs.txt")
```

### Debugging Condicional
```python
def debug_on_condition(simulator, condition_func):
    """Ativa debug apenas quando condição é atendida"""
    original_debug = simulator.debug
    
    while not simulator.halted:
        if condition_func(simulator):
            simulator.debug = True
            print("🔍 Debug ativado!")
        else:
            simulator.debug = False
            
        simulator.step()
    
    simulator.debug = original_debug

# Exemplo: debug apenas quando PC está em função específica
debug_on_condition(simulator, lambda s: 1 <= s.pc <= 23)  # Dentro da função GCD
```

## 📝 Exemplos Práticos

### Validação de Resultado
```python
def validate_gcd_program():
    test_cases = [
        ((4, 6), 2),
        ((12, 8), 4),
        ((17, 13), 1),
        ((100, 25), 25)
    ]
    
    for (a, b), expected in test_cases:
        simulator = MIPSSimulator()
        simulator.input_values = [a, b]
        
        instructions = simulator.load_binary_file("binary_output.txt")
        simulator.run(instructions)
        
        result = simulator.display
        status = "✅" if result == expected else "❌"
        print(f"{status} GCD({a},{b}) = {result} (esperado: {expected})")
```

### Análise de Pilha
```python
def analyze_stack_usage():
    """Analisa o uso da pilha durante execução"""
    simulator = MIPSSimulator(debug=True)
    simulator.input_values = [4, 6]
    
    instructions = simulator.load_binary_file("binary_output.txt")
    
    max_stack_depth = 0
    stack_base = simulator.registers[29]  # SP inicial
    
    while not simulator.halted:
        current_sp = simulator.registers[29]
        stack_depth = stack_base - current_sp
        max_stack_depth = max(max_stack_depth, stack_depth)
        
        simulator.step()
    
    print(f"Profundidade máxima da pilha: {max_stack_depth} palavras")
```

## 🚨 Tratamento de Erros

### Detecção de Loop Infinito
```python
def run_with_timeout(simulator, instructions, max_cycles=10000):
    """Executa com proteção contra loop infinito"""
    cycle = 0
    pc_history = []
    
    while not simulator.halted and cycle < max_cycles:
        pc_history.append(simulator.pc)
        
        # Detectar padrão de loop
        if len(pc_history) > 10:
            recent = pc_history[-10:]
            if len(set(recent)) <= 3:  # Poucas instruções únicas
                print("⚠️ Possível loop infinito detectado!")
                break
        
        simulator.step()
        cycle += 1
    
    if cycle >= max_cycles:
        print("🚫 Execução interrompida por timeout")
    
    return cycle
```

### Validação de Memória
```python
def validate_memory_access():
    """Valida acessos à memória"""
    simulator = MIPSSimulator()
    
    # Sobrescrever métodos de acesso à memória
    original_load = simulator.load_word
    original_store = simulator.store_word
    
    def safe_load(address):
        if address >= 256:
            raise ValueError(f"Acesso inválido à memória: {address}")
        return original_load(address)
    
    def safe_store(address, value):
        if address >= 256:
            raise ValueError(f"Escrita inválida na memória: {address}")
        return original_store(address, value)
    
    simulator.load_word = safe_load
    simulator.store_word = safe_store
```

---

Este guia fornece uma base sólida para usar o simulador MIPS em diferentes cenários, desde validação básica até análise avançada de performance e detecção de bugs.
