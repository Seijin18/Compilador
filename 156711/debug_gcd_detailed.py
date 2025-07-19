#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Debug detalhado da execução do GCD
"""

from simulator_mips import MIPSSimulator


def debug_gcd_execution():
    print("=== DEBUG DETALHADO DO GCD ===")

    simulator = MIPSSimulator(debug=True)
    simulator.input_values = [4, 6]

    instructions = simulator.load_binary_file("binary_output.txt")

    # Executar até chegar na função GCD
    cycle = 0
    while not simulator.halted and simulator.pc != 1 and cycle < 50:
        if simulator.pc < len(instructions):
            simulator.execute_instruction(instructions[simulator.pc])
        cycle += 1

    print(f"Chegou na função GCD (PC={simulator.pc})")
    print(f"Estado da memória antes do GCD:")
    print(f"  MEM[0] = {simulator.memory[0]} (primeiro parâmetro)")
    print(f"  MEM[1] = {simulator.memory[1]} (segundo parâmetro)")
    print(f"Estado dos registradores:")
    print(f"  R0 = {simulator.registers[0]} (sempre zero)")
    print(f"  R1 = {simulator.registers[1]}")
    print(f"  R2 = {simulator.registers[2]}")

    # Executar as próximas instruções uma por uma
    for i in range(5):
        if simulator.halted or simulator.pc >= len(instructions):
            break

        pc_before = simulator.pc
        instruction = instructions[simulator.pc]
        decoded = simulator.decode_instruction(instruction)
        mnemonic = simulator.opcodes.get(decoded["opcode"], "UNKNOWN")

        print(f"\n--- Passo {i+1} ---")
        print(f"PC antes: {pc_before}")
        print(f"Instrução: {mnemonic}")
        print(
            f"Detalhes: opcode={decoded['opcode']}, rs={decoded['rs']}, rt={decoded['rt']}, imm={decoded['immediate']}"
        )

        if mnemonic == "LW":
            addr = simulator.registers[decoded["rs"]] + decoded["immediate"]
            print(
                f"  Carregando MEM[{addr}] = {simulator.memory[addr & 0xFF]} para R{decoded['rt']}"
            )
        elif mnemonic == "BEQ":
            rs_val = simulator.registers[decoded["rs"]]
            rt_val = simulator.registers[decoded["rt"]]
            print(
                f"  Comparando R{decoded['rs']}({rs_val}) == R{decoded['rt']}({rt_val})"
            )
            will_branch = rs_val == rt_val
            print(f"  Branch será {'TOMADO' if will_branch else 'NÃO TOMADO'}")
            if will_branch:
                target = simulator.pc + 1 + decoded["immediate"]
                print(f"  Saltará para PC = {target}")

        simulator.execute_instruction(instruction)

        print(f"PC depois: {simulator.pc}")
        print(f"R1 = {simulator.registers[1]}, R2 = {simulator.registers[2]}")

        if mnemonic == "JR":
            break


if __name__ == "__main__":
    debug_gcd_execution()
