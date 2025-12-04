# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 128
  1: LI         SP, 255
  2: J          171
  3: ADD        R0, R0, R0
  4: J          0
  5: J          171
minloc:
  6: SUBI       SP, SP, 8
  7: SW         RA, 7(SP)
  8: SW         FP, 6(SP)
  9: MOVE       FP, SP
 10: SW         R4, 0(FP)
 11: SW         R5, 1(FP)
 12: SW         R6, 2(FP)
 13: SW         R7, 3(FP)
 14: LW         R1, 1(FP)
 15: MOVE       R2, R1
 16: SW         R2, 5(FP)
 17: LW         R1, 1(FP)
 18: LW         R3, 0(FP)
 19: ADD        R3, R3, R1
 20: LW         R4, 0(R3)
 21: MOVE       R5, R4
 22: SW         R5, 4(FP)
 23: LI         R6, 1
 24: LW         R1, 1(FP)
 25: ADD        R7, R1, R6
 26: MOVE       R8, R7
 27: SW         R8, 3(FP)
L0:
 28: LW         R8, 3(FP)
 29: LW         R9, 2(FP)
 30: SLT        R10, R8, R9
 31: BEQ        R10, R0, 54
 32: LW         R8, 3(FP)
 33: LW         R11, 0(FP)
 34: ADD        R11, R11, R8
 35: LW         R12, 0(R11)
 36: LW         R5, 4(FP)
 37: BGTE       R12, R5, 48
 38: LW         R8, 3(FP)
 39: LW         R13, 0(FP)
 40: ADD        R13, R13, R8
 41: LW         R14, 0(R13)
 42: MOVE       R5, R14
 43: SW         R5, 4(FP)
 44: LW         R8, 3(FP)
 45: MOVE       R2, R8
 46: SW         R2, 5(FP)
 47: J          48
L2:
L3:
 48: LI         R15, 1
 49: LW         R8, 3(FP)
 50: ADD        R16, R8, R15
 51: MOVE       R8, R16
 52: SW         R8, 3(FP)
 53: J          28
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
 70: MOVE       R8, R1
 71: SW         R8, 3(FP)
L4:
 72: LI         R17, 1
 73: LW         R9, 2(FP)
 74: SUB        R18, R9, R17
 75: LW         R8, 3(FP)
 76: SLT        R19, R8, R18
 77: BEQ        R19, R0, 167
 78: LW         R20, 0(FP)
 79: MOVE       R4, R20
 80: LW         R8, 3(FP)
 81: MOVE       R5, R8
 82: LW         R9, 2(FP)
 83: MOVE       R6, R9
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
111: JAL        6
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
140: MOVE       R2, R21
141: SW         R2, 4(FP)
142: LW         R2, 4(FP)
143: LW         R22, 0(FP)
144: ADD        R22, R22, R2
145: LW         R23, 0(R22)
146: MOVE       R24, R23
147: SW         R24, 6(FP)
148: LW         R8, 3(FP)
149: LW         R25, 0(FP)
150: ADD        R25, R25, R8
151: LW         R26, 0(R25)
152: LW         R2, 4(FP)
153: LW         R27, 0(FP)
154: ADD        R27, R27, R2
155: SW         R26, 0(R27)
156: LW         R8, 3(FP)
157: LW         R3, 0(FP)
158: ADD        R3, R3, R8
159: LW         R24, 6(FP)
160: SW         R24, 0(R3)
161: LI         R4, 1
162: LW         R8, 3(FP)
163: ADD        R6, R8, R4
164: MOVE       R8, R6
165: SW         R8, 3(FP)
166: J          72
L5:
sort_epilogue:
167: LW         RA, 7(SP)
168: LW         FP, 6(SP)
169: ADDI       SP, SP, 8
170: JR         RA
main:
171: SUBI       R2, SP, 2
172: SW         FP, 0(R2)
173: SUBI       SP, SP, 2
174: MOVE       FP, SP
175: LI         R7, 0
176: MOVE       R8, R7
177: SW         R8, 0(FP)
L6:
178: LI         R10, 5
179: LW         R8, 0(FP)
180: SLT        R11, R8, R10
181: BEQ        R11, R0, 194
182: INPUT      R12
183: OUTPUTREG  R12
184: LW         R8, 0(FP)
185: ADDI       R13, GP, 0
186: ADD        R13, R13, R8
187: SW         R12, 0(R13)
188: LI         R14, 1
189: LW         R8, 0(FP)
190: ADD        R5, R8, R14
191: MOVE       R8, R5
192: SW         R8, 0(FP)
193: J          178
L7:
194: LI         R15, 0
195: LI         R16, 5
196: ADDI       R1, GP, 0
197: MOVE       R4, R1
198: MOVE       R5, R15
199: MOVE       R6, R16
200: SUBI       R2, SP, 1
201: SW         R2, 0(R2)
202: SUBI       R2, SP, 2
203: SW         R3, 0(R2)
204: SUBI       R2, SP, 3
205: SW         R5, 0(R2)
206: SUBI       R2, SP, 4
207: SW         R6, 0(R2)
208: SUBI       R2, SP, 5
209: SW         R7, 0(R2)
210: SUBI       R2, SP, 6
211: SW         R8, 0(R2)
212: SUBI       R2, SP, 7
213: SW         R9, 0(R2)
214: SUBI       R2, SP, 8
215: SW         R10, 0(R2)
216: SUBI       R2, SP, 9
217: SW         R11, 0(R2)
218: SUBI       R2, SP, 10
219: SW         R12, 0(R2)
220: SUBI       R2, SP, 11
221: SW         R13, 0(R2)
222: SUBI       R2, SP, 12
223: SW         R14, 0(R2)
224: SUBI       R2, SP, 13
225: SW         R15, 0(R2)
226: SUBI       SP, SP, 13
227: JAL        61
228: ADDI       SP, SP, 13
229: SUBI       R2, SP, 13
230: LW         R15, 0(R2)
231: SUBI       R2, SP, 12
232: LW         R14, 0(R2)
233: SUBI       R2, SP, 11
234: LW         R13, 0(R2)
235: SUBI       R2, SP, 10
236: LW         R12, 0(R2)
237: SUBI       R2, SP, 9
238: LW         R11, 0(R2)
239: SUBI       R2, SP, 8
240: LW         R10, 0(R2)
241: SUBI       R2, SP, 7
242: LW         R9, 0(R2)
243: SUBI       R2, SP, 6
244: LW         R8, 0(R2)
245: SUBI       R2, SP, 5
246: LW         R7, 0(R2)
247: SUBI       R2, SP, 4
248: LW         R6, 0(R2)
249: SUBI       R2, SP, 3
250: LW         R5, 0(R2)
251: SUBI       R2, SP, 2
252: LW         R3, 0(R2)
253: SUBI       R2, SP, 1
254: LW         R2, 0(R2)
255: MOVE       R17, R1
256: MOVE       R7, R1
257: LI         R18, 0
258: MOVE       R8, R18
259: SW         R8, 0(FP)
L8:
260: LI         R19, 5
261: LW         R8, 0(FP)
262: SLT        R20, R8, R19
263: BEQ        R20, R0, 275
264: LW         R8, 0(FP)
265: ADDI       R9, GP, 0
266: ADD        R9, R9, R8
267: LW         R21, 0(R9)
268: OUTPUTREG  R21
269: LI         R22, 1
270: LW         R8, 0(FP)
271: ADD        R23, R8, R22
272: MOVE       R8, R23
273: SW         R8, 0(FP)
274: J          260
L9:
275: HALT      
