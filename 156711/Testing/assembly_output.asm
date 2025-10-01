# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 272
  1: LI         SP, 255
  2: J          175
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
 36: BGTE       R14, R6, 48
 37: LW         R9, 3(FP)
 38: SLL        R15, R9, 2
 39: LW         R16, 0(FP)
 40: ADD        R16, R16, R15
 41: LW         R17, 0(R16)
 42: MOVE       R6, R17
 43: SW         R6, 4(FP)
 44: LW         R9, 3(FP)
 45: MOVE       R2, R9
 46: SW         R2, 5(FP)
 47: J          48
L2:
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
 77: BEQ        R22, R0, 171
 78: LW         R23, 0(FP)
 79: MOVE       R4, R23
 80: LW         R9, 3(FP)
 81: MOVE       R5, R9
 82: LW         R10, 2(FP)
 83: MOVE       R6, R10
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
139: MOVE       R24, R1
140: MOVE       R2, R24
141: SW         R2, 4(FP)
142: LW         R2, 4(FP)
143: SLL        R25, R2, 2
144: LW         R26, 0(FP)
145: ADD        R26, R26, R25
146: LW         R27, 0(R26)
147: MOVE       R3, R27
148: SW         R3, 6(FP)
149: LW         R9, 3(FP)
150: SLL        R4, R9, 2
151: LW         R5, 0(FP)
152: ADD        R5, R5, R4
153: LW         R7, 0(R5)
154: LW         R2, 4(FP)
155: SLL        R8, R2, 2
156: LW         R11, 0(FP)
157: ADD        R11, R11, R8
158: SW         R7, 0(R11)
159: LW         R9, 3(FP)
160: SLL        R12, R9, 2
161: LW         R13, 0(FP)
162: ADD        R13, R13, R12
163: LW         R3, 6(FP)
164: SW         R3, 0(R13)
165: LI         R14, 1
166: LW         R9, 3(FP)
167: ADD        R15, R9, R14
168: MOVE       R9, R15
169: SW         R9, 3(FP)
170: J          72
L5:
sort_epilogue:
171: LW         RA, 7(SP)
172: LW         FP, 6(SP)
173: ADDI       SP, SP, 8
174: JR         RA
main:
175: SUBI       R2, SP, 2
176: SW         FP, 0(R2)
177: SUBI       SP, SP, 2
178: MOVE       FP, SP
179: LI         R16, 0
180: MOVE       R9, R16
181: SW         R9, 0(FP)
L6:
182: LI         R17, 5
183: LW         R9, 0(FP)
184: SLT        R6, R9, R17
185: BEQ        R6, R0, 199
186: INPUT      R18
187: OUTPUTREG  R18
188: LW         R9, 0(FP)
189: SLL        R19, R9, 2
190: ADDI       R1, GP, 0
191: ADD        R1, R1, R19
192: SW         R18, 0(R1)
193: LI         R20, 1
194: LW         R9, 0(FP)
195: ADD        R21, R9, R20
196: MOVE       R9, R21
197: SW         R9, 0(FP)
198: J          182
L7:
199: LI         R22, 0
200: LI         R23, 5
201: ADDI       R10, GP, 0
202: MOVE       R4, R10
203: MOVE       R5, R22
204: MOVE       R6, R23
205: SUBI       R2, SP, 1
206: SW         R2, 0(R2)
207: SUBI       R2, SP, 2
208: SW         R3, 0(R2)
209: SUBI       R2, SP, 3
210: SW         R5, 0(R2)
211: SUBI       R2, SP, 4
212: SW         R6, 0(R2)
213: SUBI       R2, SP, 5
214: SW         R7, 0(R2)
215: SUBI       R2, SP, 6
216: SW         R8, 0(R2)
217: SUBI       R2, SP, 7
218: SW         R9, 0(R2)
219: SUBI       R2, SP, 8
220: SW         R10, 0(R2)
221: SUBI       R2, SP, 9
222: SW         R11, 0(R2)
223: SUBI       R2, SP, 10
224: SW         R12, 0(R2)
225: SUBI       R2, SP, 11
226: SW         R13, 0(R2)
227: SUBI       R2, SP, 12
228: SW         R14, 0(R2)
229: SUBI       R2, SP, 13
230: SW         R15, 0(R2)
231: SUBI       SP, SP, 13
232: JAL        61
233: ADDI       SP, SP, 13
234: SUBI       R2, SP, 13
235: LW         R15, 0(R2)
236: SUBI       R2, SP, 12
237: LW         R14, 0(R2)
238: SUBI       R2, SP, 11
239: LW         R13, 0(R2)
240: SUBI       R2, SP, 10
241: LW         R12, 0(R2)
242: SUBI       R2, SP, 9
243: LW         R11, 0(R2)
244: SUBI       R2, SP, 8
245: LW         R10, 0(R2)
246: SUBI       R2, SP, 7
247: LW         R9, 0(R2)
248: SUBI       R2, SP, 6
249: LW         R8, 0(R2)
250: SUBI       R2, SP, 5
251: LW         R7, 0(R2)
252: SUBI       R2, SP, 4
253: LW         R6, 0(R2)
254: SUBI       R2, SP, 3
255: LW         R5, 0(R2)
256: SUBI       R2, SP, 2
257: LW         R3, 0(R2)
258: SUBI       R2, SP, 1
259: LW         R2, 0(R2)
260: MOVE       R24, R1
261: MOVE       R7, R1
262: LI         R25, 0
263: MOVE       R9, R25
264: SW         R9, 0(FP)
L8:
265: LI         R26, 5
266: LW         R9, 0(FP)
267: SLT        R27, R9, R26
268: BEQ        R27, R0, 281
269: LW         R9, 0(FP)
270: SLL        R4, R9, 2
271: ADDI       R5, GP, 0
272: ADD        R5, R5, R4
273: LW         R2, 0(R5)
274: OUTPUTREG  R2
275: LI         R8, 1
276: LW         R9, 0(FP)
277: ADD        R11, R9, R8
278: MOVE       R9, R11
279: SW         R9, 0(FP)
280: J          265
L9:
281: HALT      
