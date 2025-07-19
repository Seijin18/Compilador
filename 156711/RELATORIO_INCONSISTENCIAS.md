# RELATÓRIO DE INCONSISTÊNCIAS NO ASSEMBLY

## 🎯 Objetivo

Identificação e correção de inconsistências críticas na tradução de código intermediário (quadruplas) para assembly MIPS.

## 🔍 Inconsistências Identificadas

### 1️⃣ INCONSISTÊNCIA CONDICIONAL: BEQ vs BNE

**📍 Localização:**
- Quadruplas: linhas 6-7
- Assembly: linha 2

**📋 Descrição do Problema:**
```
Quadrupla linha 6: (==,v,t0,t1)     → t1 = (v == 0)
Quadrupla linha 7: (if_f,t1,L0, )   → if (!t1) goto L0  
Assembly linha 2:   BEQ R1, R0, 5   → if (R1 == 0) goto 5
```

**❌ Erro Identificado:**
- `if_f(t1)` significa "pule SE t1 for FALSO"
- Como `t1 = (v == 0)`, então `if_f(t1)` significa "pule SE v ≠ 0"
- Mas o assembly usa `BEQ` que pula SE v == 0 (lógica invertida!)

**✅ Correção Necessária:**
```assembly
❌ Original:  BEQ R1, R0, 5
✅ Corrigido: BNE R1, R0, 6
```

**🎯 Justificativa:**
- `BNE` implementa corretamente a lógica "pule SE v ≠ 0"
- Endereço 6 (não 5) corresponde ao label L0

### 2️⃣ INCONSISTÊNCIA DA DIVISÃO: MFLO vs MFHI

**📍 Localização:**
- Quadrupla: linha 10
- Assembly: linha 9

**📋 Descrição do Problema:**
```
Quadrupla linha 10: (/,u,v,t2)      → t2 = u / v (quociente)
Assembly linha 8-9:  DIV R3, R1     → R3 / R1
                     MFLO R4        → R4 = resto (LO register)
```

**❌ Erro Identificado:**
- A quadrupla `/` solicita o **quociente** da divisão (t2 = u/v)
- `MFLO` recupera o **resto** da divisão (LO register)
- Para o algoritmo GCD calcular `u % v = u - (u/v)*v`, precisa do quociente primeiro

**✅ Correção Necessária:**
```assembly
❌ Original:  MFLO R4
✅ Corrigido: MFHI R4
```

**🎯 Justificativa:**
- `MFHI` recupera o quociente (HI register)
- Permite o cálculo correto: t3 = t2*v, t4 = u-t3 = u%v

## 🧮 Análise de Impacto

### ⚠️ Comportamento com Bugs

**Entrada:** GCD(48, 18)

1. **Bug Condicional:** 
   - v=18, BEQ testa se 18==0 (falso), então NÃO pula
   - Executa return u=48 prematuramente
   - **Resultado errado:** 48 (deveria ser 6)

2. **Bug da Divisão (se chegasse até lá):**
   - DIV 48,18 → HI=2, LO=12
   - MFLO pega 12 (resto) em vez de 2 (quociente)
   - Cálculo: t3=12*18=216, t4=48-216=-168 (absurdo!)

### ✅ Comportamento Corrigido

**Entrada:** GCD(48, 18)

1. **Correção Condicional:**
   - v=18, BNE testa se 18≠0 (verdadeiro), então PULA para L0
   - Continua com algoritmo correto

2. **Correção da Divisão:**
   - DIV 48,18 → HI=2, LO=12
   - MFHI pega 2 (quociente correto)
   - Cálculo: t3=2*18=36, t4=48-36=12 (correto!)
   - Continua: GCD(18,12) → GCD(12,6) → GCD(6,0) → **6**

## 📊 Validação Teórica

| Caso de Teste | Original (Bugado) | Corrigido | Esperado |
|---------------|-------------------|-----------|----------|
| GCD(48, 18)   | 48               | 6         | 6        |
| GCD(15, 10)   | 15               | 5         | 5        |
| GCD(12, 8)    | 12               | 4         | 4        |
| GCD(7, 0)     | 7                | 7         | 7        |

## 🔧 Arquivos Modificados

### Assembly Corrigido
Criado: `assembly_output_corrigido.asm`
- Linha 2: `BEQ` → `BNE` 
- Linha 9: `MFLO` → `MFHI`

### Scripts de Análise
1. `analise_inconsistencias.py` - Análise inicial
2. `analise_completa_inconsistencias.py` - Análise detalhada
3. `teste_correcoes_assembly.py` - Teste das correções

## 🎯 Próximos Passos

1. **Aplicar correções no assemblador** (código C)
2. **Regenerar assembly** a partir das quadruplas
3. **Validar com casos de teste** diversos
4. **Documentar padrões** para evitar problemas similares

## 📋 Lições Aprendidas

1. **Tradução de condicionais:** `if_f` requer cuidado especial na tradução
2. **Operações DIV:** Distinção clara entre quociente (MFHI) e resto (MFLO)
3. **Endereçamento:** Labels devem corresponder exatamente aos endereços
4. **Validação:** Assembly deve ser testado contra casos conhecidos

---

**📅 Data:** 19/07/2025  
**✍️ Análise realizada:** Identificação de 2 inconsistências críticas  
**🎯 Status:** Correções propostas e validadas teoricamente  
**🚀 Próximo:** Aplicação das correções no assemblador
