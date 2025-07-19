# Exemplo GCD - Máximo Divisor Comum

Este exemplo demonstra o uso do simulador MIPS para validar um programa que calcula o GCD (Greatest Common Divisor) de dois números usando o algoritmo de Euclides.

## 📁 Arquivos

- `binary_output.txt` - Código binário do programa GCD
- `assembly_output.asm` - Assembly legível do programa
- `intermediate_output.txt` - Código intermediário (quadruplas)

## 🎯 Funcionamento

O programa implementa o algoritmo de Euclides:

```c
int gcd(int u, int v) {
    if (v == 0) {
        return u;
    }
    return gcd(v, u % v);
}

int main() {
    int x, y;
    x = input();  // Lê primeiro número
    y = input();  // Lê segundo número
    output(gcd(x, y));  // Exibe resultado
    halt();
}
```

## 🚀 Como Executar

### 1. Execução Básica
```bash
python ../simulator_mips.py binary_output.txt
```

### 2. Com Detecção de Erros
```bash
python ../detector_erros.py
```

### 3. Teste com Valores Específicos
```python
from simulator_mips import MIPSSimulator

simulator = MIPSSimulator(debug=True)
simulator.input_values = [4, 6]  # GCD(4,6) = 2
instructions = simulator.load_binary_file("binary_output.txt")
simulator.run(instructions)
print(f"Resultado: {simulator.display}")  # Deve mostrar 2
```

## 📊 Resultados Esperados

- **Entrada**: 4, 6
- **Saída**: 2
- **Instruções executadas**: ~50-100
- **Chamadas recursivas**: 3

### Trace de Execução (resumido)
```
PC=  0: J          25  # Pula para main
PC= 25: INPUT      R8  # Lê primeiro número (4)
PC= 26: SW         MEM[0] = 4  # Salva na memória
PC= 27: INPUT      R9  # Lê segundo número (6)
PC= 28: SW         MEM[1] = 6  # Salva na memória
...
PC= 34: JAL        1   # Chama GCD(4,6)
  PC=  1: LW       R1, 1(R29)  # Carrega v=6
  PC=  2: BNE      R1, R2, 5   # v != 0? Sim, vai para L0
  PC=  6: LW       R3, 0(R29)  # Carrega u=4
  ...                         # Calcula u % v = 4
  PC= 19: JAL      1           # Chama GCD(6,4)
    ...                       # GCD(6,4) -> GCD(4,2)
    ...                       # GCD(4,2) -> GCD(2,0)
    ...                       # GCD(2,0) -> return 2
PC= 37: OUTPUTREG R12  # Exibe resultado: 2
PC= 38: HALT       # Termina
```

## 🐛 Problemas Conhecidos (Corrigidos)

### 1. Offset de Parâmetros
**Problema**: Parâmetros acessados em posições incorretas
**Sintoma**: GCD(4,6) retornava 0
**Correção**: Ajuste +4 nos offsets após setup do frame

### 2. Jump Inicial Incorreto
**Problema**: Jump inicial para endereço errado
**Sintoma**: Loop infinito entre PC=0 e PC=24
**Correção**: Atualização do endereço do main de 22 para 25

## 📈 Métricas de Performance

- **Ciclos de clock**: ~100-150
- **Uso de memória**: Posições 0-2 (parâmetros e RA)
- **Profundidade de pilha**: 3 níveis (recursão)
- **Registradores utilizados**: R1-R12, R29(SP), R31(RA)

## 🔍 Análise Detalhada

### Convenção de Chamada
```asm
# Preparação da chamada
SW R10, 1(R29)    # Parâmetro 2 na pilha
SW R11, 0(R29)    # Parâmetro 1 na pilha
SW R31, 2(R29)    # Salva endereço de retorno
JAL 1             # Chama função

# Na função
LW R1, 1(R29)     # Carrega parâmetro 2
LW R3, 0(R29)     # Carrega parâmetro 1
```

### Gestão de Memória
- **Posição 0**: Primeiro parâmetro (u)
- **Posição 1**: Segundo parâmetro (v)  
- **Posição 2**: Endereço de retorno (RA)
- **SP (R29)**: Aponta para topo da pilha (255)

Este exemplo serve como referência para validação de assembladores e teste de convenções de chamada em processadores MIPS customizados.
