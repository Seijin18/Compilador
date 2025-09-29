# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 292
  1: LI         SP, 255
  2: J          121
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
 56: J          57
minloc_epilogue:
 57: LW         RA, 7(SP)
 58: LW         FP, 6(SP)
 59: ADDI       SP, SP, 8
 60: JR         RA
sort:
 61: SUBI       SP, SP, 8
 62: SW         RA, 7(SP)
 63: SW         FP, 6(SP)
 64: MOVE       FP, SP
 65: SW         R4, 0(FP)
 66: SW         R5, 1(FP)
 67: SW         R6, 2(FP)
 68: SW         R7, 3(FP)
 69: LW         R1, 1(FP)
 70: MOVE       R9, R1
 71: SW         R9, 3(FP)
L4:
 72: LI         R20, 1
 73: LW         R10, 2(FP)
 74: SUB        R21, R10, R20
 75: LW         R9, 3(FP)
 76: SLT        R22, R9, R21
 77: BEQ        R22, R0, 117
 78: LW         R23, 0(FP)
 79: MOVE       R4, R23
 80: LW         R9, 3(FP)
 81: MOVE       R5, R9
 82: LW         R10, 2(FP)
 83: MOVE       R6, R10
 84: JAL        3
 85: MOVE       R24, R1
 86: MOVE       R2, R24
 87: SW         R2, 4(FP)
 88: LW         R2, 4(FP)
 89: SLL        R25, R2, 2
 90: LW         R26, 0(FP)
 91: ADD        R26, R26, R25
 92: LW         R27, 0(R26)
 93: MOVE       R3, R27
 94: SW         R3, 6(FP)
 95: LW         R9, 3(FP)
 96: SLL        R4, R9, 2
 97: LW         R5, 0(FP)
 98: ADD        R5, R5, R4
 99: LW         R7, 0(R5)
100: LW         R2, 4(FP)
101: SLL        R8, R2, 2
102: LW         R11, 0(FP)
103: ADD        R11, R11, R8
104: SW         R7, 0(R11)
105: LW         R9, 3(FP)
106: SLL        R12, R9, 2
107: LW         R13, 0(FP)
108: ADD        R13, R13, R12
109: LW         R3, 6(FP)
110: SW         R3, 0(R13)
111: LI         R14, 1
112: LW         R9, 3(FP)
113: ADD        R15, R9, R14
114: MOVE       R9, R15
115: SW         R9, 3(FP)
116: J          72
L5:
sort_epilogue:
117: LW         RA, 7(SP)
118: LW         FP, 6(SP)
119: ADDI       SP, SP, 8
120: JR         RA
main:
121: SUBI       R2, SP, 2
122: SW         FP, 0(R2)
123: SUBI       SP, SP, 2
124: MOVE       FP, SP
125: LI         R16, 0
126: MOVE       R9, R16
127: SW         R9, 0(FP)
L6:
128: LI         R17, 10
129: LW         R9, 0(FP)
130: SLT        R6, R9, R17
131: BEQ        R6, R0, 145
132: INPUT      R18
133: OUTPUTREG  R18
134: LW         R9, 0(FP)
135: SLL        R19, R9, 2
136: ADDI       R1, GP, 0
137: ADD        R1, R1, R19
138: SW         R18, 0(R1)
139: LI         R20, 1
140: LW         R9, 0(FP)
141: ADD        R21, R9, R20
142: MOVE       R9, R21
143: SW         R9, 0(FP)
144: J          128
L7:
145: LI         R22, 0
146: LI         R23, 10
147: ADDI       R10, GP, 0
148: MOVE       R4, R10
149: MOVE       R5, R22
150: MOVE       R6, R23
151: JAL        61
152: MOVE       R24, R1
153: MOVE       R7, R1
154: LI         R25, 0
155: MOVE       R9, R25
156: SW         R9, 0(FP)
L8:
157: LI         R26, 10
158: LW         R9, 0(FP)
159: SLT        R27, R9, R26
160: BEQ        R27, R0, 173
161: LW         R9, 0(FP)
162: SLL        R4, R9, 2
163: ADDI       R5, GP, 0
164: ADD        R5, R5, R4
165: LW         R2, 0(R5)
166: OUTPUTREG  R2
167: LI         R8, 1
168: LW         R9, 0(FP)
169: ADD        R11, R9, R8
170: MOVE       R9, R11
171: SW         R9, 0(FP)
172: J          157
L9:
173: HALT      
