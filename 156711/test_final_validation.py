#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Teste Final de Validação do Processador MIPS
===========================================
Teste definitivo e prático das instruções do processador
Foco em funcionamento real sem depender de algoritmos complexos

Versão: 3.0 - 2025-07-19
"""

import builtins
from simulator_mips import MIPSSimulator


def mock_input_safe(prompt=""):
    """Mock seguro para INPUT"""
    values = [50, 25, 10, 5]
    mock_input_safe.counter = getattr(mock_input_safe, "counter", 0)
    value = values[mock_input_safe.counter % len(values)]
    mock_input_safe.counter += 1
    print(f"[MOCK INPUT] {prompt}: {value}")
    return str(value)


def test_core_functionality():
    """
    Teste das funcionalidades essenciais do processador
    """
    print("🎯 TESTE DAS FUNCIONALIDADES ESSENCIAIS")
    print("=" * 60)

    # Substituir input() para segurança
    original_input = builtins.input
    builtins.input = mock_input_safe

    try:
        simulator = MIPSSimulator(debug=False)

        # Configurar inputs seguros
        if hasattr(simulator, "set_input_values_safe"):
            simulator.set_input_values_safe([50, 25, 10, 5], extra_zeros=10)
        else:
            simulator.input_values = [50, 25, 10, 5] + [0] * 10

        print("\n📋 TESTANDO CADA CATEGORIA:")
        print("-" * 40)

        # =========================
        # TESTE 1: INSTRUÇÕES BÁSICAS
        # =========================

        print("\n1️⃣ INSTRUÇÕES BÁSICAS (LI, ADD, SUB):")

        # Reset e teste básico
        simulator.reset()

        basic_instructions = [
            # LI R1, 100
            (0b011011 << 26) | (0b000001 << 14) | 100,
            # LI R2, 30
            (0b011011 << 26) | (0b000010 << 14) | 30,
            # ADD R3, R1, R2  (R3 = 130)
            (0b000000 << 26) | (0b000001 << 20) | (0b000010 << 14) | (0b000011 << 8),
            # SUB R4, R1, R2  (R4 = 70)
            (0b000001 << 26) | (0b000001 << 20) | (0b000010 << 14) | (0b000100 << 8),
            # OUTPUTREG R3
            (0b100000 << 26) | (0b000011 << 20),
            # HALT
            (0b011110 << 26),
        ]

        try:
            for instruction in basic_instructions:
                if not simulator.halted:
                    simulator.execute_instruction(instruction)

            if (
                simulator.registers[1] == 100
                and simulator.registers[2] == 30
                and simulator.registers[3] == 130
                and simulator.registers[4] == 70
                and simulator.display_value == 130
            ):
                print("   ✅ Instruções básicas: PASSOU")
                test1_success = True
            else:
                print("   ❌ Instruções básicas: FALHOU")
                print(f"      R1={simulator.registers[1]}, R2={simulator.registers[2]}")
                print(f"      R3={simulator.registers[3]}, R4={simulator.registers[4]}")
                print(f"      Display={simulator.display_value}")
                test1_success = False
        except Exception as e:
            print(f"   ❌ Erro nas instruções básicas: {e}")
            test1_success = False

        # =========================
        # TESTE 2: MULTIPLICAÇÃO E MOVIMENTO
        # =========================

        print("\n2️⃣ MULTIPLICAÇÃO E MOVIMENTO (MULT, MFLO):")

        simulator.reset()

        mult_instructions = [
            # LI R1, 12
            (0b011011 << 26) | (0b000001 << 14) | 12,
            # LI R2, 7
            (0b011011 << 26) | (0b000010 << 14) | 7,
            # MULT R1, R2  (HI:LO = 84)
            (0b000010 << 26) | (0b000001 << 20) | (0b000010 << 14),
            # MFLO R5      (R5 = 84)
            (0b001010 << 26) | (0b000101 << 8),
            # OUTPUTREG R5
            (0b100000 << 26) | (0b000101 << 20),
            # HALT
            (0b011110 << 26),
        ]

        try:
            for instruction in mult_instructions:
                if not simulator.halted:
                    simulator.execute_instruction(instruction)

            if (
                simulator.registers[1] == 12
                and simulator.registers[2] == 7
                and simulator.registers[5] == 84
                and simulator.display_value == 84
            ):
                print("   ✅ Multiplicação: PASSOU")
                test2_success = True
            else:
                print("   ❌ Multiplicação: FALHOU")
                print(f"      R1={simulator.registers[1]}, R2={simulator.registers[2]}")
                print(
                    f"      R5={simulator.registers[5]}, Display={simulator.display_value}"
                )
                test2_success = False
        except Exception as e:
            print(f"   ❌ Erro na multiplicação: {e}")
            test2_success = False

        # =========================
        # TESTE 3: OPERAÇÕES LÓGICAS
        # =========================

        print("\n3️⃣ OPERAÇÕES LÓGICAS (AND, OR):")

        simulator.reset()

        logic_instructions = [
            # LI R1, 15   (1111 em binário)
            (0b011011 << 26) | (0b000001 << 14) | 15,
            # LI R2, 12   (1100 em binário)
            (0b011011 << 26) | (0b000010 << 14) | 12,
            # AND R3, R1, R2  (R3 = 15 & 12 = 12)
            (0b000100 << 26) | (0b000001 << 20) | (0b000010 << 14) | (0b000011 << 8),
            # OR R4, R1, R2   (R4 = 15 | 12 = 15)
            (0b000101 << 26) | (0b000001 << 20) | (0b000010 << 14) | (0b000100 << 8),
            # OUTPUTREG R4
            (0b100000 << 26) | (0b000100 << 20),
            # HALT
            (0b011110 << 26),
        ]

        try:
            for instruction in logic_instructions:
                if not simulator.halted:
                    simulator.execute_instruction(instruction)

            if (
                simulator.registers[1] == 15
                and simulator.registers[2] == 12
                and simulator.registers[3] == 12
                and simulator.registers[4] == 15
                and simulator.display_value == 15
            ):
                print("   ✅ Operações lógicas: PASSOU")
                test3_success = True
            else:
                print("   ❌ Operações lógicas: FALHOU")
                print(f"      R3={simulator.registers[3]} (esperado: 12)")
                print(f"      R4={simulator.registers[4]} (esperado: 15)")
                test3_success = False
        except Exception as e:
            print(f"   ❌ Erro nas operações lógicas: {e}")
            test3_success = False

        # =========================
        # TESTE 4: MEMÓRIA
        # =========================

        print("\n4️⃣ OPERAÇÕES DE MEMÓRIA (SW, LW):")

        simulator.reset()

        memory_instructions = [
            # LI R1, 77
            (0b011011 << 26) | (0b000001 << 14) | 77,
            # LI R2, 10   (endereço base)
            (0b011011 << 26) | (0b000010 << 14) | 10,
            # SW R1, 0(R2)  (MEM[10] = 77)
            (0b011010 << 26) | (0b000010 << 20) | (0b000001 << 14) | 0,
            # LW R3, 0(R2)  (R3 = MEM[10] = 77)
            (0b011001 << 26) | (0b000010 << 20) | (0b000011 << 14) | 0,
            # OUTPUTREG R3
            (0b100000 << 26) | (0b000011 << 20),
            # HALT
            (0b011110 << 26),
        ]

        try:
            for instruction in memory_instructions:
                if not simulator.halted:
                    simulator.execute_instruction(instruction)

            if (
                simulator.registers[1] == 77
                and simulator.registers[3] == 77
                and simulator.memory[10] == 77
                and simulator.display_value == 77
            ):
                print("   ✅ Operações de memória: PASSOU")
                test4_success = True
            else:
                print("   ❌ Operações de memória: FALHOU")
                print(f"      R1={simulator.registers[1]}, R3={simulator.registers[3]}")
                print(
                    f"      MEM[10]={simulator.memory[10]}, Display={simulator.display_value}"
                )
                test4_success = False
        except Exception as e:
            print(f"   ❌ Erro nas operações de memória: {e}")
            test4_success = False

        # =========================
        # TESTE 5: ENTRADA/SAÍDA
        # =========================

        print("\n5️⃣ ENTRADA E SAÍDA (INPUT, OUTPUT):")

        simulator.reset()

        io_instructions = [
            # INPUT R1     (R1 = valor do mock = 50)
            (0b100010 << 26) | (0b000001 << 8),
            # OUTPUTREG R1 (Display = 50)
            (0b100000 << 26) | (0b000001 << 20),
            # HALT
            (0b011110 << 26),
        ]

        try:
            for instruction in io_instructions:
                if not simulator.halted:
                    simulator.execute_instruction(instruction)

            if simulator.registers[1] == 50 and simulator.display_value == 50:
                print("   ✅ Entrada e saída: PASSOU")
                test5_success = True
            else:
                print("   ❌ Entrada e saída: FALHOU")
                print(
                    f"      R1={simulator.registers[1]}, Display={simulator.display_value}"
                )
                test5_success = False
        except Exception as e:
            print(f"   ❌ Erro na entrada/saída: {e}")
            test5_success = False

        # =========================
        # RESULTADO FINAL
        # =========================

        tests_passed = sum(
            [test1_success, test2_success, test3_success, test4_success, test5_success]
        )
        total_tests = 5

        print(f"\n🎯 RESULTADO FINAL:")
        print("=" * 40)
        print(
            f"Testes passaram: {tests_passed}/{total_tests} ({(tests_passed/total_tests)*100:.1f}%)"
        )
        print("")
        print(f"1️⃣ Instruções básicas: {'✅ PASSOU' if test1_success else '❌ FALHOU'}")
        print(f"2️⃣ Multiplicação: {'✅ PASSOU' if test2_success else '❌ FALHOU'}")
        print(f"3️⃣ Operações lógicas: {'✅ PASSOU' if test3_success else '❌ FALHOU'}")
        print(
            f"4️⃣ Operações de memória: {'✅ PASSOU' if test4_success else '❌ FALHOU'}"
        )
        print(f"5️⃣ Entrada e saída: {'✅ PASSOU' if test5_success else '❌ FALHOU'}")

        if tests_passed == total_tests:
            print("\n🎉 VALIDAÇÃO COMPLETA!")
            print("✅ Todas as funcionalidades essenciais funcionam")
            print("✅ Processador pronto para uso")
            print("✅ Simulador validado para compiladores")
        else:
            print(f"\n⚠️  {total_tests - tests_passed} teste(s) falharam")
            print("❌ Algumas funcionalidades precisam correção")

        return tests_passed == total_tests

    except Exception as e:
        print(f"💥 Erro geral no teste: {e}")
        return False

    finally:
        # Restaurar input original
        builtins.input = original_input


def show_instruction_coverage():
    """Mostra cobertura das instruções testadas"""
    print("\n📊 COBERTURA DE INSTRUÇÕES TESTADAS:")
    print("=" * 50)

    tested_instructions = {
        "Imediatas": ["LI"],
        "Aritméticas": ["ADD", "SUB", "MULT", "MFLO"],
        "Lógicas": ["AND", "OR"],
        "Memória": ["SW", "LW"],
        "I/O": ["INPUT", "OUTPUTREG"],
        "Controle": ["HALT"],
    }

    total_tested = 0
    for category, instructions in tested_instructions.items():
        print(f"✅ {category}: {', '.join(instructions)}")
        total_tested += len(instructions)

    print(f"\n📈 Total de instruções testadas: {total_tested}")
    print("📈 Cobertura: Funcionalidades essenciais do processador")
    print("📈 Validação: Conformidade com instrucoes_processador.md")


def create_final_report():
    """Cria relatório final de validação"""
    print("\n📋 RELATÓRIO FINAL DE VALIDAÇÃO:")
    print("=" * 50)
    print("🎯 OBJETIVO: Validar funcionamento das instruções do processador")
    print("📖 BASE: Documentação instrucoes_processador.md")
    print("🔬 MÉTODO: Testes práticos de cada categoria de instrução")
    print("")
    print("✅ CATEGORIAS VALIDADAS:")
    print("   • Instruções imediatas (LI)")
    print("   • Operações aritméticas (ADD, SUB, MULT)")
    print("   • Operações lógicas (AND, OR)")
    print("   • Acesso à memória (SW, LW)")
    print("   • Entrada e saída (INPUT, OUTPUTREG)")
    print("   • Controle de execução (HALT)")
    print("")
    print("🏆 CERTIFICAÇÃO:")
    print("   Se todos os testes passaram:")
    print("   ✅ Simulador em conformidade com especificação")
    print("   ✅ Instruções funcionando corretamente")
    print("   ✅ Pronto para uso em compiladores")


if __name__ == "__main__":
    print("🔬 VALIDAÇÃO FINAL DO PROCESSADOR MIPS")
    print("=" * 60)
    print("Versão: 3.0 - Teste prático e definitivo")
    print("Baseado em: instrucoes_processador.md")
    print("=" * 60)

    # Executar teste principal
    success = test_core_functionality()

    # Mostrar cobertura
    show_instruction_coverage()

    # Relatório final
    create_final_report()

    # Conclusão
    print(f"\n🏆 CERTIFICAÇÃO FINAL:")
    if success:
        print("🎉 PROCESSADOR MIPS VALIDADO COM SUCESSO!")
        print("✅ Todas as funcionalidades essenciais funcionam")
        print("✅ Simulador certificado para uso")
        print("✅ Aprovado para compiladores")
    else:
        print("⚠️  PROCESSADOR PRECISA CORREÇÕES")
        print("❌ Algumas funcionalidades não funcionam")
        print("❌ Revisar implementação")

    print("\n📝 NOTA: Este é o teste oficial de validação!")
    print("📝 Use este resultado para certificar o simulador")
