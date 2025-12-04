# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 128
  1: LI         SP, 255
  2: J          77
  3: ADD        R0, R0, R0
  4: J          0
  5: J          77
isPrime:
  6: SUBI       SP, SP, 8
  7: SW         RA, 7(SP)
  8: SW         FP, 6(SP)
  9: MOVE       FP, SP
 10: SW         R4, 0(FP)
 11: SW         R5, 1(FP)
 12: SW         R6, 2(FP)
 13: SW         R7, 3(FP)
 14: LI         R1, 1
 15: LW         R2, 0(FP)
 16: BGT        R2, R1, 21
 17: LI         R3, 0
 18: MOVE       R1, R3
 19: J          73
 20: J          21
L0:
L1:
 21: LI         R4, 2
 22: MOVE       R5, R4
 23: SW         R5, 1(FP)
 24: LW         R5, 1(FP)
 25: LW         R5, 1(FP)
 26: MULT       R6, R5, R5
 27: MOVE       R7, R6
 28: SW         R7, 3(FP)
L2:
 29: LW         R7, 3(FP)
 30: LW         R2, 0(FP)
 31: SLT        R8, R2, R7
 32: LI         R1, 1
 33: SUB        R8, R1, R8
 34: BEQ        R8, R0, 70
 35: LI         R9, 0
 36: MOVE       R10, R9
 37: SW         R10, 2(FP)
L4:
 38: LW         R10, 2(FP)
 39: LW         R2, 0(FP)
 40: SLT        R11, R2, R10
 41: LI         R1, 1
 42: SUB        R11, R1, R11
 43: BEQ        R11, R0, 50
 44: LW         R10, 2(FP)
 45: LW         R5, 1(FP)
 46: ADD        R12, R10, R5
 47: MOVE       R10, R12
 48: SW         R10, 2(FP)
 49: J          38
L5:
 50: LW         R2, 0(FP)
 51: LW         R5, 1(FP)
 52: ADD        R13, R2, R5
 53: LW         R10, 2(FP)
 54: BNE        R10, R13, 59
 55: LI         R14, 0
 56: MOVE       R1, R14
 57: J          73
 58: J          59
L6:
L7:
 59: LI         R15, 1
 60: LW         R5, 1(FP)
 61: ADD        R16, R5, R15
 62: MOVE       R5, R16
 63: SW         R5, 1(FP)
 64: LW         R5, 1(FP)
 65: LW         R5, 1(FP)
 66: MULT       R17, R5, R5
 67: MOVE       R7, R17
 68: SW         R7, 3(FP)
 69: J          29
L3:
 70: LI         R18, 1
 71: MOVE       R1, R18
 72: J          73
isPrime_epilogue:
 73: LW         RA, 7(SP)
 74: LW         FP, 6(SP)
 75: ADDI       SP, SP, 8
 76: JR         RA
main:
 77: SUBI       R2, SP, 2
 78: SW         FP, 0(R2)
 79: SUBI       SP, SP, 2
 80: MOVE       FP, SP
 81: INPUT      R19
 82: OUTPUTREG  R19
 83: MOVE       R20, R19
 84: SW         R20, 0(FP)
 85: LW         R20, 0(FP)
 86: MOVE       R4, R20
 87: SUBI       R2, SP, 1
 88: SW         R2, 0(R2)
 89: SUBI       R2, SP, 2
 90: SW         R3, 0(R2)
 91: SUBI       R2, SP, 3
 92: SW         R5, 0(R2)
 93: SUBI       R2, SP, 4
 94: SW         R6, 0(R2)
 95: SUBI       R2, SP, 5
 96: SW         R7, 0(R2)
 97: SUBI       R2, SP, 6
 98: SW         R8, 0(R2)
 99: SUBI       R2, SP, 7
100: SW         R9, 0(R2)
101: SUBI       R2, SP, 8
102: SW         R10, 0(R2)
103: SUBI       R2, SP, 9
104: SW         R11, 0(R2)
105: SUBI       R2, SP, 10
106: SW         R12, 0(R2)
107: SUBI       R2, SP, 11
108: SW         R13, 0(R2)
109: SUBI       R2, SP, 12
110: SW         R14, 0(R2)
111: SUBI       R2, SP, 13
112: SW         R15, 0(R2)
113: SUBI       SP, SP, 13
114: JAL        6
115: ADDI       SP, SP, 13
116: SUBI       R2, SP, 13
117: LW         R15, 0(R2)
118: SUBI       R2, SP, 12
119: LW         R14, 0(R2)
120: SUBI       R2, SP, 11
121: LW         R13, 0(R2)
122: SUBI       R2, SP, 10
123: LW         R12, 0(R2)
124: SUBI       R2, SP, 9
125: LW         R11, 0(R2)
126: SUBI       R2, SP, 8
127: LW         R10, 0(R2)
128: SUBI       R2, SP, 7
129: LW         R9, 0(R2)
130: SUBI       R2, SP, 6
131: LW         R8, 0(R2)
132: SUBI       R2, SP, 5
133: LW         R7, 0(R2)
134: SUBI       R2, SP, 4
135: LW         R6, 0(R2)
136: SUBI       R2, SP, 3
137: LW         R5, 0(R2)
138: SUBI       R2, SP, 2
139: LW         R3, 0(R2)
140: SUBI       R2, SP, 1
141: LW         R2, 0(R2)
142: MOVE       R21, R1
143: MOVE       R7, R1
144: MOVE       R22, R21
145: SW         R22, 1(FP)
146: LW         R22, 1(FP)
147: OUTPUTREG  R22
148: HALT      
