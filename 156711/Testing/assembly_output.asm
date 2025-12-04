# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 128
  1: LI         SP, 255
  2: J          54
  3: ADD        R0, R0, R0
  4: J          0
  5: J          54
fat:
  6: SUBI       SP, SP, 8
  7: SW         RA, 7(SP)
  8: SW         FP, 6(SP)
  9: MOVE       FP, SP
 10: SW         R4, 0(FP)
 11: LI         R1, 0
 12: LW         R2, 0(FP)
 13: BNE        R2, R1, 20
 14: LI         R3, 10
 15: OUTPUTREG  R3
 16: LI         R4, 1
 17: MOVE       R1, R4
 18: J          50
 19: J          50
L0:
 20: LW         R2, 0(FP)
 21: OUTPUTREG  R2
 22: LI         R5, 1
 23: LW         R2, 0(FP)
 24: SUB        R6, R2, R5
 25: MOVE       R4, R6
 26: SUBI       R2, SP, 1
 27: SW         R2, 0(R2)
 28: SUBI       R2, SP, 2
 29: SW         R3, 0(R2)
 30: SUBI       R2, SP, 3
 31: SW         R5, 0(R2)
 32: SUBI       R2, SP, 4
 33: SW         R6, 0(R2)
 34: SUBI       SP, SP, 4
 35: JAL        6
 36: ADDI       SP, SP, 4
 37: SUBI       R2, SP, 4
 38: LW         R6, 0(R2)
 39: SUBI       R2, SP, 3
 40: LW         R5, 0(R2)
 41: SUBI       R2, SP, 2
 42: LW         R3, 0(R2)
 43: SUBI       R2, SP, 1
 44: LW         R2, 0(R2)
 45: MOVE       R7, R1
 46: LW         R2, 0(FP)
 47: MULT       R8, R2, R7
 48: MOVE       R1, R8
 49: J          50
L1:
fat_epilogue:
 50: LW         RA, 7(SP)
 51: LW         FP, 6(SP)
 52: ADDI       SP, SP, 8
 53: JR         RA
main:
 54: SUBI       R2, SP, 2
 55: SW         FP, 0(R2)
 56: SUBI       SP, SP, 2
 57: MOVE       FP, SP
 58: INPUT      R9
 59: OUTPUTREG  R9
 60: MOVE       R2, R9
 61: SW         R2, 0(FP)
 62: LW         R2, 0(FP)
 63: MOVE       R4, R2
 64: SUBI       R2, SP, 1
 65: SW         R2, 0(R2)
 66: SUBI       R2, SP, 2
 67: SW         R3, 0(R2)
 68: SUBI       R2, SP, 3
 69: SW         R5, 0(R2)
 70: SUBI       R2, SP, 4
 71: SW         R6, 0(R2)
 72: SUBI       R2, SP, 5
 73: SW         R7, 0(R2)
 74: SUBI       R2, SP, 6
 75: SW         R8, 0(R2)
 76: SUBI       R2, SP, 7
 77: SW         R9, 0(R2)
 78: SUBI       SP, SP, 7
 79: JAL        6
 80: ADDI       SP, SP, 7
 81: SUBI       R2, SP, 7
 82: LW         R9, 0(R2)
 83: SUBI       R2, SP, 6
 84: LW         R8, 0(R2)
 85: SUBI       R2, SP, 5
 86: LW         R7, 0(R2)
 87: SUBI       R2, SP, 4
 88: LW         R6, 0(R2)
 89: SUBI       R2, SP, 3
 90: LW         R5, 0(R2)
 91: SUBI       R2, SP, 2
 92: LW         R3, 0(R2)
 93: SUBI       R2, SP, 1
 94: LW         R2, 0(R2)
 95: MOVE       R10, R1
 96: MOVE       R7, R1
 97: OUTPUTREG  R10
 98: HALT      
