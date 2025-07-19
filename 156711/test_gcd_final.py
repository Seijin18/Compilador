#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Teste do GCD sem solicitação de input do terminal - VERSÃO CORRIGIDA
"""

import builtins
from simulator_mips import MIPSSimulator


def mock_input_safe(prompt=""):
    """Mock que sempre retorna 0 para evitar loop de input"""
    print(f"[MOCK INPUT] {prompt}: 0")
    return "0"


def test_gcd_without_input():
    print("=== TESTE GCD(4,6) SEM INPUT DO TERMINAL ===")
    print("Resultado esperado: 2")
    print("=" * 50)

    # Substituir input() globalmente para evitar loops
    original_input = builtins.input
    builtins.input = mock_input_safe

    try:
        # Usar simulador sem debug para evitar input
        simulator = MIPSSimulator(debug=False)

        # Configurar inputs com valores extras para evitar esgotamento
        simulator.input_values = [4, 6, 0, 0, 0, 0, 0, 0]  # Valores extras

        # Carregar instruções
        instructions = simulator.load_binary_file("binary_output.txt")

        if not instructions:
            print("❌ Erro: Não foi possível carregar binary_output.txt")
            return False

        print(f"📂 Carregadas {len(instructions)} instruções")

        # Executar programa completo com limite de ciclos
        result = simulator.run(instructions, max_cycles=200)

        print("\n📊 RESULTADO DA EXECUÇÃO:")
        print("=" * 30)

        if isinstance(result, dict):
            halted = result.get("halted", False)
            instructions_count = result.get("instructions_executed", 0)
            display_value = result.get("display_value", "N/A")

            print(f"✅ Programa terminou: {'Sim' if halted else 'Não'}")
            print(f"📈 Instruções executadas: {instructions_count}")
            print(f"🎯 Resultado obtido: {display_value}")
            print(f"🎯 Resultado esperado: 2")

            # Verificar se está correto
            if display_value == 2:
                print("\n🎉 SUCESSO! O assembler está funcionando corretamente!")
                return True
            else:
                print(f"\n❌ FALHA! Resultado incorreto.")

                # Análise do erro
                if display_value == 6:
                    print("   • O algoritmo retornou o segundo parâmetro")
                    print("   • Problema na lógica do GCD no assembly")
                elif display_value == 4:
                    print("   • O algoritmo retornou o primeiro parâmetro")
                    print("   • Problema na condição de parada do GCD")
                else:
                    print(f"   • Resultado inesperado: {display_value}")

                return False

        else:
            print(f"⚠️  Resultado numérico: {result} ciclos")
            return False

    except Exception as e:
        print(f"💥 Erro durante execução: {e}")
        return False

    finally:
        # Restaurar input original
        builtins.input = original_input

        # Mostrar estado final (sem debug para evitar input)
        print(f"\n📋 ESTADO FINAL:")
        print(f"   Registradores principais:")
        print(f"     R8 (primeiro input): {simulator.registers[8]}")
        print(f"     R9 (segundo input): {simulator.registers[9]}")
        print(f"   Memória (stack):")
        for i in range(5):
            if simulator.memory[i] != 0:
                print(f"     MEM[{i}] = {simulator.memory[i]}")


def summary_corrections():
    print("\n" + "=" * 50)
    print("📝 RESUMO DAS CORREÇÕES APLICADAS:")
    print("=" * 50)
    print("✅ 1. Jump inicial corrigido:")
    print("     • Era: J 21 (endereço incorreto)")
    print("     • Agora: J 25 (main function)")
    print("")
    print("✅ 2. Instrução de comparação corrigida:")
    print("     • Era: BNE R1, R2, 5 (R2 não inicializado)")
    print("     • Agora: BEQ R1, R0, 5 (testa se v == 0)")
    print("")
    print("✅ 3. Loop de input resolvido:")
    print("     • Mock de input() implementado")
    print("     • Valores extras fornecidos para input_values")
    print("     • Limite de ciclos ajustado para evitar loops infinitos")
    print("")
    print("❌ 4. Problema restante:")
    print("     • GCD ainda retorna valor incorreto")
    print("     • Possível problema na lógica do algoritmo")


if __name__ == "__main__":
    success = test_gcd_without_input()
    summary_corrections()

    if success:
        print("\n🎯 STATUS: ASSEMBLADOR FUNCIONANDO CORRETAMENTE")
    else:
        print("\n⚠️  STATUS: ASSEMBLADOR PRECISA DE MAIS CORREÇÕES")
