# Guia de Depuração - Simulador MIPS

## 🐛 Visão Geral

Este guia fornece estratégias e ferramentas para depurar programas MIPS usando o simulador. Inclui técnicas para identificar bugs comuns, analisar execução e validar assembladores.

## 🔍 Estratégias de Depuração

### 1. Debug Mode Básico

```python
from simulator_mips import MIPSSimulator

# Ativar modo debug
simulator = MIPSSimulator(debug=True)
simulator.input_values = [4, 6]

instructions = simulator.load_binary_file("binary_output.txt")
simulator.run(instructions)
```

**Output esperado:**
```
PC=  0: J          | 01110000000000000000000000011001
PC= 25: INPUT      | 01001000000000000000100000000000
PC= 26: SW         | 01010100100001000000000000000000
...
```

### 2. Execução Passo a Passo

```python
def step_by_step_debug(binary_file):
    simulator = MIPSSimulator(debug=True)
    simulator.input_values = [4, 6]
    
    instructions = simulator.load_binary_file(binary_file)
    
    cycle = 0
    while not simulator.halted and cycle < 100:
        # Estado antes da instrução
        pc_before = simulator.pc
        instruction = instructions[simulator.pc]
        decoded = simulator.decode_instruction(instruction)
        
        print(f"\n--- Ciclo {cycle} ---")
        print(f"PC: {pc_before}")
        print(f"Instrução: {simulator.opcodes[decoded['opcode']]}")
        print(f"Registradores importantes:")
        print(f"  R1={simulator.registers[1]}, R29={simulator.registers[29]}, R31={simulator.registers[31]}")
        
        # Executar instrução
        simulator.execute_instruction(instruction)
        
        # Estado depois
        print(f"PC após: {simulator.pc}")
        
        # Pausa para análise (opcional)
        input("Pressione Enter para próxima instrução...")
        
        cycle += 1
```

### 3. Breakpoints Condicionais

```python
def run_with_breakpoints(binary_file, breakpoint_conditions):
    """
    Executa com breakpoints baseados em condições
    
    breakpoint_conditions: lista de funções que retornam True para parar
    """
    simulator = MIPSSimulator()
    simulator.input_values = [4, 6]
    
    instructions = simulator.load_binary_file(binary_file)
    
    cycle = 0
    while not simulator.halted and cycle < 1000:
        # Verificar condições de breakpoint
        for i, condition in enumerate(breakpoint_conditions):
            if condition(simulator):
                print(f"\n🔴 BREAKPOINT {i} atingido!")
                print(f"PC: {simulator.pc}")
                print(f"Ciclo: {cycle}")
                print_simulator_state(simulator)
                input("Pressione Enter para continuar...")
        
        simulator.step()
        cycle += 1

# Exemplos de breakpoints
breakpoints = [
    lambda s: s.pc == 1,  # Entrada na função GCD
    lambda s: s.registers[1] == 0,  # Quando v = 0
    lambda s: s.pc == 34,  # Chamada JAL no main
]

run_with_breakpoints("binary_output.txt", breakpoints)
```

## 🚨 Problemas Comuns e Diagnóstico

### 1. Loop Infinito

**Sintomas:**
```
PC=  0: J          | 01110000000000000000000000011000
PC= 24: JR         | 00110001111100000000000000000000
PC=  0: J          | 01110000000000000000000000011000
PC= 24: JR         | 00110001111100000000000000000000
...
```

**Diagnóstico:**
```python
def detect_infinite_loop(simulator, instructions, max_cycles=100):
    pc_history = []
    
    for cycle in range(max_cycles):
        pc_history.append(simulator.pc)
        
        # Detectar padrão repetitivo
        if len(pc_history) > 10:
            recent = pc_history[-10:]
            if len(set(recent)) <= 3:
                print("🚨 LOOP INFINITO DETECTADO!")
                print(f"PCs repetitivos: {set(recent)}")
                return True
        
        if simulator.halted:
            break
            
        simulator.step()
    
    return False
```

**Causas comuns:**
- Jump para endereço incorreto
- Condição de parada nunca satisfeita
- RA (R31) não inicializado corretamente

### 2. Parâmetros Incorretos

**Sintomas:**
```
# Esperado: GCD(4,6) = 2
# Obtido: GCD(4,6) = 0
```

**Diagnóstico:**
```python
def trace_parameter_passing():
    simulator = MIPSSimulator(debug=True)
    simulator.input_values = [4, 6]
    
    instructions = simulator.load_binary_file("binary_output.txt")
    
    print("=== RASTREAMENTO DE PARÂMETROS ===")
    
    while not simulator.halted:
        pc = simulator.pc
        instruction = instructions[pc]
        decoded = simulator.decode_instruction(instruction)
        opcode = decoded['opcode']
        
        # Monitorar operações de pilha
        if opcode == 0x16:  # SW
            addr = (simulator.registers[decoded['rs']] + decoded['immediate']) & 0xFF
            val = simulator.registers[decoded['rt']]
            print(f"PC={pc}: SW R{decoded['rt']} -> MEM[{addr}] = {val}")
            
        elif opcode == 0x15:  # LW
            addr = (simulator.registers[decoded['rs']] + decoded['immediate']) & 0xFF
            print(f"PC={pc}: LW R{decoded['rt']} <- MEM[{addr}] = {simulator.memory[addr]}")
            
        elif opcode == 0x1F:  # JAL
            print(f"PC={pc}: JAL - Chamando função, RA={simulator.registers[31]}")
            
        simulator.execute_instruction(instruction)
```

### 3. Endereços de Memória Incorretos

**Diagnóstico:**
```python
def validate_memory_access():
    simulator = MIPSSimulator()
    
    # Instrumentar acessos à memória
    original_load = simulator.load_word
    original_store = simulator.store_word
    
    def instrumented_load(address):
        print(f"📖 LOAD: MEM[{address}] = {simulator.memory[address]}")
        if address >= 256:
            print(f"🚨 ERRO: Acesso inválido à memória: {address}")
        return original_load(address)
    
    def instrumented_store(address, value):
        print(f"📝 STORE: MEM[{address}] = {value}")
        if address >= 256:
            print(f"🚨 ERRO: Escrita inválida na memória: {address}")
        return original_store(address, value)
    
    simulator.load_word = instrumented_load
    simulator.store_word = instrumented_store
    
    return simulator
```

## 🔧 Ferramentas de Análise

### 1. Rastreamento de Registradores

```python
def trace_register_changes(register_list):
    """Rastrea mudanças em registradores específicos"""
    simulator = MIPSSimulator()
    
    # Estado inicial
    prev_state = {r: simulator.registers[r] for r in register_list}
    
    def check_changes():
        for r in register_list:
            current = simulator.registers[r]
            if current != prev_state[r]:
                print(f"R{r}: {prev_state[r]} -> {current}")
                prev_state[r] = current
    
    # Hook na execução
    original_step = simulator.step
    def instrumented_step():
        result = original_step()
        check_changes()
        return result
    
    simulator.step = instrumented_step
    return simulator

# Exemplo de uso
simulator = trace_register_changes([1, 2, 3, 29, 31])
```

### 2. Análise de Fluxo de Controle

```python
def analyze_control_flow():
    simulator = MIPSSimulator(debug=True)
    simulator.input_values = [4, 6]
    
    instructions = simulator.load_binary_file("binary_output.txt")
    
    control_flow = []
    
    while not simulator.halted:
        pc = simulator.pc
        instruction = instructions[pc]
        decoded = simulator.decode_instruction(instruction)
        opcode = decoded['opcode']
        
        # Detectar instruções de controle
        if opcode in [0x1E, 0x1F, 0x20]:  # J, JAL, JR
            mnemonic = simulator.opcodes[opcode]
            if opcode == 0x1E:  # J
                target = decoded['immediate']
                control_flow.append(f"PC={pc}: {mnemonic} {target}")
            elif opcode == 0x1F:  # JAL
                target = decoded['immediate']
                control_flow.append(f"PC={pc}: {mnemonic} {target} (RA será {pc+1})")
            elif opcode == 0x20:  # JR
                target = simulator.registers[decoded['rs']]
                control_flow.append(f"PC={pc}: {mnemonic} R{decoded['rs']} (={target})")
        
        # Detectar branches
        elif opcode in range(0x18, 0x1E):  # BEQ, BNE, etc.
            mnemonic = simulator.opcodes[opcode]
            rs_val = simulator.registers[decoded['rs']]
            rt_val = simulator.registers[decoded['rt']]
            target = decoded['immediate']
            
            # Prever se branch será tomado
            will_branch = False
            if opcode == 0x18 and rs_val == rt_val:  # BEQ
                will_branch = True
            elif opcode == 0x19 and rs_val != rt_val:  # BNE
                will_branch = True
            # ... outras condições
            
            status = "TOMADO" if will_branch else "NÃO TOMADO"
            control_flow.append(f"PC={pc}: {mnemonic} R{decoded['rs']}({rs_val}), R{decoded['rt']}({rt_val}), {target} - {status}")
        
        simulator.execute_instruction(instruction)
    
    print("\n=== FLUXO DE CONTROLE ===")
    for entry in control_flow:
        print(entry)
```

### 3. Profiler de Performance

```python
class MIPSProfiler:
    def __init__(self):
        self.instruction_counts = {}
        self.function_calls = {}
        self.memory_accesses = 0
    
    def profile_execution(self, binary_file):
        simulator = MIPSSimulator()
        simulator.input_values = [4, 6]
        
        instructions = simulator.load_binary_file(binary_file)
        
        cycle = 0
        while not simulator.halted and cycle < 1000:
            pc = simulator.pc
            instruction = instructions[pc]
            decoded = simulator.decode_instruction(instruction)
            opcode = decoded['opcode']
            mnemonic = simulator.opcodes[opcode]
            
            # Contar instruções
            self.instruction_counts[mnemonic] = self.instruction_counts.get(mnemonic, 0) + 1
            
            # Contar acessos à memória
            if opcode in [0x15, 0x16]:  # LW, SW
                self.memory_accesses += 1
            
            # Rastrear chamadas de função
            if opcode == 0x1F:  # JAL
                target = decoded['immediate']
                self.function_calls[target] = self.function_calls.get(target, 0) + 1
            
            simulator.execute_instruction(instruction)
            cycle += 1
        
        return cycle
    
    def print_report(self, total_cycles):
        print("\n=== RELATÓRIO DE PERFORMANCE ===")
        print(f"Total de ciclos: {total_cycles}")
        print(f"Acessos à memória: {self.memory_accesses}")
        
        print("\nInstruções mais usadas:")
        sorted_instructions = sorted(self.instruction_counts.items(), key=lambda x: x[1], reverse=True)
        for instr, count in sorted_instructions[:10]:
            percentage = (count / total_cycles) * 100
            print(f"  {instr:10s}: {count:4d} ({percentage:.1f}%)")
        
        print("\nChamadas de função:")
        for addr, count in self.function_calls.items():
            print(f"  Endereço {addr}: {count} chamadas")

# Uso
profiler = MIPSProfiler()
cycles = profiler.profile_execution("binary_output.txt")
profiler.print_report(cycles)
```

## 🎯 Casos Específicos de Debug

### Debugging GCD Algorithm

```python
def debug_gcd_algorithm():
    """Debug específico para algoritmo GCD"""
    simulator = MIPSSimulator(debug=True)
    simulator.input_values = [4, 6]
    
    instructions = simulator.load_binary_file("binary_output.txt")
    
    gcd_calls = []
    
    while not simulator.halted:
        pc = simulator.pc
        
        # Detectar entrada na função GCD (PC=1)
        if pc == 1:
            # Capturar parâmetros
            u = simulator.memory[0] if simulator.memory[0] != 0 else "não definido"
            v = simulator.memory[1] if simulator.memory[1] != 0 else "não definido"
            gcd_calls.append((u, v))
            print(f"🔄 GCD({u}, {v}) chamado")
        
        # Detectar retorno da função
        elif pc == 23:  # JR R31
            result = simulator.registers[1]
            print(f"↩️  GCD retornando: {result}")
        
        simulator.step()
    
    print(f"\n📊 Total de chamadas GCD: {len(gcd_calls)}")
    for i, (u, v) in enumerate(gcd_calls):
        print(f"  {i+1}. GCD({u}, {v})")
```

### Validação de Assemblador

```python
def validate_assembler_correctness():
    """Valida se o assemblador gera código correto"""
    
    test_cases = [
        ([4, 6], 2),
        ([12, 8], 4),
        ([17, 13], 1),
        ([100, 25], 25)
    ]
    
    errors = []
    
    for inputs, expected in test_cases:
        simulator = MIPSSimulator()
        simulator.input_values = inputs
        
        instructions = simulator.load_binary_file("binary_output.txt")
        cycles = simulator.run(instructions, max_cycles=1000)
        
        result = simulator.display
        
        if result != expected:
            error = {
                'inputs': inputs,
                'expected': expected,
                'actual': result,
                'cycles': cycles,
                'halted': simulator.halted
            }
            errors.append(error)
    
    if errors:
        print("🚨 ERROS ENCONTRADOS NO ASSEMBLADOR:")
        for error in errors:
            print(f"  GCD{error['inputs']}: esperado {error['expected']}, obtido {error['actual']}")
            if not error['halted']:
                print(f"    ⚠️  Programa não terminou (timeout após {error['cycles']} ciclos)")
    else:
        print("✅ Assemblador funcionando corretamente!")
    
    return len(errors) == 0
```

## 📝 Checklist de Debug

### ✅ Verificações Básicas
- [ ] Programa carrega sem erros
- [ ] Primeira instrução é jump para main
- [ ] INPUT funciona corretamente
- [ ] OUTPUT/HALT executam
- [ ] Não há loops infinitos

### ✅ Verificações de Função
- [ ] Parâmetros são passados corretamente
- [ ] Return address (RA) é salvo/restaurado
- [ ] Valores de retorno estão corretos
- [ ] Pilha é gerenciada adequadamente

### ✅ Verificações de Memória
- [ ] Endereços de memória são válidos (0-255)
- [ ] Não há sobreposição de dados
- [ ] Stack pointer (SP) é inicializado
- [ ] Acessos à memória são consistentes

### ✅ Verificações de Performance
- [ ] Número de ciclos é razoável
- [ ] Não há instruções desnecessárias
- [ ] Recursão termina corretamente
- [ ] Uso de registradores é eficiente

Este guia fornece uma base sólida para depurar qualquer programa MIPS usando o simulador.
