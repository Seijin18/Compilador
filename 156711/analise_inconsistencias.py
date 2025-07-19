#!/usr/bin/env python3
"""
Análise de Inconsistências no Assembly Gerado
Identifica e corrige problemas na tradução das quadruplas para assembly
"""


def analisar_inconsistencias():
    """
    Analisa as inconsistências identificadas pelo usuário
    """
    print("🔍 ANÁLISE DE INCONSISTÊNCIAS NO ASSEMBLY")
    print("=" * 60)

    print("\n📋 PROBLEMAS IDENTIFICADOS:")
    print("-" * 40)

    # Problema 1: BEQ vs BNE
    print("\n1️⃣ PROBLEMA: BEQ vs BNE")
    print("   📄 Quadrupla linha 6: (==,v,t0,t1)")
    print("   📄 Quadrupla linha 7: (if_f,t1,L0, )")
    print("   🔧 Assembly linha 2:   BEQ R1, R0, 5")
    print("")
    print("   ❌ ERRO IDENTIFICADO:")
    print("      - if_f significa 'if false', ou seja, pular SE t1 for FALSO")
    print("      - t1 = (v == 0), então if_f(t1) significa pular SE v ≠ 0")
    print("      - Deveria ser BNE (Branch if Not Equal), não BEQ!")
    print("")
    print("   ✅ CORREÇÃO NECESSÁRIA:")
    print("      - Linha 2: BEQ R1, R0, 5  →  BNE R1, R0, 6")
    print("      - Lógica: SE v ≠ 0 ENTÃO pule para L0 (linha 6)")

    # Problema 2: DIV e MFLO vs MFHI
    print("\n2️⃣ PROBLEMA: DIV e recuperação do resultado")
    print("   📄 Quadrupla linha 10: (/,u,v,t2)")
    print("   🔧 Assembly linha 8-9:  DIV R3, R1")
    print("                          MFLO R4")
    print("")
    print("   ❌ ERRO IDENTIFICADO:")
    print("      - A quadrupla (/) solicita o QUOCIENTE da divisão")
    print("      - MFLO recupera a parte BAIXA (resto da divisão)")
    print("      - MFHI recupera a parte ALTA (quociente da divisão)")
    print("      - Para GCD, precisamos do RESTO, não o quociente!")
    print("")
    print("   🤔 ANÁLISE DO CONTEXTO:")
    print("      - No algoritmo GCD: u % v (resto da divisão u/v)")
    print("      - Linhas 10-14 calculam: u - (u/v)*v = u % v")
    print("      - Portanto t2 deveria ser u/v (quociente) mesmo!")
    print("")
    print("   ✅ CORREÇÃO NECESSÁRIA:")
    print("      - Linha 9: MFLO R4  →  MFHI R4")
    print("      - Lógica: t2 = quociente de u/v para calcular resto")


def analisar_logica_gcd():
    """
    Analisa a lógica do algoritmo GCD para entender melhor
    """
    print("\n🧮 ANÁLISE DA LÓGICA DO GCD")
    print("=" * 60)

    print("\n📚 ALGORITMO EUCLIDIANO:")
    print("   gcd(u, v) = {")
    print("     if (v == 0) return u;")
    print("     else return gcd(v, u % v);")
    print("   }")

    print("\n🔄 TRADUÇÃO DAS QUADRUPLAS:")
    print("   Linha 5: (immed,0, ,t0)     → t0 = 0")
    print("   Linha 6: (==,v,t0,t1)       → t1 = (v == 0)")
    print("   Linha 7: (if_f,t1,L0, )     → if (!t1) goto L0")
    print("                                → if (v != 0) goto L0")
    print("   Linha 8: (ret,u, , )        → return u")
    print("")
    print("   Linha 10: (/,u,v,t2)        → t2 = u / v (quociente)")
    print("   Linha 11: (*,t2,v,t3)       → t3 = t2 * v")
    print("   Linha 12: (-,u,t3,t4)       → t4 = u - t3 = u % v")


def criar_correcoes():
    """
    Cria as correções necessárias no assembly
    """
    print("\n🔧 CORREÇÕES NECESSÁRIAS")
    print("=" * 60)

    print("\n📝 ASSEMBLY ORIGINAL:")
    print("   1: LW          R1, 1(R29)")
    print("   2: BEQ         R1, R0, 5     ← ERRO 1")
    print("   3: LW          R3, 0(R29)")
    print("   4: MOVE        R1, R3")
    print("   5: JR          R31")
    print("L0:")
    print("   6: LW          R3, 0(R29)")
    print("   7: LW          R1, 1(R29)")
    print("   8: DIV         R3, R1")
    print("   9: MFLO        R4            ← ERRO 2")

    print("\n✅ ASSEMBLY CORRIGIDO:")
    print("   1: LW          R1, 1(R29)")
    print("   2: BNE         R1, R0, 6     ← CORREÇÃO 1")
    print("   3: LW          R3, 0(R29)")
    print("   4: MOVE        R1, R3")
    print("   5: JR          R31")
    print("L0:")
    print("   6: LW          R3, 0(R29)")
    print("   7: LW          R1, 1(R29)")
    print("   8: DIV         R3, R1")
    print("   9: MFHI        R4            ← CORREÇÃO 2")

    print("\n🎯 EXPLICAÇÃO DAS CORREÇÕES:")
    print("   CORREÇÃO 1 (BEQ → BNE):")
    print("     - if_f(v==0) significa 'se v≠0'")
    print("     - BNE R1, R0, 6: pula para L0 se R1≠0")
    print("     - Endereço 6 (não 5) porque L0 está na linha 6")
    print("")
    print("   CORREÇÃO 2 (MFLO → MFHI):")
    print("     - DIV armazena quociente em HI, resto em LO")
    print("     - Para t2=u/v precisamos do quociente (MFHI)")
    print("     - Depois t3=t2*v e t4=u-t3 calculam o resto")


def verificar_enderecos():
    """
    Verifica os endereços de jump
    """
    print("\n📍 VERIFICAÇÃO DE ENDEREÇOS")
    print("=" * 60)

    print("\n🎯 ENDEREÇOS DAS LABELS:")
    print("   gcd:  linha 1")
    print("   L0:   linha 6")
    print("   L1:   linha 24")
    print("   main: linha 25")

    print("\n🔍 JUMPS E BRANCHES:")
    print("   Linha 0: J 25        → Pula para main (✅ correto)")
    print("   Linha 2: BEQ R1,R0,5 → Deveria pular para linha 5 se v==0")
    print("                        → Linha 5 é 'JR R31' (return) (✅ lógica)")
    print("                        → MAS deveria ser BNE para L0 se v≠0!")
    print("   Linha 19: JAL 1      → Chama gcd na linha 1 (✅ correto)")
    print("   Linha 34: JAL 1      → Chama gcd na linha 1 (✅ correto)")


def main():
    """
    Função principal de análise
    """
    analisar_inconsistencias()
    analisar_logica_gcd()
    criar_correcoes()
    verificar_enderecos()

    print("\n" + "=" * 60)
    print("🎯 RESUMO DAS INCONSISTÊNCIAS ENCONTRADAS:")
    print("   1️⃣ BEQ deveria ser BNE (problema de lógica condicional)")
    print("   2️⃣ MFLO deveria ser MFHI (problema de operação DIV)")
    print("")
    print("🔧 AÇÕES NECESSÁRIAS:")
    print("   ✅ Corrigir geração de branches condicionais no assemblador")
    print("   ✅ Corrigir recuperação de resultado da divisão")
    print("   ✅ Testar com dados de entrada para validar correções")


if __name__ == "__main__":
    main()
