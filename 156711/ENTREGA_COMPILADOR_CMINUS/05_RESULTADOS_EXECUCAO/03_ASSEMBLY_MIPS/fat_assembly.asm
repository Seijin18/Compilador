# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 128
  1: LI         SP, 255
  2: J          51
fat:
  3: SUBI       SP, SP, 8
  4: SW         RA, 7(SP)
  5: SW         FP, 6(SP)
  6: MOVE       FP, SP
  7: SW         R4, 0(FP)
  8: LI         R1, 0
  9: LW         R2, 0(FP)
 10: BNE        R2, R1, 17
 11: LI         R3, 10
 12: OUTPUTREG  R3
 13: LI         R4, 1
 14: MOVE       R1, R4
 15: J          47
 16: J          47
L0:
 17: LW         R2, 0(FP)
 18: OUTPUTREG  R2
 19: LI         R5, 1
 20: LW         R2, 0(FP)
 21: SUB        R6, R2, R5
 22: MOVE       R4, R6
 23: SUBI       R2, SP, 1
 24: SW         R2, 0(R2)
 25: SUBI       R2, SP, 2
 26: SW         R3, 0(R2)
 27: SUBI       R2, SP, 3
 28: SW         R5, 0(R2)
 29: SUBI       R2, SP, 4
 30: SW         R6, 0(R2)
 31: SUBI       SP, SP, 4
 32: JAL        3
 33: ADDI       SP, SP, 4
 34: SUBI       R2, SP, 4
 35: LW         R6, 0(R2)
 36: SUBI       R2, SP, 3
 37: LW         R5, 0(R2)
 38: SUBI       R2, SP, 2
 39: LW         R3, 0(R2)
 40: SUBI       R2, SP, 1
 41: LW         R2, 0(R2)
 42: MOVE       R7, R1
 43: LW         R2, 0(FP)
 44: MULT       R8, R2, R7
 45: MOVE       R1, R8
 46: J          47
L1:
fat_epilogue:
 47: LW         RA, 7(SP)
 48: LW         FP, 6(SP)
 49: ADDI       SP, SP, 8
 50: JR         RA
main:
 51: SUBI       R2, SP, 2
 52: SW         FP, 0(R2)
 53: SUBI       SP, SP, 2
 54: MOVE       FP, SP
 55: INPUT      R9
 56: OUTPUTREG  R9
 57: MOVE       R2, R9
 58: SW         R2, 0(FP)
 59: LW         R2, 0(FP)
 60: MOVE       R4, R2
 61: SUBI       R2, SP, 1
 62: SW         R2, 0(R2)
 63: SUBI       R2, SP, 2
 64: SW         R3, 0(R2)
 65: SUBI       R2, SP, 3
 66: SW         R5, 0(R2)
 67: SUBI       R2, SP, 4
 68: SW         R6, 0(R2)
 69: SUBI       R2, SP, 5
 70: SW         R7, 0(R2)
 71: SUBI       R2, SP, 6
 72: SW         R8, 0(R2)
 73: SUBI       R2, SP, 7
 74: SW         R9, 0(R2)
 75: SUBI       SP, SP, 7
 76: JAL        3
 77: ADDI       SP, SP, 7
 78: SUBI       R2, SP, 7
 79: LW         R9, 0(R2)
 80: SUBI       R2, SP, 6
 81: LW         R8, 0(R2)
 82: SUBI       R2, SP, 5
 83: LW         R7, 0(R2)
 84: SUBI       R2, SP, 4
 85: LW         R6, 0(R2)
 86: SUBI       R2, SP, 3
 87: LW         R5, 0(R2)
 88: SUBI       R2, SP, 2
 89: LW         R3, 0(R2)
 90: SUBI       R2, SP, 1
 91: LW         R2, 0(R2)
 92: MOVE       R10, R1
 93: MOVE       R7, R1
 94: OUTPUTREG  R10
 95: HALT      
