#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Debug simplificado para GCD(4,6)
Vamos rastrear o problema passo a passo
"""

import sys
from simulator_mips import MIPSSimulator


class SimpleGCDDebugger(MIPSSimulator):
    def __init__(self):
        super().__init__(debug=False)
        self.call_depth = 0
        self.max_iterations = 50  # Limite baixo para debug

    def execute_instruction(self, instruction: int) -> bool:
        decoded = self.decode_instruction(instruction)
        opcode = decoded["opcode"]
        mnemonic = self.opcodes.get(opcode, "UNKNOWN")

        # Log crítico das instruções importantes
        if mnemonic in ["JAL", "JR", "BNE", "LW", "SW"]:
            if mnemonic == "JAL":
                self.call_depth += 1
                print(
                    f"[{self.instruction_count:4d}] {'  ' * self.call_depth}CALL: PC={self.pc} -> {decoded['immediate']}"
                )

            elif mnemonic == "JR" and decoded["rs"] == 31:  # Return
                print(
                    f"[{self.instruction_count:4d}] {'  ' * self.call_depth}RETURN: PC={self.pc} from R31={self.registers[31]}"
                )
                self.call_depth = max(0, self.call_depth - 1)

            elif mnemonic == "BNE":
                r1_val = self.registers[decoded["rs"]]
                r2_val = self.registers[decoded["rt"]]
                will_branch = r1_val != r2_val
                print(
                    f"[{self.instruction_count:4d}] {'  ' * self.call_depth}BNE: R{decoded['rs']}({r1_val}) != R{decoded['rt']}({r2_val}) = {will_branch}"
                )

            elif mnemonic in ["LW", "SW"]:
                addr = (self.registers[decoded["rs"]] + decoded["immediate"]) & 0xFF
                if mnemonic == "LW":
                    val = self.memory[addr] if addr < len(self.memory) else 0
                    print(
                        f"[{self.instruction_count:4d}] {'  ' * self.call_depth}LW: R{decoded['rt']} = MEM[{addr}] = {val}"
                    )
                else:  # SW
                    val = self.registers[decoded["rt"]]
                    print(
                        f"[{self.instruction_count:4d}] {'  ' * self.call_depth}SW: MEM[{addr}] = R{decoded['rt']} = {val}"
                    )

        # Parar se ultrapassar limite
        if self.instruction_count >= self.max_iterations:
            print(f"\n*** LIMITE DE {self.max_iterations} INSTRUÇÕES ATINGIDO ***")
            return False

        # Executa normalmente
        return super().execute_instruction(instruction)


def main():
    print("Debug Simplificado GCD(4,6)")
    print("=" * 50)

    debugger = SimpleGCDDebugger()
    instructions = debugger.load_binary_file("binary_output.txt")

    if not instructions:
        print("Erro: Não foi possível carregar as instruções")
        return

    # Executa com valores 4 e 6
    debugger.input_values = [4, 6]
    summary = debugger.run(instructions, max_cycles=100)  # Limite baixo

    print("\n" + "=" * 50)
    print("ANÁLISE DOS RESULTADOS:")
    print(f"Instruções executadas: {summary['instructions_executed']}")
    print(f"PC final: {summary['final_pc']}")
    print(f"Halted: {summary['halted']}")

    print("\nRegistradores importantes:")
    print(f"R10 (primeiro param): {summary['registers'][10]}")
    print(f"R11 (segundo param): {summary['registers'][11]}")
    print(f"R29 (Stack Pointer): {summary['registers'][29]}")
    print(f"R31 (Return Address): {summary['registers'][31]}")

    print("\nMemória relevante:")
    for i in range(10):
        if summary["memory"] and i < len(summary["memory"]):
            print(f"MEM[{i}]: {debugger.memory[i]}")


if __name__ == "__main__":
    main()
