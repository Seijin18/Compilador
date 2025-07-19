# Exemplos Avançados - Simulador MIPS

## 🎯 Visão Geral

Esta seção apresenta exemplos avançados de uso do simulador MIPS, incluindo cenários complexos de debug, análise de performance e validação de compiladores.

## 🧪 Exemplo 1: Algoritmo de Fibonacci

### fibonacci.c
```c
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n;
    input(n);
    int result = fibonacci(n);
    output(result);
    return 0;
}
```

### Simulação e Análise

```python
from simulator_mips import MIPSSimulator

def analyze_fibonacci_recursion():
    """Analisa o comportamento recursivo do Fibonacci"""
    
    # Configurar simulador com trace de chamadas
    simulator = MIPSSimulator(debug=True)
    simulator.input_values = [5]  # Fibonacci(5) = 5
    
    # Carregar instruções
    instructions = simulator.load_binary_file("fibonacci_binary.txt")
    
    # Rastrear chamadas recursivas
    call_stack = []
    recursion_depth = 0
    max_depth = 0
    
    cycle = 0
    while not simulator.halted and cycle < 10000:
        pc = simulator.pc
        instruction = instructions[pc]
        decoded = simulator.decode_instruction(instruction)
        
        # Detectar chamada JAL para fibonacci
        if decoded['opcode'] == 0x1F and decoded['immediate'] == 1:  # JAL fibonacci
            n_value = simulator.registers[1]  # Parâmetro n
            call_stack.append(n_value)
            recursion_depth += 1
            max_depth = max(max_depth, recursion_depth)
            print(f"{'  ' * (recursion_depth-1)}→ fibonacci({n_value})")
        
        # Detectar retorno JR R31
        elif decoded['opcode'] == 0x20 and decoded['rs'] == 31:  # JR R31
            if call_stack:
                n_value = call_stack.pop()
                result = simulator.registers[1]
                print(f"{'  ' * (recursion_depth-1)}← fibonacci({n_value}) = {result}")
                recursion_depth -= 1
        
        simulator.execute_instruction(instruction)
        cycle += 1
    
    print(f"\n📊 Estatísticas:")
    print(f"Profundidade máxima: {max_depth}")
    print(f"Total de ciclos: {cycle}")
    print(f"Resultado final: {simulator.display}")

# Executar análise
analyze_fibonacci_recursion()
```

**Output esperado:**
```
→ fibonacci(5)
  → fibonacci(4)
    → fibonacci(3)
      → fibonacci(2)
        → fibonacci(1)
        ← fibonacci(1) = 1
        → fibonacci(0)
        ← fibonacci(0) = 0
      ← fibonacci(2) = 1
      → fibonacci(1)
      ← fibonacci(1) = 1
    ← fibonacci(3) = 2
    → fibonacci(2)
      → fibonacci(1)
      ← fibonacci(1) = 1
      → fibonacci(0)
      ← fibonacci(0) = 0
    ← fibonacci(2) = 1
  ← fibonacci(4) = 3
  → fibonacci(3)
    → fibonacci(2)
      → fibonacci(1)
      ← fibonacci(1) = 1
      → fibonacci(0)
      ← fibonacci(0) = 0
    ← fibonacci(2) = 1
    → fibonacci(1)
    ← fibonacci(1) = 1
  ← fibonacci(3) = 2
← fibonacci(5) = 5
```

## 🔀 Exemplo 2: Algoritmo de Ordenação (Bubble Sort)

### bubble_sort.c
```c
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[5] = {64, 34, 25, 12, 22};
    bubble_sort(arr, 5);
    
    for (int i = 0; i < 5; i++) {
        output(arr[i]);
    }
    return 0;
}
```

### Análise de Performance

```python
def analyze_sorting_performance():
    """Analisa performance do bubble sort"""
    
    class SortingProfiler:
        def __init__(self):
            self.comparisons = 0
            self.swaps = 0
            self.memory_writes = 0
            self.loop_iterations = 0
        
        def profile_bubble_sort(self, binary_file):
            simulator = MIPSSimulator()
            instructions = simulator.load_binary_file(binary_file)
            
            cycle = 0
            in_comparison = False
            
            while not simulator.halted and cycle < 50000:
                pc = simulator.pc
                instruction = instructions[pc]
                decoded = simulator.decode_instruction(instruction)
                opcode = decoded['opcode']
                
                # Detectar comparações (instruções SLT)
                if opcode == 0x0E:  # SLT
                    self.comparisons += 1
                
                # Detectar escritas na memória (SW)
                elif opcode == 0x16:  # SW
                    self.memory_writes += 1
                    # Heurística: duas escritas consecutivas = uma troca
                    if cycle > 0 and instructions[pc-1] and \
                       simulator.decode_instruction(instructions[pc-1])['opcode'] == 0x16:
                        self.swaps += 1
                
                # Detectar voltas de loop (branches para endereços menores)
                elif opcode in [0x18, 0x19] and decoded['immediate'] < pc:  # BEQ, BNE
                    self.loop_iterations += 1
                
                simulator.execute_instruction(instruction)
                cycle += 1
            
            return cycle
        
        def print_report(self, total_cycles):
            print("\n=== RELATÓRIO DE PERFORMANCE - BUBBLE SORT ===")
            print(f"Total de ciclos: {total_cycles}")
            print(f"Comparações: {self.comparisons}")
            print(f"Trocas: {self.swaps}")
            print(f"Escritas na memória: {self.memory_writes}")
            print(f"Iterações de loop: {self.loop_iterations}")
            print(f"Ciclos por comparação: {total_cycles / max(1, self.comparisons):.2f}")
    
    # Executar profiling
    profiler = SortingProfiler()
    cycles = profiler.profile_bubble_sort("bubble_sort_binary.txt")
    profiler.print_report(cycles)

# Executar análise
analyze_sorting_performance()
```

## 🌳 Exemplo 3: Busca em Árvore Binária

### binary_tree.c
```c
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
```

### Análise de Estruturas de Dados

```python
def analyze_tree_traversal():
    """Analisa navegação em árvore binária"""
    
    class TreeAnalyzer:
        def __init__(self):
            self.nodes_visited = []
            self.comparisons = 0
            self.null_checks = 0
            self.recursion_depth = 0
            self.max_depth = 0
        
        def trace_tree_search(self, binary_file, search_key):
            simulator = MIPSSimulator(debug=True)
            simulator.input_values = [search_key]
            
            instructions = simulator.load_binary_file(binary_file)
            
            while not simulator.halted:
                pc = simulator.pc
                instruction = instructions[pc]
                decoded = simulator.decode_instruction(instruction)
                
                # Detectar entrada na função search
                if pc == 10:  # Endereço da função search
                    node_addr = simulator.registers[1]  # Parâmetro root
                    key = simulator.registers[2]        # Parâmetro key
                    
                    if node_addr == 0:
                        self.null_checks += 1
                        print(f"{'  ' * self.recursion_depth}Null node check")
                    else:
                        node_data = simulator.memory[node_addr]  # root->data
                        self.nodes_visited.append(node_data)
                        self.recursion_depth += 1
                        self.max_depth = max(self.max_depth, self.recursion_depth)
                        
                        print(f"{'  ' * (self.recursion_depth-1)}Visiting node: {node_data}")
                        
                        # Prever direção da busca
                        if key < node_data:
                            print(f"{'  ' * self.recursion_depth}→ Going left")
                        elif key > node_data:
                            print(f"{'  ' * self.recursion_depth}→ Going right")
                        else:
                            print(f"{'  ' * self.recursion_depth}✓ Found target!")
                
                # Detectar comparações
                elif decoded['opcode'] in [0x0E, 0x18, 0x19]:  # SLT, BEQ, BNE
                    self.comparisons += 1
                
                # Detectar retorno
                elif decoded['opcode'] == 0x20 and decoded['rs'] == 31:  # JR R31
                    if self.recursion_depth > 0:
                        self.recursion_depth -= 1
                        result = simulator.registers[1]
                        status = "Found" if result != 0 else "Not found"
                        print(f"{'  ' * self.recursion_depth}← Returning: {status}")
                
                simulator.execute_instruction(instruction)
        
        def print_analysis(self):
            print(f"\n📊 ANÁLISE DA BUSCA:")
            print(f"Nós visitados: {self.nodes_visited}")
            print(f"Profundidade máxima: {self.max_depth}")
            print(f"Total de comparações: {self.comparisons}")
            print(f"Verificações de null: {self.null_checks}")
            print(f"Caminho percorrido: {' → '.join(map(str, self.nodes_visited))}")
    
    # Executar análise
    analyzer = TreeAnalyzer()
    analyzer.trace_tree_search("tree_search_binary.txt", 7)
    analyzer.print_analysis()

# Executar análise
analyze_tree_traversal()
```

## 🎮 Exemplo 4: Sistema de Benchmark

### benchmark_suite.py
```python
class MIPSBenchmarkSuite:
    def __init__(self):
        self.benchmarks = {}
    
    def add_benchmark(self, name, binary_file, inputs, expected_output):
        """Adiciona um benchmark à suíte"""
        self.benchmarks[name] = {
            'binary_file': binary_file,
            'inputs': inputs,
            'expected_output': expected_output
        }
    
    def run_benchmark(self, name, iterations=1):
        """Executa um benchmark específico"""
        if name not in self.benchmarks:
            raise ValueError(f"Benchmark '{name}' não encontrado")
        
        benchmark = self.benchmarks[name]
        results = []
        
        for i in range(iterations):
            simulator = MIPSSimulator()
            simulator.input_values = benchmark['inputs']
            
            instructions = simulator.load_binary_file(benchmark['binary_file'])
            
            start_time = time.time()
            cycles = simulator.run(instructions, max_cycles=100000)
            end_time = time.time()
            
            result = {
                'iteration': i + 1,
                'cycles': cycles,
                'output': simulator.display,
                'halted': simulator.halted,
                'execution_time': end_time - start_time,
                'correct': simulator.display == benchmark['expected_output']
            }
            
            results.append(result)
        
        return results
    
    def run_all_benchmarks(self):
        """Executa todos os benchmarks"""
        overall_results = {}
        
        for name in self.benchmarks:
            print(f"\n🏃 Executando benchmark: {name}")
            results = self.run_benchmark(name, iterations=3)
            overall_results[name] = results
            
            # Estatísticas
            cycles = [r['cycles'] for r in results]
            times = [r['execution_time'] for r in results]
            correct = all(r['correct'] for r in results)
            
            print(f"  ✓ Correto: {'Sim' if correct else 'Não'}")
            print(f"  📊 Ciclos: {min(cycles)}-{max(cycles)} (média: {sum(cycles)/len(cycles):.1f})")
            print(f"  ⏱️  Tempo: {min(times)*1000:.2f}-{max(times)*1000:.2f}ms")
        
        return overall_results
    
    def compare_implementations(self, impl1, impl2):
        """Compara duas implementações"""
        results1 = self.run_benchmark(impl1, iterations=5)
        results2 = self.run_benchmark(impl2, iterations=5)
        
        cycles1 = [r['cycles'] for r in results1]
        cycles2 = [r['cycles'] for r in results2]
        
        avg_cycles1 = sum(cycles1) / len(cycles1)
        avg_cycles2 = sum(cycles2) / len(cycles2)
        
        print(f"\n⚖️  COMPARAÇÃO: {impl1} vs {impl2}")
        print(f"{impl1}: {avg_cycles1:.1f} ciclos (média)")
        print(f"{impl2}: {avg_cycles2:.1f} ciclos (média)")
        
        if avg_cycles1 < avg_cycles2:
            improvement = (avg_cycles2 - avg_cycles1) / avg_cycles2 * 100
            print(f"🏆 {impl1} é {improvement:.1f}% mais eficiente")
        else:
            improvement = (avg_cycles1 - avg_cycles2) / avg_cycles1 * 100
            print(f"🏆 {impl2} é {improvement:.1f}% mais eficiente")

# Exemplo de uso
import time

def setup_benchmark_suite():
    suite = MIPSBenchmarkSuite()
    
    # Adicionar benchmarks
    suite.add_benchmark(
        "GCD", 
        "gcd_binary.txt", 
        [48, 18], 
        6
    )
    
    suite.add_benchmark(
        "Fibonacci", 
        "fibonacci_binary.txt", 
        [8], 
        21
    )
    
    suite.add_benchmark(
        "Factorial", 
        "factorial_binary.txt", 
        [5], 
        120
    )
    
    suite.add_benchmark(
        "Prime Check", 
        "prime_binary.txt", 
        [17], 
        1  # 1 = é primo
    )
    
    return suite

# Executar suíte completa
suite = setup_benchmark_suite()
results = suite.run_all_benchmarks()

# Comparar implementações (se disponível)
# suite.compare_implementations("GCD", "GCD_Optimized")
```

## 🐛 Exemplo 5: Detector Automático de Bugs

### auto_bug_detector.py
```python
class AutoBugDetector:
    def __init__(self):
        self.bugs_found = []
    
    def detect_infinite_loops(self, simulator, max_cycles=1000):
        """Detecta loops infinitos"""
        pc_history = []
        
        for cycle in range(max_cycles):
            pc_history.append(simulator.pc)
            
            # Procurar padrões repetitivos
            if len(pc_history) >= 20:
                recent = pc_history[-20:]
                unique_pcs = set(recent)
                
                if len(unique_pcs) <= 3:
                    self.bugs_found.append({
                        'type': 'INFINITE_LOOP',
                        'cycle': cycle,
                        'pattern': list(unique_pcs),
                        'description': f'Loop infinito detectado entre PCs {unique_pcs}'
                    })
                    return True
            
            if simulator.halted:
                break
                
            simulator.step()
        
        return False
    
    def detect_stack_overflow(self, simulator):
        """Detecta overflow de pilha"""
        sp = simulator.registers[29]  # Stack Pointer
        
        if sp < 200:  # Limite arbitrário para stack
            self.bugs_found.append({
                'type': 'STACK_OVERFLOW',
                'sp_value': sp,
                'description': f'Stack overflow: SP = {sp} (muito baixo)'
            })
            return True
        
        return False
    
    def detect_uninitialized_memory(self, simulator):
        """Detecta acessos à memória não inicializada"""
        # Monitora acessos LW a endereços que nunca foram escritos
        written_addresses = set()
        
        # Hook para SW
        original_store = simulator.store_word
        def tracked_store(addr, value):
            written_addresses.add(addr)
            return original_store(addr, value)
        
        # Hook para LW
        original_load = simulator.load_word
        def tracked_load(addr):
            if addr not in written_addresses and simulator.memory[addr] == 0:
                self.bugs_found.append({
                    'type': 'UNINITIALIZED_MEMORY',
                    'address': addr,
                    'description': f'Leitura de memória não inicializada: {addr}'
                })
            return original_load(addr)
        
        simulator.store_word = tracked_store
        simulator.load_word = tracked_load
    
    def detect_invalid_jumps(self, simulator, instructions):
        """Detecta jumps para endereços inválidos"""
        pc = simulator.pc
        
        if pc >= len(instructions) or pc < 0:
            self.bugs_found.append({
                'type': 'INVALID_JUMP',
                'pc': pc,
                'max_pc': len(instructions) - 1,
                'description': f'Jump para PC inválido: {pc}'
            })
            return True
        
        return False
    
    def analyze_program(self, binary_file, inputs):
        """Análise completa de bugs"""
        simulator = MIPSSimulator()
        simulator.input_values = inputs
        
        instructions = simulator.load_binary_file(binary_file)
        
        # Configurar detecções
        self.detect_uninitialized_memory(simulator)
        
        # Executar com verificações
        cycle = 0
        max_cycles = 10000
        
        while not simulator.halted and cycle < max_cycles:
            # Verificar condições de bug
            if self.detect_invalid_jumps(simulator, instructions):
                break
            
            if self.detect_stack_overflow(simulator):
                break
            
            # Verificar loop infinito a cada 100 ciclos
            if cycle % 100 == 0 and cycle > 0:
                if self.detect_infinite_loops(simulator, 100):
                    break
            
            simulator.step()
            cycle += 1
        
        # Verificar se programa não terminou
        if cycle >= max_cycles and not simulator.halted:
            self.bugs_found.append({
                'type': 'TIMEOUT',
                'cycles': cycle,
                'description': f'Programa não terminou após {cycle} ciclos'
            })
        
        return self.bugs_found
    
    def print_bug_report(self):
        """Imprime relatório de bugs"""
        if not self.bugs_found:
            print("✅ Nenhum bug detectado!")
            return
        
        print(f"🚨 {len(self.bugs_found)} bug(s) encontrado(s):")
        
        for i, bug in enumerate(self.bugs_found, 1):
            print(f"\n{i}. {bug['type']}")
            print(f"   Descrição: {bug['description']}")
            
            # Informações específicas por tipo
            if bug['type'] == 'INFINITE_LOOP':
                print(f"   Ciclo: {bug['cycle']}")
                print(f"   Padrão: {bug['pattern']}")
            elif bug['type'] == 'STACK_OVERFLOW':
                print(f"   SP: {bug['sp_value']}")
            elif bug['type'] == 'UNINITIALIZED_MEMORY':
                print(f"   Endereço: {bug['address']}")

# Uso do detector
detector = AutoBugDetector()
bugs = detector.analyze_program("problematic_binary.txt", [4, 6])
detector.print_bug_report()
```

## 🎯 Exemplo 6: Validador de Compilador

### compiler_validator.py
```python
class CompilerValidator:
    def __init__(self):
        self.test_cases = []
    
    def add_test_case(self, name, c_code, inputs, expected_output):
        """Adiciona caso de teste"""
        self.test_cases.append({
            'name': name,
            'c_code': c_code,
            'inputs': inputs,
            'expected_output': expected_output
        })
    
    def validate_compilation_chain(self, test_case):
        """Valida toda a cadeia de compilação"""
        print(f"\n🧪 Testando: {test_case['name']}")
        
        # Aqui você compilaria o código C para assembly
        # compile_c_to_assembly(test_case['c_code'])
        
        # Simular com o resultado
        simulator = MIPSSimulator()
        simulator.input_values = test_case['inputs']
        
        # Assumindo que o binary foi gerado
        try:
            instructions = simulator.load_binary_file("generated_binary.txt")
            cycles = simulator.run(instructions, max_cycles=10000)
            
            result = {
                'passed': simulator.display == test_case['expected_output'],
                'expected': test_case['expected_output'],
                'actual': simulator.display,
                'cycles': cycles,
                'halted': simulator.halted
            }
            
            if result['passed']:
                print(f"  ✅ PASSOU - Resultado: {result['actual']} ({cycles} ciclos)")
            else:
                print(f"  ❌ FALHOU - Esperado: {result['expected']}, Obtido: {result['actual']}")
            
            return result
            
        except Exception as e:
            print(f"  💥 ERRO: {e}")
            return {'passed': False, 'error': str(e)}
    
    def run_all_tests(self):
        """Executa todos os casos de teste"""
        results = []
        
        for test_case in self.test_cases:
            result = self.validate_compilation_chain(test_case)
            result['name'] = test_case['name']
            results.append(result)
        
        # Relatório final
        passed = sum(1 for r in results if r.get('passed', False))
        total = len(results)
        
        print(f"\n📊 RELATÓRIO FINAL:")
        print(f"Testes aprovados: {passed}/{total} ({passed/total*100:.1f}%)")
        
        if passed < total:
            print("\n❌ Testes que falharam:")
            for r in results:
                if not r.get('passed', False):
                    print(f"  - {r['name']}")
        
        return results

# Configuração dos testes
def setup_compiler_tests():
    validator = CompilerValidator()
    
    # Teste básico
    validator.add_test_case(
        "Básico I/O",
        """
        int main() {
            int x;
            input(x);
            output(x);
            return 0;
        }
        """,
        [42],
        42
    )
    
    # Teste aritmético
    validator.add_test_case(
        "Aritmética",
        """
        int main() {
            int a, b;
            input(a);
            input(b);
            output(a + b);
            return 0;
        }
        """,
        [10, 20],
        30
    )
    
    # Teste condicional
    validator.add_test_case(
        "Condicional",
        """
        int main() {
            int x;
            input(x);
            if (x > 0) output(1);
            else output(0);
            return 0;
        }
        """,
        [5],
        1
    )
    
    return validator

# Executar validação
validator = setup_compiler_tests()
results = validator.run_all_tests()
```

Estes exemplos avançados demonstram como usar o simulador MIPS para análises sofisticadas, desde debugging de algoritmos recursivos até validação completa de compiladores. Cada exemplo pode ser adaptado para diferentes necessidades de teste e análise.
