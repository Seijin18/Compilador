#!/usr/bin/env python3
"""
Comprehensive verification of all MIPS instruction encodings
"""


def decode_instruction(binary):
    """Decode a 32-bit binary instruction into fields"""
    if len(binary) != 32:
        return None

    # Convert binary string to integer
    instruction = int(binary, 2)

    # Extract fields according to format: [31:26] OPCODE | [25:20] RS | [19:14] RT | [13:8] RD | [7:0] IMMEDIATE
    opcode = (instruction >> 26) & 0x3F
    rs = (instruction >> 20) & 0x3F
    rt = (instruction >> 14) & 0x3F
    rd = (instruction >> 8) & 0x3F
    immediate = instruction & 0xFF

    return {
        "opcode": opcode,
        "rs": rs,
        "rt": rt,
        "rd": rd,
        "immediate": immediate,
        "instruction": instruction,
    }


def get_opcode_name(opcode):
    """Get instruction name from opcode"""
    opcodes = {
        0x00: "ADD",
        0x01: "SUB",
        0x02: "MULT",
        0x03: "DIV",
        0x04: "AND",
        0x05: "OR",
        0x06: "XOR",
        0x07: "NOT",
        0x08: "SLT",
        0x09: "MFHI",
        0x0A: "MFLO",
        0x0B: "MOVE",
        0x0C: "JR",
        0x0D: "NOP",
        0x0E: "ADDI",
        0x0F: "SUBI",
        0x10: "SLTI",
        0x11: "ANDI",
        0x12: "ORI",
        0x13: "BEQ",
        0x14: "BNE",
        0x15: "BGT",
        0x16: "BGTE",
        0x17: "BLT",
        0x18: "BLTE",
        0x19: "LW",
        0x1A: "SW",
        0x1B: "LI",
        0x1C: "J",
        0x1D: "JAL",
        0x1E: "HALT",
        0x1F: "OUTPUTMEM",
        0x20: "OUTPUTREG",
        0x21: "OUTPUT_RESET",
        0x22: "INPUT",
    }
    return opcodes.get(opcode, f"UNKNOWN(0x{opcode:02X})")


def validate_instruction(decoded, line_num):
    """Validate instruction encoding based on processor specification"""
    errors = []
    opcode = decoded["opcode"]
    rs = decoded["rs"]
    rt = decoded["rt"]
    rd = decoded["rd"]
    immediate = decoded["immediate"]
    inst_name = get_opcode_name(opcode)

    # Validation rules based on processor documentation
    if inst_name == "LI":
        # LI RT, IMEDIATO - uses RT as destination, RS and RD should be 0
        if rs != 0:
            errors.append(f"LI deve ter RS=0, atual RS={rs}")
        if rd != 0:
            errors.append(f"LI deve ter RD=0, atual RD={rd}")

    elif inst_name == "MOVE":
        # MOVE RD, RS - uses RD as destination, RT should be 0
        if rt != 0:
            errors.append(f"MOVE deve ter RT=0, atual RT={rt}")

    elif inst_name in ["LW", "SW"]:
        # Memory instructions: LW RT, OFFSET(RS) / SW RT, OFFSET(RS)
        # Uses RT as data register, RD should be 0
        if rd != 0:
            errors.append(f"{inst_name} deve ter RD=0, atual RD={rd}")

    elif inst_name in ["BEQ", "BNE", "BGT", "BGTE", "BLT", "BLTE"]:
        # Branch instructions use RS and RT for comparison, RD should be 0
        if rd != 0:
            errors.append(f"{inst_name} deve ter RD=0, atual RD={rd}")

    elif inst_name in ["J", "JAL"]:
        # Jump instructions use immediate as address, RS/RT/RD should be 0
        if rs != 0 or rt != 0 or rd != 0:
            errors.append(f"{inst_name} deve ter RS=RT=RD=0")

    elif inst_name == "JR":
        # Jump register uses RS, RT/RD should be 0
        if rt != 0 or rd != 0:
            errors.append(f"JR deve ter RT=RD=0, atual RT={rt}, RD={rd}")

    elif inst_name in ["INPUT"]:
        # INPUT RD - writes to RD, RS/RT should be 0
        if rs != 0 or rt != 0:
            errors.append(f"INPUT deve ter RS=RT=0, atual RS={rs}, RT={rt}")

    elif inst_name in ["MFHI", "MFLO"]:
        # MFHI/MFLO RD - writes to RD, RS/RT should be 0
        if rs != 0 or rt != 0:
            errors.append(f"{inst_name} deve ter RS=RT=0, atual RS={rs}, RT={rt}")

    elif inst_name in ["OUTPUTREG"]:
        # OUTPUTREG RS - reads from RS, RT/RD should be 0
        if rt != 0 or rd != 0:
            errors.append(f"OUTPUTREG deve ter RT=RD=0, atual RT={rt}, RD={rd}")

    elif inst_name in ["ADD", "SUB", "AND", "OR", "SLT"]:
        # Three-register operations: OP RD, RS, RT
        pass  # All fields used

    elif inst_name in ["MULT", "DIV"]:
        # Two-register operations: OP RS, RT (result in HI/LO)
        if rd != 0:
            errors.append(f"{inst_name} deve ter RD=0, atual RD={rd}")

    elif inst_name in ["ADDI", "SUBI", "ANDI", "ORI"]:
        # Immediate operations: OP RT, RS, IMEDIATO
        if rd != 0:
            errors.append(f"{inst_name} deve ter RD=0, atual RD={rd}")

    return errors


def main():
    try:
        with open("binary_output.txt", "r") as f:
            binary_lines = [line.strip() for line in f.readlines() if line.strip()]

        print("VERIFICAÇÃO COMPLETA DE INSTRUÇÕES")
        print("=" * 60)

        total_errors = 0
        total_instructions = len(binary_lines)

        for i, binary in enumerate(binary_lines):
            decoded = decode_instruction(binary)
            if not decoded:
                print(f"Linha {i:2d}: ERRO - Instrução inválida: {binary}")
                total_errors += 1
                continue

            inst_name = get_opcode_name(decoded["opcode"])
            errors = validate_instruction(decoded, i)

            if errors:
                print(f"Linha {i:2d}: {inst_name:12s} | ❌ ERROS: {len(errors)}")
                for error in errors:
                    print(f"         {error}")
                total_errors += len(errors)
            else:
                print(f"Linha {i:2d}: {inst_name:12s} | ✅ OK")

        print("=" * 60)
        print(f"INSTRUÇÕES ANALISADAS: {total_instructions}")
        print(f"TOTAL DE ERROS: {total_errors}")

        if total_errors == 0:
            print("🎉 SUCESSO: Todas as instruções estão codificadas corretamente!")
        else:
            print(f"❌ FALHA: {total_errors} erro(s) encontrado(s)")

    except FileNotFoundError:
        print("Erro: Arquivo binary_output.txt não encontrado")
    except Exception as e:
        print(f"Erro inesperado: {e}")


if __name__ == "__main__":
    main()
