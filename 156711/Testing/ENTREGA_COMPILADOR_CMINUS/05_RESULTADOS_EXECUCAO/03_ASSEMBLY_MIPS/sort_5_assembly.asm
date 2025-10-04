# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 128
  1: LI         SP, 255
  2: J          168
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
 15: LW         R3, 0(FP)
 16: ADD        R3, R3, R1
 17: LW         R4, 0(R3)
 18: MOVE       R5, R4
 19: SW         R5, 4(FP)
 20: LI         R6, 1
 21: LW         R1, 1(FP)
 22: ADD        R7, R1, R6
 23: MOVE       R8, R7
 24: SW         R8, 3(FP)
L0:
 25: LW         R8, 3(FP)
 26: LW         R9, 2(FP)
 27: SLT        R10, R8, R9
 28: BEQ        R10, R0, 51
 29: LW         R8, 3(FP)
 30: LW         R11, 0(FP)
 31: ADD        R11, R11, R8
 32: LW         R12, 0(R11)
 33: LW         R5, 4(FP)
 34: BGTE       R12, R5, 45
 35: LW         R8, 3(FP)
 36: LW         R13, 0(FP)
 37: ADD        R13, R13, R8
 38: LW         R14, 0(R13)
 39: MOVE       R5, R14
 40: SW         R5, 4(FP)
 41: LW         R8, 3(FP)
 42: MOVE       R2, R8
 43: SW         R2, 5(FP)
 44: J          45
L2:
L3:
 45: LI         R15, 1
 46: LW         R8, 3(FP)
 47: ADD        R16, R8, R15
 48: MOVE       R8, R16
 49: SW         R8, 3(FP)
 50: J          25
L1:
 51: LW         R2, 5(FP)
 52: MOVE       R1, R2
 53: J          54
minloc_epilogue:
 54: LW         RA, 7(SP)
 55: LW         FP, 6(SP)
 56: ADDI       SP, SP, 8
 57: JR         RA
sort:
 58: SUBI       SP, SP, 8
 59: SW         RA, 7(SP)
 60: SW         FP, 6(SP)
 61: MOVE       FP, SP
 62: SW         R4, 0(FP)
 63: SW         R5, 1(FP)
 64: SW         R6, 2(FP)
 65: SW         R7, 3(FP)
 66: LW         R1, 1(FP)
 67: MOVE       R8, R1
 68: SW         R8, 3(FP)
L4:
 69: LI         R17, 1
 70: LW         R9, 2(FP)
 71: SUB        R18, R9, R17
 72: LW         R8, 3(FP)
 73: SLT        R19, R8, R18
 74: BEQ        R19, R0, 164
 75: LW         R20, 0(FP)
 76: MOVE       R4, R20
 77: LW         R8, 3(FP)
 78: MOVE       R5, R8
 79: LW         R9, 2(FP)
 80: MOVE       R6, R9
 81: SUBI       R2, SP, 1
 82: SW         R2, 0(R2)
 83: SUBI       R2, SP, 2
 84: SW         R3, 0(R2)
 85: SUBI       R2, SP, 3
 86: SW         R5, 0(R2)
 87: SUBI       R2, SP, 4
 88: SW         R6, 0(R2)
 89: SUBI       R2, SP, 5
 90: SW         R7, 0(R2)
 91: SUBI       R2, SP, 6
 92: SW         R8, 0(R2)
 93: SUBI       R2, SP, 7
 94: SW         R9, 0(R2)
 95: SUBI       R2, SP, 8
 96: SW         R10, 0(R2)
 97: SUBI       R2, SP, 9
 98: SW         R11, 0(R2)
 99: SUBI       R2, SP, 10
100: SW         R12, 0(R2)
101: SUBI       R2, SP, 11
102: SW         R13, 0(R2)
103: SUBI       R2, SP, 12
104: SW         R14, 0(R2)
105: SUBI       R2, SP, 13
106: SW         R15, 0(R2)
107: SUBI       SP, SP, 13
108: JAL        3
109: ADDI       SP, SP, 13
110: SUBI       R2, SP, 13
111: LW         R15, 0(R2)
112: SUBI       R2, SP, 12
113: LW         R14, 0(R2)
114: SUBI       R2, SP, 11
115: LW         R13, 0(R2)
116: SUBI       R2, SP, 10
117: LW         R12, 0(R2)
118: SUBI       R2, SP, 9
119: LW         R11, 0(R2)
120: SUBI       R2, SP, 8
121: LW         R10, 0(R2)
122: SUBI       R2, SP, 7
123: LW         R9, 0(R2)
124: SUBI       R2, SP, 6
125: LW         R8, 0(R2)
126: SUBI       R2, SP, 5
127: LW         R7, 0(R2)
128: SUBI       R2, SP, 4
129: LW         R6, 0(R2)
130: SUBI       R2, SP, 3
131: LW         R5, 0(R2)
132: SUBI       R2, SP, 2
133: LW         R3, 0(R2)
134: SUBI       R2, SP, 1
135: LW         R2, 0(R2)
136: MOVE       R21, R1
137: MOVE       R2, R21
138: SW         R2, 4(FP)
139: LW         R2, 4(FP)
140: LW         R22, 0(FP)
141: ADD        R22, R22, R2
142: LW         R23, 0(R22)
143: MOVE       R24, R23
144: SW         R24, 6(FP)
145: LW         R8, 3(FP)
146: LW         R25, 0(FP)
147: ADD        R25, R25, R8
148: LW         R26, 0(R25)
149: LW         R2, 4(FP)
150: LW         R27, 0(FP)
151: ADD        R27, R27, R2
152: SW         R26, 0(R27)
153: LW         R8, 3(FP)
154: LW         R3, 0(FP)
155: ADD        R3, R3, R8
156: LW         R24, 6(FP)
157: SW         R24, 0(R3)
158: LI         R4, 1
159: LW         R8, 3(FP)
160: ADD        R6, R8, R4
161: MOVE       R8, R6
162: SW         R8, 3(FP)
163: J          69
L5:
sort_epilogue:
164: LW         RA, 7(SP)
165: LW         FP, 6(SP)
166: ADDI       SP, SP, 8
167: JR         RA
main:
168: SUBI       R2, SP, 2
169: SW         FP, 0(R2)
170: SUBI       SP, SP, 2
171: MOVE       FP, SP
172: LI         R7, 0
173: MOVE       R8, R7
174: SW         R8, 0(FP)
L6:
175: LI         R10, 5
176: LW         R8, 0(FP)
177: SLT        R11, R8, R10
178: BEQ        R11, R0, 191
179: INPUT      R12
180: OUTPUTREG  R12
181: LW         R8, 0(FP)
182: ADDI       R13, GP, 0
183: ADD        R13, R13, R8
184: SW         R12, 0(R13)
185: LI         R14, 1
186: LW         R8, 0(FP)
187: ADD        R5, R8, R14
188: MOVE       R8, R5
189: SW         R8, 0(FP)
190: J          175
L7:
191: LI         R15, 0
192: LI         R16, 5
193: ADDI       R1, GP, 0
194: MOVE       R4, R1
195: MOVE       R5, R15
196: MOVE       R6, R16
197: SUBI       R2, SP, 1
198: SW         R2, 0(R2)
199: SUBI       R2, SP, 2
200: SW         R3, 0(R2)
201: SUBI       R2, SP, 3
202: SW         R5, 0(R2)
203: SUBI       R2, SP, 4
204: SW         R6, 0(R2)
205: SUBI       R2, SP, 5
206: SW         R7, 0(R2)
207: SUBI       R2, SP, 6
208: SW         R8, 0(R2)
209: SUBI       R2, SP, 7
210: SW         R9, 0(R2)
211: SUBI       R2, SP, 8
212: SW         R10, 0(R2)
213: SUBI       R2, SP, 9
214: SW         R11, 0(R2)
215: SUBI       R2, SP, 10
216: SW         R12, 0(R2)
217: SUBI       R2, SP, 11
218: SW         R13, 0(R2)
219: SUBI       R2, SP, 12
220: SW         R14, 0(R2)
221: SUBI       R2, SP, 13
222: SW         R15, 0(R2)
223: SUBI       SP, SP, 13
224: JAL        58
225: ADDI       SP, SP, 13
226: SUBI       R2, SP, 13
227: LW         R15, 0(R2)
228: SUBI       R2, SP, 12
229: LW         R14, 0(R2)
230: SUBI       R2, SP, 11
231: LW         R13, 0(R2)
232: SUBI       R2, SP, 10
233: LW         R12, 0(R2)
234: SUBI       R2, SP, 9
235: LW         R11, 0(R2)
236: SUBI       R2, SP, 8
237: LW         R10, 0(R2)
238: SUBI       R2, SP, 7
239: LW         R9, 0(R2)
240: SUBI       R2, SP, 6
241: LW         R8, 0(R2)
242: SUBI       R2, SP, 5
243: LW         R7, 0(R2)
244: SUBI       R2, SP, 4
245: LW         R6, 0(R2)
246: SUBI       R2, SP, 3
247: LW         R5, 0(R2)
248: SUBI       R2, SP, 2
249: LW         R3, 0(R2)
250: SUBI       R2, SP, 1
251: LW         R2, 0(R2)
252: MOVE       R17, R1
253: MOVE       R7, R1
254: LI         R18, 0
255: MOVE       R8, R18
256: SW         R8, 0(FP)
L8:
257: LI         R19, 5
258: LW         R8, 0(FP)
259: SLT        R20, R8, R19
260: BEQ        R20, R0, 272
261: LW         R8, 0(FP)
262: ADDI       R9, GP, 0
263: ADD        R9, R9, R8
264: LW         R21, 0(R9)
265: OUTPUTREG  R21
266: LI         R22, 1
267: LW         R8, 0(FP)
268: ADD        R23, R8, R22
269: MOVE       R8, R23
270: SW         R8, 0(FP)
271: J          257
L9:
272: HALT      
