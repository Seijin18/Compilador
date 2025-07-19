#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def test_gcd():
    # Load corrected assembly
    with open("assembly_output.asm", "r", encoding="utf-8") as f:
        content = f.read()

    # Simple MIPS simulator
    registers = {
        "R0": 0,
        "R1": 0,
        "R2": 0,
        "R3": 0,
        "R4": 0,
        "R5": 0,
        "R29": 1000,
        "R31": 0,
    }
    memory = {}
    pc = 0
    hi_lo = {"HI": 0, "LO": 0}
    outputs = []

    # Parse instructions
    instructions = []
    for line in content.split("\n"):
        line = line.strip()
        if ":" in line and not line.startswith("#"):
            if line.endswith(":"):
                continue  # Skip labels
            parts = line.split(":", 1)
            if len(parts) == 2:
                try:
                    addr = int(parts[0].strip())
                    instr = parts[1].strip()
                    instructions.append((addr, instr))
                except:
                    continue

    # Set initial values: x=4, y=6
    memory[1000] = 4  # x (u)
    memory[1001] = 6  # y (v)

    max_steps = 100
    step = 0

    while step < max_steps:
        step += 1

        # Find instruction for current PC
        current_instr = None
        for addr, instr in instructions:
            if addr == pc:
                current_instr = instr
                break

        if not current_instr:
            print(f"No instruction at PC={pc}")
            break

        print(f"PC:{pc} | {current_instr}")

        # Parse instruction
        parts = current_instr.split()
        if not parts:
            pc += 1
            continue

        opcode = parts[0]

        if opcode == "J":
            pc = int(parts[1])
        elif opcode == "JAL":
            registers["R31"] = pc + 1
            pc = int(parts[1])
        elif opcode == "JR":
            pc = registers[parts[1]]
        elif opcode == "BNE":
            rs, rt, addr = parts[1].rstrip(","), parts[2].rstrip(","), int(parts[3])
            if registers[rs] != registers[rt]:
                pc = addr
            else:
                pc += 1
        elif opcode == "LW":
            reg = parts[1].rstrip(",")
            if "(" in parts[2]:
                offset, base = parts[2].split("(")
                base = base.rstrip(")")
                addr = registers[base] + int(offset)
                registers[reg] = memory.get(addr, 0)
            pc += 1
        elif opcode == "SW":
            reg = parts[1].rstrip(",")
            if "(" in parts[2]:
                offset, base = parts[2].split("(")
                base = base.rstrip(")")
                addr = registers[base] + int(offset)
                memory[addr] = registers[reg]
            pc += 1
        elif opcode == "DIV":
            rs, rt = parts[1].rstrip(","), parts[2]
            dividend, divisor = registers[rs], registers[rt]
            if divisor != 0:
                hi_lo["LO"] = dividend // divisor
                hi_lo["HI"] = dividend % divisor
            pc += 1
        elif opcode == "MFLO":
            registers[parts[1]] = hi_lo["LO"]
            pc += 1
        elif opcode == "MFHI":
            registers[parts[1]] = hi_lo["HI"]
            pc += 1
        elif opcode == "MULT":
            rs, rt = parts[1].rstrip(","), parts[2]
            result = registers[rs] * registers[rt]
            hi_lo["LO"] = result & 0xFFFFFFFF
            hi_lo["HI"] = (result >> 32) & 0xFFFFFFFF
            pc += 1
        elif opcode == "SUB":
            rd, rs, rt = parts[1].rstrip(","), parts[2].rstrip(","), parts[3]
            registers[rd] = registers[rs] - registers[rt]
            pc += 1
        elif opcode == "MOVE":
            rd, rs = parts[1].rstrip(","), parts[2]
            registers[rd] = registers[rs]
            pc += 1
        elif opcode == "INPUT":
            reg = parts[1]
            if reg == "R7":
                registers[reg] = 4
            elif reg == "R8":
                registers[reg] = 6
            pc += 1
        elif opcode == "OUTPUTREG":
            reg = parts[1]
            output_val = registers[reg]
            outputs.append(output_val)
            print(f"OUTPUT: {output_val}")
            pc += 1
        else:
            pc += 1

        # Show key register values
        print(
            f"  u={memory.get(1000, '?')}, v={memory.get(1001, '?')}, R1={registers['R1']}"
        )

        if opcode == "OUTPUTREG":
            break

    print(f"\nResultado: {outputs}")
    print(f"Esperado: [2] para GCD(4,6)")
    if outputs == [2]:
        print("SUCESSO!")
    else:
        print("FALHA!")


if __name__ == "__main__":
    test_gcd()
