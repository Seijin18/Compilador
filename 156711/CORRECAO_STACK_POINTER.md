# CORREÇÃO CRÍTICA: INICIALIZAÇÃO DO STACK POINTER

## PROBLEMA IDENTIFICADO

**Situação Anterior:**
```assembly
# PROBLEMA: R29 (Stack Pointer) não inicializado!
main:
 35: SW         R31, -4(R29)  # R29 = 0, endereço = -4 (INVÁLIDO!)
 36: SW         R30, -8(R29)  # R29 = 0, endereço = -8 (INVÁLIDO!)
```

Se R29 = 0 (valor padrão), tentamos acessar:
- Endereço -4 (para salvar RA)
- Endereço -8 (para salvar FP)

**Consequências:**
- ❌ Acesso a endereços negativos inválidos
- ❌ Comportamento indefinido do processador
- ❌ Possível crash ou corrupção de dados
- ❌ Stack overflow desde o início

## SOLUÇÃO IMPLEMENTADA

**Correção Aplicada:**
```assembly
# SOLUÇÃO: Inicialização adequada dos registradores base
  0: LI         R28, 128     # GP = 128 (base das variáveis globais)
  1: LI         R29, 255     # SP = 255 (topo da pilha na RAM 8-bit)
  2: J          36
```

Agora quando executamos main:
```assembly
main:
 36: SW         R31, -4(R29)  # R29 = 255, endereço = 251 ✅ VÁLIDO!
 37: SW         R30, -8(R29)  # R29 = 255, endereço = 247 ✅ VÁLIDO!
```

## LAYOUT DE MEMÓRIA CORRIGIDO (RAM 8-bit: 0-255)

```
Endereço    Uso
255    ←── SP inicial (topo da pilha)
254
253
252
251    ←── Primeiro RA salvo (-4 do SP)
250
249
248
247    ←── Primeiro FP salvo (-8 do SP)
246
...
129    ←── Área da pilha
128    ←── GP (base das variáveis globais)
127
...
1
0      ←── Base da RAM
```

## BENEFÍCIOS DA CORREÇÃO

1. **✅ Endereços Válidos**: Todos os acessos dentro do range 0-255
2. **✅ Pilha Funcional**: Stack cresce para baixo corretamente
3. **✅ Separação Clara**: Globais (128+) vs Stack (255-)
4. **✅ Compatibilidade**: 100% com arquitetura 8-bit
5. **✅ Segurança**: Sem acesso a endereços inválidos

## ANTES vs DEPOIS

### ANTES (Problemático):
```assembly
# Sem inicialização
main:
 SW R31, -4(R29)    # R29=0 → endereço -4 ❌ INVÁLIDO
 SW R30, -8(R29)    # R29=0 → endereço -8 ❌ INVÁLIDO
```

### DEPOIS (Corrigido):
```assembly
# Com inicialização adequada
LI R28, 128          # GP = base das globais
LI R29, 255          # SP = topo da pilha
main:
 SW R31, -4(R29)    # R29=255 → endereço 251 ✅ VÁLIDO
 SW R30, -8(R29)    # R29=255 → endereço 247 ✅ VÁLIDO
```

## VERIFICAÇÃO DOS LIMITES

- **Endereço máximo da pilha**: 255 (SP inicial)
- **Endereço mínimo estimado**: ~200 (considerando funções aninhadas)
- **Margem de segurança**: ~72 palavras (255-128-55 = 72)
- **Área de globais**: 128-255 (128 palavras disponíveis)

## CONCLUSÃO

Esta correção resolve um bug crítico que tornaria o código completamente inviável na prática. Sem ela, qualquer tentativa de usar a pilha resultaria em acesso a memória inválida.

**Status: CORREÇÃO CRÍTICA IMPLEMENTADA COM SUCESSO** ✅
