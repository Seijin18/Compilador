# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 128
  1: LI         SP, 255
  2: J          69
  3: ADD        R0, R0, R0
  4: J          0
  5: J          69
fibonacci:
  6: SUBI       SP, SP, 8
  7: SW         RA, 7(SP)
  8: SW         FP, 6(SP)
  9: MOVE       FP, SP
 10: SW         R4, 0(FP)
 11: LI         R1, 1
 12: LW         R2, 0(FP)
 13: BLTE       R2, R1, 62
 14: LI         R3, 1
 15: LW         R2, 0(FP)
 16: SUB        R4, R2, R3
 17: MOVE       R4, R4
 18: SUBI       R2, SP, 1
 19: SW         R2, 0(R2)
 20: SUBI       R2, SP, 2
 21: SW         R3, 0(R2)
 22: SUBI       SP, SP, 2
 23: JAL        6
 24: ADDI       SP, SP, 2
 25: SUBI       R2, SP, 2
 26: LW         R3, 0(R2)
 27: SUBI       R2, SP, 1
 28: LW         R2, 0(R2)
 29: MOVE       R5, R1
 30: LI         R6, 2
 31: LW         R2, 0(FP)
 32: SUB        R7, R2, R6
 33: MOVE       R4, R7
 34: SUBI       R2, SP, 1
 35: SW         R2, 0(R2)
 36: SUBI       R2, SP, 2
 37: SW         R3, 0(R2)
 38: SUBI       R2, SP, 3
 39: SW         R5, 0(R2)
 40: SUBI       R2, SP, 4
 41: SW         R6, 0(R2)
 42: SUBI       R2, SP, 5
 43: SW         R7, 0(R2)
 44: SUBI       SP, SP, 5
 45: JAL        6
 46: ADDI       SP, SP, 5
 47: SUBI       R2, SP, 5
 48: LW         R7, 0(R2)
 49: SUBI       R2, SP, 4
 50: LW         R6, 0(R2)
 51: SUBI       R2, SP, 3
 52: LW         R5, 0(R2)
 53: SUBI       R2, SP, 2
 54: LW         R3, 0(R2)
 55: SUBI       R2, SP, 1
 56: LW         R2, 0(R2)
 57: MOVE       R8, R1
 58: ADD        R9, R5, R8
 59: MOVE       R1, R9
 60: J          65
 61: J          65
L0:
 62: LW         R2, 0(FP)
 63: MOVE       R1, R2
 64: J          65
L1:
fibonacci_epilogue:
 65: LW         RA, 7(SP)
 66: LW         FP, 6(SP)
 67: ADDI       SP, SP, 8
 68: JR         RA
main:
 69: SUBI       R2, SP, 2
 70: SW         FP, 0(R2)
 71: SUBI       SP, SP, 2
 72: MOVE       FP, SP
 73: INPUT      R10
 74: OUTPUTREG  R10
 75: MOVE       R2, R10
 76: SW         R2, 0(FP)
 77: LW         R2, 0(FP)
 78: MOVE       R4, R2
 79: SUBI       R2, SP, 1
 80: SW         R2, 0(R2)
 81: SUBI       R2, SP, 2
 82: SW         R3, 0(R2)
 83: SUBI       R2, SP, 3
 84: SW         R5, 0(R2)
 85: SUBI       R2, SP, 4
 86: SW         R6, 0(R2)
 87: SUBI       R2, SP, 5
 88: SW         R7, 0(R2)
 89: SUBI       R2, SP, 6
 90: SW         R8, 0(R2)
 91: SUBI       R2, SP, 7
 92: SW         R9, 0(R2)
 93: SUBI       R2, SP, 8
 94: SW         R10, 0(R2)
 95: SUBI       SP, SP, 8
 96: JAL        6
 97: ADDI       SP, SP, 8
 98: SUBI       R2, SP, 8
 99: LW         R10, 0(R2)
100: SUBI       R2, SP, 7
101: LW         R9, 0(R2)
102: SUBI       R2, SP, 6
103: LW         R8, 0(R2)
104: SUBI       R2, SP, 5
105: LW         R7, 0(R2)
106: SUBI       R2, SP, 4
107: LW         R6, 0(R2)
108: SUBI       R2, SP, 3
109: LW         R5, 0(R2)
110: SUBI       R2, SP, 2
111: LW         R3, 0(R2)
112: SUBI       R2, SP, 1
113: LW         R2, 0(R2)
114: MOVE       R11, R1
115: MOVE       R7, R1
116: OUTPUTREG  R11
117: HALT      
