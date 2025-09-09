#!/usr/bin/env python3
"""
Script de teste para validar o simulador MIPS genérico
Testa diferentes tipos de algoritmos e operações
"""

from mips_simulator import MIPSSimulator
import tempfile
import os


def create_test_assembly(instructions, filename=None):
    """Cria um arquivo assembly temporário para teste"""
    if filename is None:
        fd, filename = tempfile.mkstemp(suffix=".asm", text=True)
        os.close(fd)

    with open(filename, "w") as f:
        for i, instr in enumerate(instructions):
            f.write(f"{i}: {instr}\n")

    return filename


def test_basic_arithmetic():
    """Testa operações aritméticas básicas"""
    print("🧪 Teste 1: Operações Aritméticas Básicas")

    # Programa: a = input(), b = input(), output(a+b), output(a-b), output(a*b), output(a/b)
    instructions = [
        "INPUT R1",  # a = input()
        "INPUT R2",  # b = input()
        "ADD R3, R1, R2",  # R3 = a + b
        "OUTPUTREG R3",  # output(a + b)
        "SUB R4, R1, R2",  # R4 = a - b
        "OUTPUTREG R4",  # output(a - b)
        "MULT R1, R2",  # HI:LO = a * b
        "MFLO R5",  # R5 = LO (resultado multiplicação)
        "OUTPUTREG R5",  # output(a * b)
        "DIV R1, R2",  # HI = a/b, LO = a%b
        "MFHI R6",  # R6 = HI (quociente)
        "OUTPUTREG R6",  # output(a / b)
        "HALT",
    ]

    test_file = create_test_assembly(instructions)

    try:
        simulator = MIPSSimulator(input_values=[20, 4])  # 20, 4
        simulator.load_assembly(test_file)
        simulator.run()

        outputs = simulator.get_output_values()
        expected = [24, 16, 80, 5]  # 20+4, 20-4, 20*4, 20/4

        if outputs == expected:
            print(f"   ✅ PASSOU: {outputs}")
            return True
        else:
            print(f"   ❌ FALHOU: Esperado {expected}, Obtido {outputs}")
            return False

    except Exception as e:
        print(f"   ❌ ERRO: {e}")
        return False
    finally:
        os.unlink(test_file)


def test_conditional_logic():
    """Testa lógica condicional (if-else)"""
    print("🧪 Teste 2: Lógica Condicional")

    # Programa: a = input(), b = input(), if (a > b) output(1) else output(0)
    instructions = [
        "INPUT R1",  # a = input()
        "INPUT R2",  # b = input()
        "BGT R1, R2, 5",  # if (a > b) goto linha 5
        "LI R3, 0",  # R3 = 0 (a <= b)
        "J 6",  # goto linha 6
        "LI R3, 1",  # R3 = 1 (a > b)
        "OUTPUTREG R3",  # output(resultado)
        "HALT",
    ]

    test_file = create_test_assembly(instructions)

    try:
        # Teste 1: 15 > 10 = true (1)
        simulator = MIPSSimulator(input_values=[15, 10])
        simulator.load_assembly(test_file)
        simulator.run()
        result1 = simulator.get_last_output()

        # Teste 2: 5 > 10 = false (0)
        simulator.reset()
        simulator.set_input_values([5, 10])
        simulator.load_assembly(test_file)
        simulator.run()
        result2 = simulator.get_last_output()

        if result1 == 1 and result2 == 0:
            print(f"   ✅ PASSOU: 15>10={result1}, 5>10={result2}")
            return True
        else:
            print(f"   ❌ FALHOU: 15>10={result1}, 5>10={result2}")
            return False

    except Exception as e:
        print(f"   ❌ ERRO: {e}")
        return False
    finally:
        os.unlink(test_file)


def test_loop_structure():
    """Testa estruturas de repetição"""
    print("🧪 Teste 3: Estruturas de Repetição")

    # Programa: soma = 0; for(i=1; i<=5; i++) soma += i; output(soma)
    instructions = [
        "LI R1, 0",  # soma = 0
        "LI R2, 1",  # i = 1
        "LI R3, 5",  # limite = 5
        "BGT R2, R3, 6",  # while (i <= 5) - loop: if (i > 5) goto fim
        "ADD R1, R1, R2",  # soma = soma + i
        "ADDI R2, R2, 1",  # i = i + 1
        "J 3",  # goto loop
        "OUTPUTREG R1",  # output(soma)
        "HALT",
    ]

    test_file = create_test_assembly(instructions)

    try:
        simulator = MIPSSimulator(input_values=[])
        simulator.load_assembly(test_file)
        simulator.run()

        result = simulator.get_last_output()
        expected = 15  # 1+2+3+4+5 = 15

        if result == expected:
            print(f"   ✅ PASSOU: Soma 1-5 = {result}")
            return True
        else:
            print(f"   ❌ FALHOU: Esperado {expected}, Obtido {result}")
            return False

    except Exception as e:
        print(f"   ❌ ERRO: {e}")
        return False
    finally:
        os.unlink(test_file)


def test_function_simulation():
    """Testa simulação de chamada de função (max function)"""
    print("🧪 Teste 4: Simulação de Função")

    # Programa: a = input(), b = input(), output(max(a,b))
    instructions = [
        "INPUT R1",  # a = input()
        "INPUT R2",  # b = input()
        "JAL 5",  # call max(R1, R2) - função na linha 5
        "OUTPUTREG R3",  # output(resultado)
        "HALT",
        # Função max(a, b):
        "BGT R1, R2, 8",  # if (a > b) goto retorna_a
        "MOVE R3, R2",  # return b
        "JR 31",  # return (jump to RA)
        "MOVE R3, R1",  # return a
        "JR 31",  # return
    ]

    test_file = create_test_assembly(instructions)

    try:
        # Teste 1: max(25, 10) = 25
        simulator = MIPSSimulator(input_values=[25, 10])
        simulator.load_assembly(test_file)
        simulator.run()
        result1 = simulator.get_last_output()

        # Teste 2: max(7, 18) = 18
        simulator.reset()
        simulator.set_input_values([7, 18])
        simulator.load_assembly(test_file)
        simulator.run()
        result2 = simulator.get_last_output()

        if result1 == 25 and result2 == 18:
            print(f"   ✅ PASSOU: max(25,10)={result1}, max(7,18)={result2}")
            return True
        else:
            print(f"   ❌ FALHOU: max(25,10)={result1}, max(7,18)={result2}")
            return False

    except Exception as e:
        print(f"   ❌ ERRO: {e}")
        return False
    finally:
        os.unlink(test_file)


def test_memory_operations():
    """Testa operações de memória"""
    print("🧪 Teste 5: Operações de Memória")

    # Programa: armazenar valor na memória e recuperar
    instructions = [
        "INPUT R1",  # valor = input()
        "LI R2, 100",  # endereço = 100
        "SW R1, 0(R2)",  # MEM[100] = valor
        "LI R3, 0",  # R3 = 0 (limpar)
        "LW R3, 0(R2)",  # R3 = MEM[100]
        "OUTPUTREG R3",  # output(valor recuperado)
        "HALT",
    ]

    test_file = create_test_assembly(instructions)

    try:
        simulator = MIPSSimulator(input_values=[42])
        simulator.load_assembly(test_file)
        simulator.run()

        result = simulator.get_last_output()
        expected = 42

        if result == expected:
            print(f"   ✅ PASSOU: Memória store/load = {result}")
            return True
        else:
            print(f"   ❌ FALHOU: Esperado {expected}, Obtido {result}")
            return False

    except Exception as e:
        print(f"   ❌ ERRO: {e}")
        return False
    finally:
        os.unlink(test_file)


def test_multiple_outputs():
    """Testa programa com múltiplas saídas"""
    print("🧪 Teste 6: Múltiplas Saídas")

    # Programa: output os quadrados de 1 a 4
    instructions = [
        "LI R1, 1",  # i = 1
        "LI R2, 4",  # limite = 4
        "BGT R1, R2, 7",  # while (i <= 4)
        "MULT R1, R1",  # HI:LO = i * i
        "MFLO R3",  # R3 = i²
        "OUTPUTREG R3",  # output(i²)
        "ADDI R1, R1, 1",  # i++
        "J 2",  # loop
        "HALT",
    ]

    test_file = create_test_assembly(instructions)

    try:
        simulator = MIPSSimulator(input_values=[])
        simulator.load_assembly(test_file)
        simulator.run()

        outputs = simulator.get_output_values()
        expected = [1, 4, 9, 16]  # 1², 2², 3², 4²

        if outputs == expected:
            print(f"   ✅ PASSOU: Quadrados = {outputs}")
            return True
        else:
            print(f"   ❌ FALHOU: Esperado {expected}, Obtido {outputs}")
            return False

    except Exception as e:
        print(f"   ❌ ERRO: {e}")
        return False
    finally:
        os.unlink(test_file)


def run_all_tests():
    """Executa todos os testes"""
    print("🚀 INICIANDO BATERIA DE TESTES DO SIMULADOR MIPS GENÉRICO")
    print("=" * 60)

    tests = [
        test_basic_arithmetic,
        test_conditional_logic,
        test_loop_structure,
        test_function_simulation,
        test_memory_operations,
        test_multiple_outputs,
    ]

    passed = 0
    total = len(tests)

    for test in tests:
        try:
            if test():
                passed += 1
            print()
        except Exception as e:
            print(f"   ❌ ERRO FATAL: {e}\n")

    print("=" * 60)
    print(f"📊 RESULTADO FINAL: {passed}/{total} testes passaram")

    if passed == total:
        print("🎉 TODOS OS TESTES PASSARAM! Simulador funcionando corretamente.")
    else:
        print(f"⚠️  {total - passed} teste(s) falharam. Verificar implementação.")

    return passed == total


if __name__ == "__main__":
    success = run_all_tests()
    exit(0 if success else 1)
