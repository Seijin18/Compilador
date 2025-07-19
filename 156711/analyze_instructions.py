#!/usr/bin/env python3
# Script para verificar correspondência das instruções com a documentação


def analyze_instruction(binary, assembly, line_num):
    """Analisa uma instrução binária comparando com a documentação"""

    # Extrair campos
    opcode = binary[:6]
    rs = binary[6:12]
    rt = binary[12:18]
    rd = binary[18:24]
    immediate = binary[24:32]

    # Converter para decimal
    opcode_dec = int(opcode, 2)
    rs_dec = int(rs, 2)
    rt_dec = int(rt, 2)
    rd_dec = int(rd, 2)
    immediate_dec = int(immediate, 2)

    errors = []

    # Mapear opcodes para nomes
    opcodes = {
        0x00: "ADD",
        0x01: "SUB",
        0x02: "MULT",
        0x03: "DIV",
        0x04: "AND",
        0x05: "OR",
        0x06: "SLL",
        0x07: "SRL",
        0x08: "SLT",
        0x09: "MFHI",
        0x0A: "MFLO",
        0x0B: "MOVE",
        0x0C: "JR",
        0x0D: "JALR",
        0x0E: "LA",
        0x0F: "ADDI",
        0x10: "SUBI",
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

    expected_inst = opcodes.get(opcode_dec, "UNKNOWN")
    actual_inst = assembly.split()[0] if assembly else "UNKNOWN"

    print(f"Linha {line_num:2d}: {assembly:25s} | {binary}")
    print(f"         Opcode: {opcode} ({opcode_dec:02X}) = {expected_inst}")
    print(
        f"         RS: {rs} (R{rs_dec}) | RT: {rt} (R{rt_dec}) | RD: {rd} (R{rd_dec}) | IMM: {immediate} ({immediate_dec})"
    )

    # Verificações específicas por instrução
    if expected_inst != actual_inst:
        errors.append(f"Opcode mismatch: expected {expected_inst}, got {actual_inst}")

    # Verificações específicas por tipo de instrução
    if expected_inst == "LI":
        # Para este processador customizado: LI RD, IMEDIATO - usa RD como destino
        if rt_dec != 0:
            errors.append(f"LI deve ter RT=0, atual RT={rt_dec}")
        # RD deve conter o registrador de destino (não zero)
        # O valor imediato é carregado no registrador RD

    elif expected_inst == "MOVE":
        # MOVE RD, RS - deve usar RD como destino, RS como fonte
        if rt_dec != 0:
            errors.append(f"MOVE deve ter RT=0, atual RT={rt_dec}")

    elif expected_inst == "INPUT":
        # INPUT RD - deve usar RD como destino
        if rs_dec != 0 or rt_dec != 0:
            errors.append(f"INPUT deve ter RS=0 e RT=0")

    elif expected_inst == "OUTPUTREG":
        # OUTPUTREG RS - deve usar RS como fonte
        if rt_dec != 0 or rd_dec != 0:
            errors.append(f"OUTPUTREG deve ter RT=0 e RD=0")

    elif expected_inst in ["LW", "SW"]:
        # LW RT, OFFSET(RS) / SW RT, OFFSET(RS)
        # LW: RT é destino, RS é base
        # SW: RT é fonte, RS é base
        pass  # Complexo, verificar manualmente

    elif expected_inst in ["ADD", "SUB", "AND", "OR", "SLT"]:
        # Formato: OP RD, RS, RT
        pass  # OK conforme atual

    elif expected_inst in ["BEQ", "BNE", "BGT", "BLT", "BGTE", "BLTE"]:
        # Formato: OP RS, RT, ENDEREÇO
        if rd_dec != 0:
            errors.append(f"Branch deve ter RD=0")

    if errors:
        for error in errors:
            print(f"         ❌ ERRO: {error}")
    else:
        print(f"         ✅ OK")

    print()
    return len(errors) == 0


# Dados das instruções
binary_lines = [
    "01110000000000000000000000010101",  # J 21
    "01101100000000000000000100000000",  # LI R1, 0
    "01100101110100001000000000000001",  # LW R2, 1(R29)
    "01010000001000000100000000000111",  # BNE R2, R1, 7
    "01100101110100001100000000000000",  # LW R3, 0(R29)
    "00101100001100000000000100000000",  # MOVE R1, R3
    "00110001111100000000000000000000",  # JR R31
    "00001100001100001000000000000000",  # DIV R3, R2
    "00100100000000000000010000000000",  # MFHI R4
    "00001000010000001000000000000000",  # MULT R4, R2
]

assembly_lines = [
    "J 21",
    "LI R1, 0",
    "LW R2, 1(R29)",
    "BNE R2, R1, 7",
    "LW R3, 0(R29)",
    "MOVE R1, R3",
    "JR R31",
    "DIV R3, R2",
    "MFHI R4",
    "MULT R4, R2",
]

print("ANÁLISE SISTEMÁTICA DAS INSTRUÇÕES")
print("=" * 80)

total_errors = 0
for i, (binary, assembly) in enumerate(zip(binary_lines, assembly_lines)):
    if not analyze_instruction(binary, assembly, i):
        total_errors += 1

print(f"TOTAL DE ERROS ENCONTRADOS: {total_errors}")
