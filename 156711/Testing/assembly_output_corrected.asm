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
 15: SLL        R3, R6, 2
 16: ADDI       R4, GP, 0
 17: ADD        R4, R4, R3
 18: SW         R5, 0(R4)
 19: LI         R7, 300
 20: LI         R8, 2
 21: SLL        R3, R8, 2
 22: ADDI       R4, GP, 0
 23: ADD        R4, R4, R3
 24: SW         R7, 0(R4)
 25: LI         R9, 400
 26: LI         R10, 3
 27: SLL        R3, R10, 2
 28: ADDI       R4, GP, 0
 29: ADD        R4, R4, R3
 30: SW         R9, 0(R4)
 31: LI         R11, 1
 32: SLL        R3, R11, 2
 33: ADDI       R4, GP, 0
 34: ADD        R4, R4, R3
 35: LW         R12, 0(R4)
 36: MOVE       R13, R12
 37: SW         R13, 0(FP)
 38: LI         R14, 0
 39: SLL        R3, R14, 2
 40: ADDI       R4, GP, 0
 41: ADD        R4, R4, R3
 42: LW         R15, 0(R4)
 43: LI         R16, 2
 44: SLL        R3, R16, 2
 45: ADDI       R4, GP, 0
 46: ADD        R4, R4, R3
 47: LW         R17, 0(R4)
 48: ADD        R18, R15, R17
 49: LI         R19, 1
 50: SLL        R3, R19, 2
 51: ADDI       R4, GP, 0
 52: ADD        R4, R4, R3
 53: SW         R18, 0(R4)
 54: LI         R20, 0
 55: SLL        R3, R20, 2
 56: ADDI       R4, GP, 0
 57: ADD        R4, R4, R3
 58: LW         R13, 0(FP)
 59: SW         R13, 0(R4)
 60: LI         R21, 0
 61: SLL        R3, R21, 2
 62: ADDI       R4, GP, 0
 63: ADD        R4, R4, R3
 64: LW         R22, 0(R4)
 65: OUTPUTREG  R22
 66: LI         R23, 1
 67: SLL        R3, R23, 2
 68: ADDI       R4, GP, 0
 69: ADD        R4, R4, R3
 70: LW         R24, 0(R4)
 71: OUTPUTREG  R24
 72: LI         R25, 2
 73: SLL        R3, R25, 2
 74: ADDI       R4, GP, 0
 75: ADD        R4, R4, R3
 76: LW         R26, 0(R4)
 77: OUTPUTREG  R26
 78: LI         R27, 3
 79: SLL        R3, R27, 2
 80: ADDI       R4, GP, 0
 81: ADD        R4, R4, R3
 82: LW         R2, 0(R4)
 83: OUTPUTREG  R2
 84: HALT      
