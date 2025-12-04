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
gcd:
  6: SUBI       SP, SP, 8
  7: SW         RA, 7(SP)
  8: SW         FP, 6(SP)
  9: MOVE       FP, SP
 10: SW         R4, 0(FP)
 11: SW         R5, 1(FP)
 12: LI         R1, 0
 13: LW         R2, 1(FP)
 14: BNE        R2, R1, 18
 15: LW         R3, 0(FP)
 16: MOVE       R1, R3
 17: J          50
L0:
 18: LW         R3, 0(FP)
 19: LW         R2, 1(FP)
 20: DIV        R4, R3, R2
 21: LW         R2, 1(FP)
 22: MULT       R5, R4, R2
 23: LW         R3, 0(FP)
 24: SUB        R6, R3, R5
 25: LW         R2, 1(FP)
 26: MOVE       R4, R2
 27: MOVE       R5, R6
 28: SUBI       R2, SP, 1
 29: SW         R2, 0(R2)
 30: SUBI       R2, SP, 2
 31: SW         R3, 0(R2)
 32: SUBI       R2, SP, 3
 33: SW         R5, 0(R2)
 34: SUBI       R2, SP, 4
 35: SW         R6, 0(R2)
 36: SUBI       SP, SP, 4
 37: JAL        6
 38: ADDI       SP, SP, 4
 39: SUBI       R2, SP, 4
 40: LW         R6, 0(R2)
 41: SUBI       R2, SP, 3
 42: LW         R5, 0(R2)
 43: SUBI       R2, SP, 2
 44: LW         R3, 0(R2)
 45: SUBI       R2, SP, 1
 46: LW         R2, 0(R2)
 47: MOVE       R7, R1
 48: MOVE       R1, R7
 49: J          50
L1:
gcd_epilogue:
 50: LW         RA, 7(SP)
 51: LW         FP, 6(SP)
 52: ADDI       SP, SP, 8
 53: JR         RA
main:
 54: SUBI       R2, SP, 2
 55: SW         FP, 0(R2)
 56: SUBI       SP, SP, 2
 57: MOVE       FP, SP
 58: INPUT      R8
 59: OUTPUTREG  R8
 60: MOVE       R9, R8
 61: SW         R9, 0(FP)
 62: INPUT      R10
 63: OUTPUTREG  R10
 64: MOVE       R11, R10
 65: SW         R11, 1(FP)
 66: LW         R9, 0(FP)
 67: MOVE       R4, R9
 68: LW         R11, 1(FP)
 69: MOVE       R5, R11
 70: SUBI       R2, SP, 1
 71: SW         R2, 0(R2)
 72: SUBI       R2, SP, 2
 73: SW         R3, 0(R2)
 74: SUBI       R2, SP, 3
 75: SW         R5, 0(R2)
 76: SUBI       R2, SP, 4
 77: SW         R6, 0(R2)
 78: SUBI       R2, SP, 5
 79: SW         R7, 0(R2)
 80: SUBI       R2, SP, 6
 81: SW         R8, 0(R2)
 82: SUBI       R2, SP, 7
 83: SW         R9, 0(R2)
 84: SUBI       R2, SP, 8
 85: SW         R10, 0(R2)
 86: SUBI       R2, SP, 9
 87: SW         R11, 0(R2)
 88: SUBI       SP, SP, 9
 89: JAL        6
 90: ADDI       SP, SP, 9
 91: SUBI       R2, SP, 9
 92: LW         R11, 0(R2)
 93: SUBI       R2, SP, 8
 94: LW         R10, 0(R2)
 95: SUBI       R2, SP, 7
 96: LW         R9, 0(R2)
 97: SUBI       R2, SP, 6
 98: LW         R8, 0(R2)
 99: SUBI       R2, SP, 5
100: LW         R7, 0(R2)
101: SUBI       R2, SP, 4
102: LW         R6, 0(R2)
103: SUBI       R2, SP, 3
104: LW         R5, 0(R2)
105: SUBI       R2, SP, 2
106: LW         R3, 0(R2)
107: SUBI       R2, SP, 1
108: LW         R2, 0(R2)
109: MOVE       R12, R1
110: MOVE       R7, R1
111: OUTPUTREG  R12
112: HALT      
