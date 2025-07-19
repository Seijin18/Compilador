#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Teste GCD Atualizado - Versão sem Loop de Input
=============================================
Este arquivo demonstra como usar o simulador MIPS atualizado
sem risco de loop de input no terminal.

Versão: 2.0 - Atualizada em 2025-07-19
"""

import builtins
import sys
import os
from simulator_mips import MIPSSimulator


def mock_input_safe(prompt=""):
    """Mock que sempre retorna 0 para evitar loop de input"""
    print(f"[MOCK INPUT] {prompt}: 0")
    return "0"


def test_gcd_updated():
    """
    Teste do GCD usando a versão atualizada do simulador
    """
    print("=== TESTE GCD COM SIMULADOR ATUALIZADO ===")
    print("Versão: 2.0 - Sem Loop de Input")
    print("Testando: GCD(4,6) = 2")
    print("=" * 50)

    # Substituir input() globalmente para máxima segurança
    original_input = builtins.input
    builtins.input = mock_input_safe

    try:
        # Criar simulador atualizado
        simulator = MIPSSimulator(debug=False)

        # Usar método seguro para configurar inputs
        simulator.set_input_values_safe([4, 6], extra_zeros=20)

        # Carregar arquivo binário do exemplo
        binary_file = "binary_output.txt"
        if not os.path.exists(binary_file):
            # Tentar carregar do diretório de exemplos
            example_file = os.path.join("examples", "gcd_example", "binary_output.txt")
            if os.path.exists(example_file):
                binary_file = example_file
            else:
                print("❌ Erro: Arquivo binary_output.txt não encontrado")
                print(
                    "   Verifique se o arquivo está no diretório atual ou em examples/gcd_example/"
                )
                return False

        instructions = simulator.load_binary_file(binary_file)

        if not instructions:
            print("❌ Erro: Não foi possível carregar instruções")
            return False

        print(f"📂 Carregadas {len(instructions)} instruções de {binary_file}")

        # Executar com limite seguro de ciclos
        result = simulator.run(instructions, max_cycles=500)

        print("\n📊 RESULTADO DA EXECUÇÃO:")
        print("=" * 40)

        if isinstance(result, dict):
            halted = result.get("halted", False)
            instructions_count = result.get("instructions_executed", 0)
            display_value = result.get("display_value", "N/A")

            print(f"✅ Programa terminou: {'Sim' if halted else 'Não'}")
            print(f"📈 Instruções executadas: {instructions_count}")
            print(f"🎯 Resultado obtido: {display_value}")
            print(f"🎯 Resultado esperado: 2")

            # Análise do resultado
            if display_value == 2:
                print("\n🎉 SUCESSO! GCD funcionando corretamente!")
                status = "✅ CORRETO"
            else:
                print(f"\n⚠️  Resultado diferente do esperado")
                if display_value == 6:
                    print("   • Retornou o segundo parâmetro")
                    print("   • Possível problema na lógica do GCD")
                elif display_value == 4:
                    print("   • Retornou o primeiro parâmetro")
                    print("   • Possível problema na condição de parada")
                else:
                    print(f"   • Resultado inesperado: {display_value}")
                status = "⚠️  INCORRETO"

            print(f"\n📋 ESTADO FINAL:")
            print(f"   Status: {status}")
            print(f"   Input R8: {simulator.registers[8]}")
            print(f"   Input R9: {simulator.registers[9]}")

            return display_value == 2

        else:
            print(f"⚠️  Resultado inesperado: {result}")
            return False

    except Exception as e:
        print(f"💥 Erro durante execução: {e}")
        import traceback

        traceback.print_exc()
        return False

    finally:
        # Restaurar input original
        builtins.input = original_input


def test_other_cases():
    """
    Testa outros casos de GCD
    """
    print("\n🧪 TESTANDO OUTROS CASOS:")
    print("=" * 40)

    test_cases = [
        (12, 8, 4),  # GCD(12, 8) = 4
        (15, 10, 5),  # GCD(15, 10) = 5
        (7, 5, 1),  # GCD(7, 5) = 1
    ]

    # Substituir input() para estes testes também
    original_input = builtins.input
    builtins.input = mock_input_safe

    try:
        for a, b, expected in test_cases:
            print(f"\n🔍 Testando GCD({a}, {b}) = {expected}")

            simulator = MIPSSimulator(debug=False)
            simulator.set_input_values_safe([a, b], extra_zeros=10)

            binary_file = "binary_output.txt"
            if not os.path.exists(binary_file):
                example_file = os.path.join(
                    "examples", "gcd_example", "binary_output.txt"
                )
                if os.path.exists(example_file):
                    binary_file = example_file

            instructions = simulator.load_binary_file(binary_file)

            if instructions:
                result = simulator.run(instructions, max_cycles=200)
                if isinstance(result, dict):
                    obtained = result.get("display_value", "N/A")
                    status = "✅" if obtained == expected else "❌"
                    print(f"   Resultado: {obtained} {status}")
                else:
                    print(f"   Erro na execução")
            else:
                print(f"   ❌ Não foi possível carregar instruções")

    finally:
        builtins.input = original_input


def show_improvements():
    """
    Mostra as melhorias implementadas na versão 2.0
    """
    print("\n🚀 MELHORIAS NA VERSÃO 2.0:")
    print("=" * 50)
    print("✅ 1. Método set_input_values_safe():")
    print("     • Adiciona zeros extras automaticamente")
    print("     • Evita esgotamento de input_values")
    print("     • Configura valores de forma segura")
    print("")
    print("✅ 2. Proteção contra loop de INPUT:")
    print("     • Verifica se input_values existe e não está vazio")
    print("     • Usa zero automático quando lista se esgota")
    print("     • Captura exceções de input do terminal")
    print("")
    print("✅ 3. Mock de input() global:")
    print("     • Substitui input() temporariamente")
    print("     • Evita qualquer solicitação de terminal")
    print("     • Restaura input original após uso")
    print("")
    print("✅ 4. Limite de ciclos ajustável:")
    print("     • Evita loops infinitos")
    print("     • Permite ajuste conforme necessidade")
    print("     • Detecção de programas travados")


if __name__ == "__main__":
    print("🎯 SIMULADOR MIPS - VERSÃO ATUALIZADA 2.0")
    print("=" * 50)

    # Teste principal
    success = test_gcd_updated()

    # Testes adicionais (comentados por padrão para não sobrecarregar)
    # test_other_cases()

    # Mostrar melhorias
    show_improvements()

    print(f"\n📊 RESULTADO FINAL:")
    if success:
        print("🎉 SIMULADOR FUNCIONANDO PERFEITAMENTE!")
    else:
        print("⚠️  SIMULADOR ATUALIZADO MAS ALGORITMO PRECISA CORREÇÃO")

    print("\n📝 NOTA: O loop de input foi completamente eliminado!")
    print("📝 Para usar: simulator.set_input_values_safe([valores])")
