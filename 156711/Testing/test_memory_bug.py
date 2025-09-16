#!/usr/bin/env python3
"""
Teste isolado do bug do simulador MIPS
"""

import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from mips_simulator import MIPSSimulator


def test_memory_issue():
    print("=== TESTE ISOLADO DE MEMÓRIA ===")

    # Criar simulador
    sim = MIPSSimulator()

    # Simular as operações do teste
    print("1. Configurando GP = 148")
    sim.registers[28] = 148  # GP

    print("2. Armazenando valor 300 em MEM[156]")
    sim.memory[156] = 300
    print(f"   MEM[156] = {sim.memory[156]}")

    print("3. Lendo valor de MEM[156]")
    value = sim.memory[156]
    print(f"   MEM[156] = {value}")

    if value == 300:
        print("✓ Memória funciona corretamente")
    else:
        print(f"❌ ERRO: Esperado 300, obtido {value}")

    # Testar com instrução LW
    print("\n4. Testando instrução LW simulada")
    rs = 28  # GP
    offset = 8  # Para calcular endereço 148 + 8 = 156
    address = (sim.registers[rs] + offset) & 0xFF
    print(f"   Endereço calculado: {sim.registers[rs]} + {offset} = {address}")

    if address == 156:
        print("✓ Cálculo de endereço correto")
        sim.registers[3] = sim.memory[address]
        print(f"   R3 = MEM[{address}] = {sim.registers[3]}")

        if sim.registers[3] == 300:
            print("✓ Instrução LW funcionando corretamente")
        else:
            print(f"❌ ERRO LW: Esperado 300, obtido {sim.registers[3]}")
    else:
        print(f"❌ ERRO: Endereço incorreto: {address}")


if __name__ == "__main__":
    test_memory_issue()
