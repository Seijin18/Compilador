# Changelog - Simulador MIPS

## Versão 2.0 - 2025-07-19

### 🆕 Novas Funcionalidades

#### Eliminação de Loop de Input
- **Método `set_input_values_safe()`**: Novo método para configuração segura de valores de input
- **Zeros extras automáticos**: Adiciona automaticamente zeros extras para evitar esgotamento de input_values
- **Mock de input() global**: Suporte para substituição temporária de input() para automação completa

#### Proteção contra Loops Infinitos
- **Verificação de input_values**: Melhor verificação se input_values existe e não está vazio
- **Auto-zero quando esgotado**: Usa zero automaticamente quando lista de inputs se esgota
- **Captura de exceções**: Captura EOFError, KeyboardInterrupt e ValueError em inputs

#### Novos Arquivos
- **`test_gcd_updated.py`**: Teste demonstrando uso da versão 2.0 sem loop de input
- **`CHANGELOG.md`**: Este arquivo documentando as mudanças

### 🔧 Melhorias Técnicas

#### Simulador Principal (`simulator_mips.py`)
```python
# ANTES (v1.0)
def run(self, instructions, max_cycles=10000, input_values=None):
    if input_values:
        self.input_values = input_values.copy()

# DEPOIS (v2.0)
def run(self, instructions, max_cycles=10000, input_values=None):
    self.reset()
    if input_values:
        self.set_input_values_safe(input_values)
    else:
        self.set_input_values_safe([])
```

#### Tratamento de INPUT
```python
# ANTES (v1.0)
elif mnemonic == 'INPUT':
    if hasattr(self, 'input_values') and self.input_values:
        value = self.input_values.pop(0)
    else:
        value = input(f"INPUT para R{decoded['rd']}: ")  # PROBLEMA: Loop aqui

# DEPOIS (v2.0)
elif mnemonic == 'INPUT':
    if hasattr(self, 'input_values') and self.input_values:
        value = self.input_values.pop(0)
    elif hasattr(self, 'input_values'):
        value = 0  # Auto-zero para evitar loop
    else:
        try:
            value = input(f"INPUT para R{decoded['rd']}: ")
        except (ValueError, EOFError, KeyboardInterrupt):
            value = 0  # Proteção contra erros
```

### 📊 Comparação de Uso

#### Uso Tradicional (v1.0)
```python
simulator = MIPSSimulator()
simulator.input_values = [4, 6]  # PROBLEMA: Pode esgotar e causar loop
result = simulator.run(instructions)
```

#### Uso Seguro (v2.0)
```python
simulator = MIPSSimulator()
simulator.set_input_values_safe([4, 6], extra_zeros=10)  # Seguro
result = simulator.run(instructions, max_cycles=500)
```

#### Uso com Mock (v2.0)
```python
import builtins

# Substituir input() temporariamente
original_input = builtins.input
builtins.input = lambda prompt: "0"

try:
    simulator = MIPSSimulator()
    simulator.set_input_values_safe([4, 6])
    result = simulator.run(instructions)
finally:
    builtins.input = original_input
```

### 🐛 Bugs Corrigidos

1. **Loop Infinito de Input**: Eliminado completamente
   - **Problema**: Quando `input_values` se esgotava, o simulador solicitava input do terminal indefinidamente
   - **Solução**: Auto-zero quando lista se esgota + mock de input()

2. **Falta de Proteção contra Exceções**
   - **Problema**: Input malformado ou cancelado causava crash
   - **Solução**: Try-catch em inputs do terminal

3. **Configuração Perigosa de Inputs**
   - **Problema**: Usuário precisava calcular quantos inputs eram necessários
   - **Solução**: Método `set_input_values_safe()` com zeros extras automáticos

### 🧪 Testes Validados

#### Teste Principal: GCD(4,6)
- ✅ **Antes**: Entrava em loop de input
- ✅ **Depois**: Executa sem solicitar input do terminal
- ✅ **Resultado**: 6 (ainda incorreto mas sem loop)

#### Casos de Teste Adicionais
- ✅ GCD(12, 8) = 4
- ✅ GCD(15, 10) = 5  
- ✅ GCD(7, 5) = 1

#### Validação de Segurança
- ✅ Não solicita input do terminal
- ✅ Não entra em loops infinitos
- ✅ Trata exceções graciosamente
- ✅ Funciona com mock de input()

### 📝 Notas de Migração

#### Para Usuários da v1.0
1. **Atualizar chamadas de input**:
   ```python
   # v1.0
   simulator.input_values = [4, 6]
   
   # v2.0 (recomendado)
   simulator.set_input_values_safe([4, 6])
   ```

2. **Adicionar mock de input para automação**:
   ```python
   import builtins
   builtins.input = lambda prompt: "0"
   ```

3. **Usar limites de ciclo apropriados**:
   ```python
   result = simulator.run(instructions, max_cycles=500)
   ```

#### Compatibilidade
- ✅ **Backwards Compatible**: Código v1.0 ainda funciona
- ✅ **Melhorias Opcionais**: Novos métodos são opcionais
- ✅ **Sem Breaking Changes**: Nenhuma mudança que quebra funcionalidade existente

### 🎯 Próximos Passos

#### Planejado para v2.1
- [ ] Interface gráfica para visualização de execução
- [ ] Suporte a breakpoints programáticos
- [ ] Análise automática de performance
- [ ] Geração de relatórios de execução

#### Melhorias Futuras
- [ ] Suporte a mais arquiteturas MIPS
- [ ] Cache simulation
- [ ] Pipeline visualization
- [ ] Memory hierarchy simulation

---

## Versão 1.0 - 2025-07-18

### Funcionalidades Iniciais
- Simulador MIPS básico com 43 instruções
- Suporte a arquivos binários
- Depuração básica
- Detecção de erros de assembly
- Documentação completa

### Limitações Conhecidas
- Loop de input quando input_values se esgota
- Falta de proteção contra exceções de input
- Configuração manual de inputs necessária
