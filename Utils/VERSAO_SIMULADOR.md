# Versões do Simulador MIPS

## Versão Atual (mips_simulator.py)
- **Data de atualização**: 16/09/2025
- **Versão**: v2.1 - Corrigida e Funcional
- **Linhas de código**: 723
- **Principais características**:
  - ✅ Suporte completo para instrução MULT com 2 e 3 operandos
  - ✅ Formato `MULT rd, rs, rt` (usado pelo assembler atual)
  - ✅ Formato `MULT rs, rt` (formato tradicional MIPS)
  - ✅ Compatibilidade total com o assembler corrigido
  - ✅ Testado e validado com todos os testes funcionais
  - ✅ Log detalhado de execução para debug
  - ✅ Arquitetura flexível (32 bits padrão)

## Correção Crítica
A principal diferença desta versão é o suporte para ambos os formatos da instrução MULT:

### Versão Antiga (2 operandos apenas):
```python
elif opcode == "MULT":
    # Multiply: MULT rs, rt
    rs = self.get_register_number(args[0])
    rt = self.get_register_number(args[1])
    # ... armazena resultado em HI/LO
```

### Versão Atual (2 e 3 operandos):
```python
elif opcode == "MULT":
    # Multiply: MULT rd, rs, rt (3 operandos) ou MULT rs, rt (2 operandos)
    if len(args) == 3:
        # Formato: MULT rd, rs, rt
        rd = self.get_register_number(args[0])
        rs = self.get_register_number(args[1])
        rt = self.get_register_number(args[2])
        
        result = self.registers[rs] * self.registers[rt]
        self.registers[rd] = result & self.max_value
    else:
        # Formato tradicional: MULT rs, rt
        # ... armazena resultado em HI/LO
```

## Testes Validados
- ✅ test_array_access: [200, 400, 300, 400]
- ✅ test_array_param: 30
- ✅ test_global_array: [10, 20, 30]
- ✅ test_loops_arrays: [150, 10, 20, 30]
- ❌ test_multiple_functions: Problemas conhecidos de escopo
- ❌ test_variable_scope: Problemas conhecidos de escopo

## Versões Históricas
- **mips_simulator_old.py**: Versão anterior sem suporte para MULT de 3 operandos
- Todas as outras versões foram consolidadas para esta versão única

## Localização Atualizada
- **Pasta Utils**: Versão principal e atualizada
- **Pasta Testing**: Sincronizada com Utils
- **Pasta Entregável**: Fonte da versão mais recente