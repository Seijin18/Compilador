#!/usr/bin/env python3
# Script para verificar a correspondência entre assembly e binário

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

binary_lines = [
    "01110000000000000000000000010101",
    "01101100000000000000000100000000",
    "01100101110100001000000000000001",
    "01010000001000000100000000000111",
    "01100101110100001100000000000000",
    "00101100001100000100000000000000",
    "00110001111100000000000000000000",
    "00001100001100001000000000000000",
    "00100100000000000000010000000000",
    "00001000010000001000000000000000",
]

# Opcodes conforme documentação
opcodes = {
    "ADD": "000000",
    "SUB": "000001",
    "MULT": "000010",
    "DIV": "000011",
    "AND": "000100",
    "OR": "000101",
    "SLL": "000110",
    "SRL": "000111",
    "SLT": "001000",
    "MFHI": "001001",
    "MFLO": "001010",
    "MOVE": "001011",
    "JR": "001100",
    "JALR": "001101",
    "LA": "001110",
    "ADDI": "001111",
    "SUBI": "010000",
    "ANDI": "010001",
    "ORI": "010010",
    "BEQ": "010011",
    "BNE": "010100",
    "BGT": "010101",
    "BGTE": "010110",
    "BLT": "010111",
    "BLTE": "011000",
    "LW": "011001",
    "SW": "011010",
    "LI": "011011",
    "J": "011100",
    "JAL": "011101",
    "HALT": "011110",
    "OUTPUTMEM": "011111",
    "OUTPUTREG": "100000",
    "OUTPUT_RESET": "100001",
    "INPUT": "100010",
}

print("Verificação Assembly vs Binário:")
print("=" * 80)

for i, (asm, binary) in enumerate(zip(assembly_lines, binary_lines)):
    inst = asm.split()[0]
    expected_opcode = opcodes.get(inst, "UNKNOWN")
    actual_opcode = binary[:6]

    status = "✅" if expected_opcode == actual_opcode else "❌"

    print(f"Linha {i:2d}: {asm:20s} | {binary} | {status}")
    print(f"         Esperado: {expected_opcode} | Atual: {actual_opcode}")

    if expected_opcode != actual_opcode:
        print(f"         ❌ ERRO: Opcode incorreto!")
    print()
