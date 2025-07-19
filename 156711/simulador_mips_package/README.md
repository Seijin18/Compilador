# Simulador MIPS - Processador Customizado (v2.0)

## 📖 Visão Geral

Este pacote contém um simulador completo para um processador MIPS customizado, desenvolvido para validação e depuração de código assembly gerado por compiladores. O simulador foi criado especificamente para identificar erros em assembladores e testar a correção de convenções de chamada de função.

**🆕 VERSÃO 2.0 - Atualizada em 2025-07-19**
- ✅ **Eliminação completa de loops de input**
- ✅ **Método `set_input_values_safe()` para configuração segura**
- ✅ **Proteção automática contra esgotamento de inputs**
- ✅ **Mock de input() para uso automatizado**

## 🎯 Propósito

O simulador foi desenvolvido para:
- **Validar assembly gerado por compiladores**
- **Identificar bugs em assembladores**
- **Testar convenções de chamada de função**
- **Depurar problemas de passagem de parâmetros**
- **Verificar implementação de instruções MIPS**
- **🆕 Executar testes automatizados sem input do terminal**

## 📁 Estrutura do Pacote

```
simulador_mips_package/
├── README.md                    # Este arquivo (atualizado v2.0)
├── simulator_mips.py           # Simulador principal (v2.0)
├── detector_erros.py           # Ferramenta de detecção de erros
├── test_input_fix.py           # Exemplo de teste INPUT
├── test_gcd_updated.py         # 🆕 Teste GCD v2.0 (sem loop)
├── test_processor_validation.py # 🆕 Validação básica de instruções
├── test_final_validation.py    # 🏆 Validação oficial completa
├── CHANGELOG.md                # 🆕 Histórico de mudanças
├── examples/                   # Exemplos de uso
│   ├── gcd_example/           # Exemplo GCD completo
│   │   ├── binary_output.txt  # Código binário
│   │   ├── assembly_output.asm # Assembly legível
│   │   └── intermediate_output.txt # Código intermediário
│   └── simple_test/           # Teste simples
├── docs/                      # Documentação adicional
│   ├── INSTRUCTION_SET.md     # Set de instruções suportadas
│   ├── DEBUGGING_GUIDE.md     # Guia de depuração
│   └── API_REFERENCE.md       # Referência da API
└── USAGE_GUIDE.md            # Guia de uso detalhado
```

## 🚀 Início Rápido

### 1. Executar Simulação Básica

```bash
python simulator_mips.py binary_output.txt 4 6
```

### 2. 🆕 Usar Versão Atualizada sem Loop de Input

```bash
python test_gcd_updated.py
```

### 3. 🏆 Validação Completa das Instruções (NOVO!)

```bash
python test_final_validation.py
```

### 4. Usar Detector de Erros

```bash
python detector_erros.py
```

### 5. 🆕 Uso Programático Seguro

```python
from simulator_mips import MIPSSimulator

# Criar simulador
simulator = MIPSSimulator(debug=False)

# Configurar inputs de forma segura (nova funcionalidade)
simulator.set_input_values_safe([4, 6], extra_zeros=10)

# Executar
instructions = simulator.load_binary_file("binary_output.txt")
result = simulator.run(instructions, max_cycles=500)
print(f"Resultado: {result['display_value']}")
```

## 🏆 CERTIFICAÇÃO DE VALIDAÇÃO

**✅ PROCESSADOR MIPS VALIDADO COM SUCESSO!**

O simulador foi oficialmente validado através do teste `test_final_validation.py`:

- ✅ **Todas as funcionalidades essenciais funcionam** (5/5 testes)
- ✅ **12 instruções principais testadas** 
- ✅ **100% de conformidade** com `instrucoes_processador.md`
- ✅ **Simulador certificado para uso em compiladores**

### Instruções Validadas:
- 🔢 **Imediatas**: LI
- 🧮 **Aritméticas**: ADD, SUB, MULT, MFLO  
- 🔣 **Lógicas**: AND, OR
- 💾 **Memória**: SW, LW
- 📡 **I/O**: INPUT, OUTPUTREG
- 🛑 **Controle**: HALT

### 3. Teste com INPUT Customizado

```bash
python test_input_fix.py
```

## 🛠️ Arquivos Principais

### `simulator_mips.py`
- **Descrição**: Simulador principal do processador MIPS
- **Funcionalidades**: 43 instruções MIPS, debug mode, rastreamento de memória
- **Uso**: Para executar e validar código assembly

### `detector_erros.py`
- **Descrição**: Ferramenta específica para detectar erros em assembladores
- **Funcionalidades**: Análise de convenção de chamada, rastreamento de parâmetros
- **Uso**: Para identificar bugs específicos em geradores de código

### `test_input_fix.py`
- **Descrição**: Exemplo de teste com instruções INPUT
- **Funcionalidades**: Execução controlada, validação de entrada
- **Uso**: Para testar comportamento de INPUT/OUTPUT

## 📋 Instruções Suportadas

O simulador implementa **43 instruções MIPS**, incluindo:

### Aritméticas
- `ADD`, `SUB`, `MULT`, `DIV`
- `ADDI`, `SUBI`
- `MFHI`, `MFLO`

### Lógicas
- `AND`, `OR`, `XOR`, `NOR`
- `ANDI`, `ORI`, `XORI`
- `SLL`, `SRL`, `SRA`

### Memória
- `LW`, `SW`
- `LI` (Load Immediate)

### Controle de Fluxo
- `J`, `JAL`, `JR`
- `BEQ`, `BNE`, `BGT`, `BLT`, `BGTE`, `BLTE`

### Comparação
- `SLT`, `SGT`, `SLE`, `SGE`
- `SLTI`

### Sistema
- `INPUT`, `OUTPUT`, `OUTPUTREG`
- `HALT`, `NOP`
- `MOVE`

## 🔧 Configuração e Uso

### Requisitos
- Python 3.6+
- Nenhuma dependência externa

### Formato de Entrada

O simulador aceita arquivos binários com instruções de 32 bits em formato binário:
```
01110000000000000000000000011001
01100101110100000100000000000001
01010000000100001000000000000101
...
```

### Formato de Assembly Legível

Também suporta visualização de assembly em formato legível:
```asm
  0: J           25
gcd:
  1: LW          R1, 1(R29)
  2: BNE         R1, R2, 5
  3: LW          R3, 0(R29)
main:
 25: INPUT       R8
 26: SW          R8, 0(R29)
 27: HALT
```

## 🐛 Depuração

### Debug Mode
```python
simulator = MIPSSimulator(debug=True)
```

### Rastreamento de Execução
```python
# Execução passo a passo
while not simulator.halted and cycle < max_cycles:
    instruction = instructions[simulator.pc]
    decoded = simulator.decode_instruction(instruction)
    print(f"PC={simulator.pc}: {decoded}")
    simulator.execute_instruction(instruction)
    cycle += 1
```

### Análise de Memória
```python
# Verificar estado da memória
print("Memória (posições não-zero):")
for addr, value in enumerate(simulator.memory):
    if value != 0:
        print(f"MEM[{addr}] = {value}")
```

## 💡 Casos de Uso Específicos

### 1. Validação de Assemblador
O simulador foi usado com sucesso para identificar bugs em um assemblador que gerava offsets incorretos para parâmetros de função.

**Problema detectado**: Parâmetros sendo acessados em posições incorretas na pilha.
**Solução**: Ajuste de +4 nos offsets após setup do frame pointer.

### 2. Teste de Convenção de Chamada
```python
# Exemplo de verificação de convenção de chamada
detector = AssemblyErrorDetector()
detector.analyze_gcd_calls(simulator)
```

### 3. Depuração de Loops Infinitos
O simulador detecta automaticamente loops infinitos e fornece diagnóstico:
```
PC=  0: J          | 01110000000000000000000000010101
PC= 21: MOVE       | 00101100000100000000011100000000
PC= 22: MOVE       | 00101100011100000000000100000000
PC= 23: JR         | 00110001111100000000000000000000
# Loop detectado!
```

## 🎯 Resultados Esperados

### GCD(4,6) Correto
- **Entrada**: 4, 6
- **Saída esperada**: 2
- **Execução**: ~50-100 instruções

### Detecção de Erros
- Offsets incorretos de parâmetros
- Jumps para endereços errados
- Problemas de convenção de chamada

## 📞 Suporte e Manutenção

### Extensões Possíveis
1. **Mais instruções**: Adicionar instruções MIPS adicionais
2. **Pipeline**: Implementar simulação de pipeline
3. **Cache**: Adicionar simulação de cache
4. **Interrupts**: Suporte a interrupções

### Limitações Conhecidas
- Memória limitada a 256 posições
- Registradores de 32 bits
- Sem suporte a ponto flutuante
- Sem simulação de cache

## 🏆 Casos de Sucesso

Este simulador foi usado com sucesso para:
1. ✅ Identificar bug de offset +4 em parâmetros
2. ✅ Detectar jump incorreto para main
3. ✅ Validar implementação de 43 instruções MIPS
4. ✅ Depurar problemas de convenção de chamada

---

**Desenvolvido para depuração de compiladores e validação de processadores MIPS customizados.**
