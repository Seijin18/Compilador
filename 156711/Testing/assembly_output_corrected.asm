# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 148
  1: LI         SP, 255
  2: J          3
main:
  3: SUBI       R2, SP, 2
  4: SW         FP, 0(R2)
  5: SUBI       SP, SP, 2
  6: MOVE       FP, SP
  7: LI         R1, 100
  8: LI         R2, 0
  9: SLL        R3, R2, 2
 10: ADDI       R4, GP, 0
 11: ADD        R4, R4, R3
 12: SW         R1, 0(R4)
 13: LI         R5, 200
 14: LI         R6, 1
 15: SLL        R7, R6, 2
 16: ADDI       R8, GP, 0
 17: ADD        R8, R8, R7
 18: SW         R5, 0(R8)
 19: LI         R9, 300
 20: LI         R10, 2
 21: SLL        R11, R10, 2
 22: ADDI       R12, GP, 0
 23: ADD        R12, R12, R11
 24: SW         R9, 0(R12)
 25: LI         R13, 400
 26: LI         R14, 3
 27: SLL        R15, R14, 2
 28: ADDI       R16, GP, 0
 29: ADD        R16, R16, R15
 30: SW         R13, 0(R16)
 31: LI         R17, 1
 32: SLL        R18, R17, 2
 33: ADDI       R19, GP, 0
 34: ADD        R19, R19, R18
 35: LW         R20, 0(R19)
 36: MOVE       R21, R20
 37: SW         R21, 0(FP)
 38: LI         R22, 0
 39: SLL        R23, R22, 2
 40: ADDI       R24, GP, 0
 41: ADD        R24, R24, R23
 42: LW         R25, 0(R24)
 43: LI         R26, 2
 44: SLL        R27, R26, 2
 45: ADDI       R2, GP, 0
 46: ADD        R2, R2, R27
 47: LW         R3, 0(R2)
 48: ADD        R4, R25, R3
 49: LI         R1, 1
 50: SLL        R6, R1, 2
 51: ADDI       R7, GP, 0
 52: ADD        R7, R7, R6
 53: SW         R4, 0(R7)
 54: LI         R8, 0
 55: SLL        R5, R8, 2
 56: ADDI       R10, GP, 0
 57: ADD        R10, R10, R5
 58: LW         R21, 0(FP)
 59: SW         R21, 0(R10)
 60: LI         R11, 0
 61: SLL        R12, R11, 2
 62: ADDI       R9, GP, 0
 63: ADD        R9, R9, R12
 64: LW         R14, 0(R9)
 65: OUTPUTREG  R14
 66: LI         R15, 1
 67: SLL        R16, R15, 2
 68: ADDI       R13, GP, 0
 69: ADD        R13, R13, R16
 70: LW         R17, 0(R13)
 71: OUTPUTREG  R17
 72: LI         R18, 2
 73: SLL        R19, R18, 2
 74: ADDI       R20, GP, 0
 75: ADD        R20, R20, R19
 76: LW         R22, 0(R20)
 77: OUTPUTREG  R22
 78: LI         R23, 3
 79: SLL        R24, R23, 2
 80: ADDI       R26, GP, 0
 81: ADD        R26, R26, R24
 82: LW         R27, 0(R26)
 83: OUTPUTREG  R27
 84: HALT      
