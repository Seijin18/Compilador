# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 292
  1: LI         SP, 255
  2: J          120
minloc:
  3: SUBI       SP, SP, 8
  4: SW         RA, 7(SP)
  5: SW         FP, 6(SP)
  6: MOVE       FP, SP
  7: SW         R4, 0(FP)
  8: SW         R5, 1(FP)
  9: SW         R6, 2(FP)
 10: SW         R7, 3(FP)
 11: LW         R1, 1(FP)
 12: MOVE       R2, R1
 13: SW         R2, 5(FP)
 14: LW         R1, 1(FP)
 15: SLL        R3, R1, 2
 16: LW         R4, 0(FP)
 17: ADD        R4, R4, R3
 18: LW         R5, 0(R4)
 19: MOVE       R6, R5
 20: SW         R6, 4(FP)
 21: LI         R7, 1
 22: LW         R1, 1(FP)
 23: ADD        R8, R1, R7
 24: MOVE       R9, R8
 25: SW         R9, 3(FP)
L0:
 26: LW         R9, 3(FP)
 27: LW         R10, 2(FP)
 28: SLT        R11, R9, R10
 29: BEQ        R11, R0, 54
 30: LW         R9, 3(FP)
 31: SLL        R12, R9, 2
 32: LW         R13, 0(FP)
 33: ADD        R13, R13, R12
 34: LW         R14, 0(R13)
 35: LW         R6, 4(FP)
 36: BGTE       R14, R6, 45
 37: LW         R9, 3(FP)
 38: SLL        R15, R9, 2
 39: LW         R16, 0(FP)
 40: ADD        R16, R16, R15
 41: LW         R17, 0(R16)
 42: MOVE       R6, R17
 43: SW         R6, 4(FP)
 44: J          48
L2:
 45: LW         R9, 3(FP)
 46: MOVE       R2, R9
 47: SW         R2, 5(FP)
L3:
 48: LI         R18, 1
 49: LW         R9, 3(FP)
 50: ADD        R19, R9, R18
 51: MOVE       R9, R19
 52: SW         R9, 3(FP)
 53: J          26
L1:
 54: LW         R2, 5(FP)
 55: MOVE       R1, R2
 56: LW         RA, 7(SP)
 57: LW         FP, 6(SP)
 58: ADDI       SP, SP, 8
 59: JR         RA
sort:
 60: SUBI       SP, SP, 8
 61: SW         RA, 7(SP)
 62: SW         FP, 6(SP)
 63: MOVE       FP, SP
 64: SW         R4, 0(FP)
 65: SW         R5, 1(FP)
 66: SW         R6, 2(FP)
 67: SW         R7, 3(FP)
 68: LW         R1, 1(FP)
 69: MOVE       R9, R1
 70: SW         R9, 3(FP)
L4:
 71: LI         R20, 1
 72: LW         R10, 2(FP)
 73: SUB        R21, R10, R20
 74: LW         R9, 3(FP)
 75: SLT        R22, R9, R21
 76: BEQ        R22, R0, 116
 77: ADDI       R23, FP, 0
 78: MOVE       R4, R23
 79: LW         R9, 3(FP)
 80: MOVE       R5, R9
 81: LW         R10, 2(FP)
 82: MOVE       R6, R10
 83: JAL        3
 84: MOVE       R24, R1
 85: MOVE       R2, R24
 86: SW         R2, 4(FP)
 87: LW         R2, 4(FP)
 88: SLL        R25, R2, 2
 89: LW         R26, 0(FP)
 90: ADD        R26, R26, R25
 91: LW         R27, 0(R26)
 92: MOVE       R3, R27
 93: SW         R3, 6(FP)
 94: LW         R9, 3(FP)
 95: SLL        R4, R9, 2
 96: LW         R5, 0(FP)
 97: ADD        R5, R5, R4
 98: LW         R7, 0(R5)
 99: LW         R2, 4(FP)
100: SLL        R8, R2, 2
101: LW         R11, 0(FP)
102: ADD        R11, R11, R8
103: SW         R7, 0(R11)
104: LW         R9, 3(FP)
105: SLL        R12, R9, 2
106: LW         R13, 0(FP)
107: ADD        R13, R13, R12
108: LW         R3, 6(FP)
109: SW         R3, 0(R13)
110: LI         R14, 1
111: LW         R9, 3(FP)
112: ADD        R15, R9, R14
113: MOVE       R9, R15
114: SW         R9, 3(FP)
115: J          71
L5:
116: LW         RA, 7(SP)
117: LW         FP, 6(SP)
118: ADDI       SP, SP, 8
119: JR         RA
main:
120: SUBI       R2, SP, 2
121: SW         FP, 0(R2)
122: SUBI       SP, SP, 2
123: MOVE       FP, SP
124: LI         R16, 0
125: MOVE       R9, R16
126: SW         R9, 0(FP)
L6:
127: LI         R17, 10
128: LW         R9, 0(FP)
129: SLT        R6, R9, R17
130: BEQ        R6, R0, 144
131: INPUT      R18
132: OUTPUTREG  R18
133: LW         R9, 0(FP)
134: SLL        R19, R9, 2
135: ADDI       R1, GP, 0
136: ADD        R1, R1, R19
137: SW         R18, 0(R1)
138: LI         R20, 1
139: LW         R9, 0(FP)
140: ADD        R21, R9, R20
141: MOVE       R9, R21
142: SW         R9, 0(FP)
143: J          127
L7:
144: LI         R22, 0
145: LI         R23, 10
146: ADDI       R10, GP, 0
147: MOVE       R4, R10
148: MOVE       R5, R22
149: MOVE       R6, R23
150: JAL        60
151: MOVE       R24, R1
152: MOVE       R7, R1
153: LI         R25, 0
154: MOVE       R9, R25
155: SW         R9, 0(FP)
L8:
156: LI         R26, 10
157: LW         R9, 0(FP)
158: SLT        R27, R9, R26
159: BEQ        R27, R0, 172
160: LW         R9, 0(FP)
161: SLL        R4, R9, 2
162: ADDI       R5, GP, 0
163: ADD        R5, R5, R4
164: LW         R2, 0(R5)
165: OUTPUTREG  R2
166: LI         R8, 1
167: LW         R9, 0(FP)
168: ADD        R11, R9, R8
169: MOVE       R9, R11
170: SW         R9, 0(FP)
171: J          156
L9:
172: HALT      
