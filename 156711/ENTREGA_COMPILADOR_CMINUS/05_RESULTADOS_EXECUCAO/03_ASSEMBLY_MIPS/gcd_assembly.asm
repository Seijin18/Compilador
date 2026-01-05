# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 128
  1: LI         SP, 255
  2: J          51
gcd:
  3: SUBI       SP, SP, 8
  4: SW         RA, 7(SP)
  5: SW         FP, 6(SP)
  6: MOVE       FP, SP
  7: SW         R4, 0(FP)
  8: SW         R5, 1(FP)
  9: LI         R1, 0
 10: LW         R2, 1(FP)
 11: BNE        R2, R1, 15
 12: LW         R3, 0(FP)
 13: MOVE       R1, R3
 14: J          47
L0:
 15: LW         R3, 0(FP)
 16: LW         R2, 1(FP)
 17: DIV        R4, R3, R2
 18: LW         R2, 1(FP)
 19: MULT       R5, R4, R2
 20: LW         R3, 0(FP)
 21: SUB        R6, R3, R5
 22: LW         R2, 1(FP)
 23: MOVE       R4, R2
 24: MOVE       R5, R6
 25: SUBI       R2, SP, 1
 26: SW         R2, 0(R2)
 27: SUBI       R2, SP, 2
 28: SW         R3, 0(R2)
 29: SUBI       R2, SP, 3
 30: SW         R5, 0(R2)
 31: SUBI       R2, SP, 4
 32: SW         R6, 0(R2)
 33: SUBI       SP, SP, 4
 34: JAL        3
 35: ADDI       SP, SP, 4
 36: SUBI       R2, SP, 4
 37: LW         R6, 0(R2)
 38: SUBI       R2, SP, 3
 39: LW         R5, 0(R2)
 40: SUBI       R2, SP, 2
 41: LW         R3, 0(R2)
 42: SUBI       R2, SP, 1
 43: LW         R2, 0(R2)
 44: MOVE       R7, R1
 45: MOVE       R1, R7
 46: J          47
L1:
gcd_epilogue:
 47: LW         RA, 7(SP)
 48: LW         FP, 6(SP)
 49: ADDI       SP, SP, 8
 50: JR         RA
main:
 51: SUBI       R2, SP, 2
 52: SW         FP, 0(R2)
 53: SUBI       SP, SP, 2
 54: MOVE       FP, SP
 55: INPUT      R8
 56: OUTPUTREG  R8
 57: MOVE       R9, R8
 58: SW         R9, 0(FP)
 59: INPUT      R10
 60: OUTPUTREG  R10
 61: MOVE       R11, R10
 62: SW         R11, 1(FP)
 63: LW         R9, 0(FP)
 64: MOVE       R4, R9
 65: LW         R11, 1(FP)
 66: MOVE       R5, R11
 67: SUBI       R2, SP, 1
 68: SW         R2, 0(R2)
 69: SUBI       R2, SP, 2
 70: SW         R3, 0(R2)
 71: SUBI       R2, SP, 3
 72: SW         R5, 0(R2)
 73: SUBI       R2, SP, 4
 74: SW         R6, 0(R2)
 75: SUBI       R2, SP, 5
 76: SW         R7, 0(R2)
 77: SUBI       R2, SP, 6
 78: SW         R8, 0(R2)
 79: SUBI       R2, SP, 7
 80: SW         R9, 0(R2)
 81: SUBI       R2, SP, 8
 82: SW         R10, 0(R2)
 83: SUBI       R2, SP, 9
 84: SW         R11, 0(R2)
 85: SUBI       SP, SP, 9
 86: JAL        3
 87: ADDI       SP, SP, 9
 88: SUBI       R2, SP, 9
 89: LW         R11, 0(R2)
 90: SUBI       R2, SP, 8
 91: LW         R10, 0(R2)
 92: SUBI       R2, SP, 7
 93: LW         R9, 0(R2)
 94: SUBI       R2, SP, 6
 95: LW         R8, 0(R2)
 96: SUBI       R2, SP, 5
 97: LW         R7, 0(R2)
 98: SUBI       R2, SP, 4
 99: LW         R6, 0(R2)
100: SUBI       R2, SP, 3
101: LW         R5, 0(R2)
102: SUBI       R2, SP, 2
103: LW         R3, 0(R2)
104: SUBI       R2, SP, 1
105: LW         R2, 0(R2)
106: MOVE       R12, R1
107: MOVE       R7, R1
108: OUTPUTREG  R12
109: HALT      
