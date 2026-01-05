# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 128
  1: LI         SP, 255
  2: J          74
isPrime:
  3: SUBI       SP, SP, 8
  4: SW         RA, 7(SP)
  5: SW         FP, 6(SP)
  6: MOVE       FP, SP
  7: SW         R4, 0(FP)
  8: SW         R5, 1(FP)
  9: SW         R6, 2(FP)
 10: SW         R7, 3(FP)
 11: LI         R1, 1
 12: LW         R2, 0(FP)
 13: BGT        R2, R1, 18
 14: LI         R3, 0
 15: MOVE       R1, R3
 16: J          70
 17: J          18
L0:
L1:
 18: LI         R4, 2
 19: MOVE       R5, R4
 20: SW         R5, 1(FP)
 21: LW         R5, 1(FP)
 22: LW         R5, 1(FP)
 23: MULT       R6, R5, R5
 24: MOVE       R7, R6
 25: SW         R7, 3(FP)
L2:
 26: LW         R7, 3(FP)
 27: LW         R2, 0(FP)
 28: SLT        R8, R2, R7
 29: LI         R1, 1
 30: SUB        R8, R1, R8
 31: BEQ        R8, R0, 67
 32: LI         R9, 0
 33: MOVE       R10, R9
 34: SW         R10, 2(FP)
L4:
 35: LW         R10, 2(FP)
 36: LW         R2, 0(FP)
 37: SLT        R11, R2, R10
 38: LI         R1, 1
 39: SUB        R11, R1, R11
 40: BEQ        R11, R0, 47
 41: LW         R10, 2(FP)
 42: LW         R5, 1(FP)
 43: ADD        R12, R10, R5
 44: MOVE       R10, R12
 45: SW         R10, 2(FP)
 46: J          35
L5:
 47: LW         R2, 0(FP)
 48: LW         R5, 1(FP)
 49: ADD        R13, R2, R5
 50: LW         R10, 2(FP)
 51: BNE        R10, R13, 56
 52: LI         R14, 0
 53: MOVE       R1, R14
 54: J          70
 55: J          56
L6:
L7:
 56: LI         R15, 1
 57: LW         R5, 1(FP)
 58: ADD        R16, R5, R15
 59: MOVE       R5, R16
 60: SW         R5, 1(FP)
 61: LW         R5, 1(FP)
 62: LW         R5, 1(FP)
 63: MULT       R17, R5, R5
 64: MOVE       R7, R17
 65: SW         R7, 3(FP)
 66: J          26
L3:
 67: LI         R18, 1
 68: MOVE       R1, R18
 69: J          70
isPrime_epilogue:
 70: LW         RA, 7(SP)
 71: LW         FP, 6(SP)
 72: ADDI       SP, SP, 8
 73: JR         RA
main:
 74: SUBI       R2, SP, 2
 75: SW         FP, 0(R2)
 76: SUBI       SP, SP, 2
 77: MOVE       FP, SP
 78: INPUT      R19
 79: OUTPUTREG  R19
 80: MOVE       R20, R19
 81: SW         R20, 0(FP)
 82: LW         R20, 0(FP)
 83: MOVE       R4, R20
 84: SUBI       R2, SP, 1
 85: SW         R2, 0(R2)
 86: SUBI       R2, SP, 2
 87: SW         R3, 0(R2)
 88: SUBI       R2, SP, 3
 89: SW         R5, 0(R2)
 90: SUBI       R2, SP, 4
 91: SW         R6, 0(R2)
 92: SUBI       R2, SP, 5
 93: SW         R7, 0(R2)
 94: SUBI       R2, SP, 6
 95: SW         R8, 0(R2)
 96: SUBI       R2, SP, 7
 97: SW         R9, 0(R2)
 98: SUBI       R2, SP, 8
 99: SW         R10, 0(R2)
100: SUBI       R2, SP, 9
101: SW         R11, 0(R2)
102: SUBI       R2, SP, 10
103: SW         R12, 0(R2)
104: SUBI       R2, SP, 11
105: SW         R13, 0(R2)
106: SUBI       R2, SP, 12
107: SW         R14, 0(R2)
108: SUBI       R2, SP, 13
109: SW         R15, 0(R2)
110: SUBI       SP, SP, 13
111: JAL        3
112: ADDI       SP, SP, 13
113: SUBI       R2, SP, 13
114: LW         R15, 0(R2)
115: SUBI       R2, SP, 12
116: LW         R14, 0(R2)
117: SUBI       R2, SP, 11
118: LW         R13, 0(R2)
119: SUBI       R2, SP, 10
120: LW         R12, 0(R2)
121: SUBI       R2, SP, 9
122: LW         R11, 0(R2)
123: SUBI       R2, SP, 8
124: LW         R10, 0(R2)
125: SUBI       R2, SP, 7
126: LW         R9, 0(R2)
127: SUBI       R2, SP, 6
128: LW         R8, 0(R2)
129: SUBI       R2, SP, 5
130: LW         R7, 0(R2)
131: SUBI       R2, SP, 4
132: LW         R6, 0(R2)
133: SUBI       R2, SP, 3
134: LW         R5, 0(R2)
135: SUBI       R2, SP, 2
136: LW         R3, 0(R2)
137: SUBI       R2, SP, 1
138: LW         R2, 0(R2)
139: MOVE       R21, R1
140: MOVE       R7, R1
141: MOVE       R22, R21
142: SW         R22, 1(FP)
143: LW         R22, 1(FP)
144: OUTPUTREG  R22
145: HALT      
