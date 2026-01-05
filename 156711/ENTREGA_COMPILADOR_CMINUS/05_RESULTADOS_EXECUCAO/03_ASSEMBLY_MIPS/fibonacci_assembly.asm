# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 128
  1: LI         SP, 255
  2: J          66
fibonacci:
  3: SUBI       SP, SP, 8
  4: SW         RA, 7(SP)
  5: SW         FP, 6(SP)
  6: MOVE       FP, SP
  7: SW         R4, 0(FP)
  8: LI         R1, 1
  9: LW         R2, 0(FP)
 10: BLTE       R2, R1, 59
 11: LI         R3, 1
 12: LW         R2, 0(FP)
 13: SUB        R4, R2, R3
 14: MOVE       R4, R4
 15: SUBI       R2, SP, 1
 16: SW         R2, 0(R2)
 17: SUBI       R2, SP, 2
 18: SW         R3, 0(R2)
 19: SUBI       SP, SP, 2
 20: JAL        3
 21: ADDI       SP, SP, 2
 22: SUBI       R2, SP, 2
 23: LW         R3, 0(R2)
 24: SUBI       R2, SP, 1
 25: LW         R2, 0(R2)
 26: MOVE       R5, R1
 27: LI         R6, 2
 28: LW         R2, 0(FP)
 29: SUB        R7, R2, R6
 30: MOVE       R4, R7
 31: SUBI       R2, SP, 1
 32: SW         R2, 0(R2)
 33: SUBI       R2, SP, 2
 34: SW         R3, 0(R2)
 35: SUBI       R2, SP, 3
 36: SW         R5, 0(R2)
 37: SUBI       R2, SP, 4
 38: SW         R6, 0(R2)
 39: SUBI       R2, SP, 5
 40: SW         R7, 0(R2)
 41: SUBI       SP, SP, 5
 42: JAL        3
 43: ADDI       SP, SP, 5
 44: SUBI       R2, SP, 5
 45: LW         R7, 0(R2)
 46: SUBI       R2, SP, 4
 47: LW         R6, 0(R2)
 48: SUBI       R2, SP, 3
 49: LW         R5, 0(R2)
 50: SUBI       R2, SP, 2
 51: LW         R3, 0(R2)
 52: SUBI       R2, SP, 1
 53: LW         R2, 0(R2)
 54: MOVE       R8, R1
 55: ADD        R9, R5, R8
 56: MOVE       R1, R9
 57: J          62
 58: J          62
L0:
 59: LW         R2, 0(FP)
 60: MOVE       R1, R2
 61: J          62
L1:
fibonacci_epilogue:
 62: LW         RA, 7(SP)
 63: LW         FP, 6(SP)
 64: ADDI       SP, SP, 8
 65: JR         RA
main:
 66: SUBI       R2, SP, 2
 67: SW         FP, 0(R2)
 68: SUBI       SP, SP, 2
 69: MOVE       FP, SP
 70: INPUT      R10
 71: OUTPUTREG  R10
 72: MOVE       R2, R10
 73: SW         R2, 0(FP)
 74: LW         R2, 0(FP)
 75: MOVE       R4, R2
 76: SUBI       R2, SP, 1
 77: SW         R2, 0(R2)
 78: SUBI       R2, SP, 2
 79: SW         R3, 0(R2)
 80: SUBI       R2, SP, 3
 81: SW         R5, 0(R2)
 82: SUBI       R2, SP, 4
 83: SW         R6, 0(R2)
 84: SUBI       R2, SP, 5
 85: SW         R7, 0(R2)
 86: SUBI       R2, SP, 6
 87: SW         R8, 0(R2)
 88: SUBI       R2, SP, 7
 89: SW         R9, 0(R2)
 90: SUBI       R2, SP, 8
 91: SW         R10, 0(R2)
 92: SUBI       SP, SP, 8
 93: JAL        3
 94: ADDI       SP, SP, 8
 95: SUBI       R2, SP, 8
 96: LW         R10, 0(R2)
 97: SUBI       R2, SP, 7
 98: LW         R9, 0(R2)
 99: SUBI       R2, SP, 6
100: LW         R8, 0(R2)
101: SUBI       R2, SP, 5
102: LW         R7, 0(R2)
103: SUBI       R2, SP, 4
104: LW         R6, 0(R2)
105: SUBI       R2, SP, 3
106: LW         R5, 0(R2)
107: SUBI       R2, SP, 2
108: LW         R3, 0(R2)
109: SUBI       R2, SP, 1
110: LW         R2, 0(R2)
111: MOVE       R11, R1
112: MOVE       R7, R1
113: OUTPUTREG  R11
114: HALT      
