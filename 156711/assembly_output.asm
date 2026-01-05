# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 128
  1: LI         SP, 255
  2: J          222
scheduler:
  3: SUBI       SP, SP, 8
  4: SW         RA, 7(SP)
  5: SW         FP, 6(SP)
  6: MOVE       FP, SP
  7: SW         R4, 0(FP)
  8: SW         R5, 1(FP)
  9: LI         R1, 10
 10: MOVE       R2, R1
 11: SW         R2, 0(FP)
 12: LI         R3, 0
 13: MOVE       R4, R3
 14: SW         R4, 1(FP)
L0:
 15: LI         R5, 0
 16: LW         R2, 0(FP)
 17: SLT        R6, R5, R2
 18: BEQ        R6, R0, 56
 19: LI         R7, 9
 20: LW         R8, 0(GP)
 21: BLTE       R8, R7, 26
 22: LI         R9, 0
 23: MOVE       R8, R9
 24: SW         R8, 0(GP)
 25: J          26
L2:
L3:
 26: LW         R8, 0(GP)
 27: ADDI       R10, GP, 2
 28: ADD        R10, R10, R8
 29: LW         R11, 0(R10)
 30: LI         R12, 1
 31: BNE        R11, R12, 41
 32: LW         R8, 0(GP)
 33: MOVE       R27, R8
 34: LI         R13, 1
 35: MOVE       R4, R13
 36: SW         R4, 1(FP)
 37: LI         R14, 0
 38: MOVE       R2, R14
 39: SW         R2, 0(FP)
 40: J          55
L4:
 41: LI         R15, 1
 42: LW         R2, 0(FP)
 43: SUB        R16, R2, R15
 44: MOVE       R2, R16
 45: SW         R2, 0(FP)
 46: LI         R17, 0
 47: LW         R2, 0(FP)
 48: BLTE       R2, R17, 55
 49: LI         R18, 1
 50: LW         R8, 0(GP)
 51: ADD        R19, R8, R18
 52: MOVE       R8, R19
 53: SW         R8, 0(GP)
 54: J          55
L6:
L7:
L5:
 55: J          15
L1:
 56: LI         R20, 1
 57: LW         R4, 1(FP)
 58: BNE        R4, R20, 74
 59: LW         R8, 0(GP)
 60: LOAD_PROG  R8
 61: LOAD_CTX  
 62: LI         R21, 1
 63: LW         R22, 1(GP)
 64: BNE        R22, R21, 69
 65: LI         R23, 100
 66: SET_QUANTUM R23
 67: ENABLE_TIMER
 68: J          69
L10:
L11:
 69: LI         R24, 1
 70: LW         R8, 0(GP)
 71: ADD        R25, R8, R24
 72: MOVE       R8, R25
 73: J          77
L8:
 74: LI         R26, 0
 75: MOVE       R8, R26
 76: SW         R8, 0(GP)
L9:
 77: RETI      
scheduler_epilogue:
 78: LW         RA, 7(SP)
 79: LW         FP, 6(SP)
 80: ADDI       SP, SP, 8
 81: JR         RA
irq:
 82: SUBI       SP, SP, 8
 83: SW         RA, 7(SP)
 84: SW         FP, 6(SP)
 85: MOVE       FP, SP
 86: DISABLE_TIMER
 87: SAVE_CTX  
 88: LW         R8, 0(GP)
 89: MOVE       R4, R8
 90: LW         R8, 0(GP)
 91: MOVE       R5, R8
 92: MOVE       R6, R23
 93: SUBI       R26, SP, 1
 94: SW         R2, 0(R26)
 95: SUBI       R26, SP, 2
 96: SW         R3, 0(R26)
 97: SUBI       R26, SP, 3
 98: SW         R5, 0(R26)
 99: SUBI       R26, SP, 4
100: SW         R6, 0(R26)
101: SUBI       R26, SP, 5
102: SW         R7, 0(R26)
103: SUBI       R26, SP, 6
104: SW         R8, 0(R26)
105: SUBI       R26, SP, 7
106: SW         R9, 0(R26)
107: SUBI       R26, SP, 8
108: SW         R10, 0(R26)
109: SUBI       R26, SP, 9
110: SW         R11, 0(R26)
111: SUBI       R26, SP, 10
112: SW         R12, 0(R26)
113: SUBI       R26, SP, 11
114: SW         R13, 0(R26)
115: SUBI       R26, SP, 12
116: SW         R14, 0(R26)
117: SUBI       R26, SP, 13
118: SW         R15, 0(R26)
119: SUBI       SP, SP, 13
120: JAL        3
121: ADDI       SP, SP, 13
122: SUBI       R26, SP, 13
123: LW         R15, 0(R26)
124: SUBI       R26, SP, 12
125: LW         R14, 0(R26)
126: SUBI       R26, SP, 11
127: LW         R13, 0(R26)
128: SUBI       R26, SP, 10
129: LW         R12, 0(R26)
130: SUBI       R26, SP, 9
131: LW         R11, 0(R26)
132: SUBI       R26, SP, 8
133: LW         R10, 0(R26)
134: SUBI       R26, SP, 7
135: LW         R9, 0(R26)
136: SUBI       R26, SP, 6
137: LW         R8, 0(R26)
138: SUBI       R26, SP, 5
139: LW         R7, 0(R26)
140: SUBI       R26, SP, 4
141: LW         R6, 0(R26)
142: SUBI       R26, SP, 3
143: LW         R5, 0(R26)
144: SUBI       R26, SP, 2
145: LW         R3, 0(R26)
146: SUBI       R26, SP, 1
147: LW         R2, 0(R26)
irq_epilogue:
148: LW         RA, 7(SP)
149: LW         FP, 6(SP)
150: ADDI       SP, SP, 8
151: JR         RA
halt:
152: SUBI       SP, SP, 8
153: SW         RA, 7(SP)
154: SW         FP, 6(SP)
155: MOVE       FP, SP
156: DISABLE_TIMER
157: LI         R3, 0
158: LW         R8, 0(GP)
159: ADDI       R5, GP, 2
160: ADD        R5, R5, R8
161: SW         R3, 0(R5)
162: SUBI       R26, SP, 1
163: SW         R2, 0(R26)
164: SUBI       R26, SP, 2
165: SW         R3, 0(R26)
166: SUBI       R26, SP, 3
167: SW         R5, 0(R26)
168: SUBI       R26, SP, 4
169: SW         R6, 0(R26)
170: SUBI       R26, SP, 5
171: SW         R7, 0(R26)
172: SUBI       R26, SP, 6
173: SW         R8, 0(R26)
174: SUBI       R26, SP, 7
175: SW         R9, 0(R26)
176: SUBI       R26, SP, 8
177: SW         R10, 0(R26)
178: SUBI       R26, SP, 9
179: SW         R11, 0(R26)
180: SUBI       R26, SP, 10
181: SW         R12, 0(R26)
182: SUBI       R26, SP, 11
183: SW         R13, 0(R26)
184: SUBI       R26, SP, 12
185: SW         R14, 0(R26)
186: SUBI       R26, SP, 13
187: SW         R15, 0(R26)
188: SUBI       SP, SP, 13
189: JAL        82
190: ADDI       SP, SP, 13
191: SUBI       R26, SP, 13
192: LW         R15, 0(R26)
193: SUBI       R26, SP, 12
194: LW         R14, 0(R26)
195: SUBI       R26, SP, 11
196: LW         R13, 0(R26)
197: SUBI       R26, SP, 10
198: LW         R12, 0(R26)
199: SUBI       R26, SP, 9
200: LW         R11, 0(R26)
201: SUBI       R26, SP, 8
202: LW         R10, 0(R26)
203: SUBI       R26, SP, 7
204: LW         R9, 0(R26)
205: SUBI       R26, SP, 6
206: LW         R8, 0(R26)
207: SUBI       R26, SP, 5
208: LW         R7, 0(R26)
209: SUBI       R26, SP, 4
210: LW         R6, 0(R26)
211: SUBI       R26, SP, 3
212: LW         R5, 0(R26)
213: SUBI       R26, SP, 2
214: LW         R3, 0(R26)
215: SUBI       R26, SP, 1
216: LW         R2, 0(R26)
217: MOVE       R6, R1
halt_epilogue:
218: LW         RA, 7(SP)
219: LW         FP, 6(SP)
220: ADDI       SP, SP, 8
221: JR         RA
main:
222: SUBI       R26, SP, 2
223: SW         FP, 0(R26)
224: SUBI       SP, SP, 2
225: MOVE       FP, SP
226: LI         R7, 0
227: MOVE       R9, R7
228: SW         R9, 0(FP)
229: INPUT      R10
230: OUTPUTREG  R10
231: MOVE       R22, R10
232: SW         R22, 1(GP)
L12:
233: LI         R11, 10
234: LW         R9, 0(FP)
235: SLT        R12, R9, R11
236: BEQ        R12, R0, 249
237: INPUT      R13
238: OUTPUTREG  R13
239: LW         R9, 0(FP)
240: ADDI       R14, GP, 2
241: ADD        R14, R14, R9
242: SW         R13, 0(R14)
243: LI         R15, 1
244: LW         R9, 0(FP)
245: ADD        R16, R9, R15
246: MOVE       R9, R16
247: SW         R9, 0(FP)
248: J          233
L13:
249: SUBI       R26, SP, 1
250: SW         R2, 0(R26)
251: SUBI       R26, SP, 2
252: SW         R3, 0(R26)
253: SUBI       R26, SP, 3
254: SW         R5, 0(R26)
255: SUBI       R26, SP, 4
256: SW         R6, 0(R26)
257: SUBI       R26, SP, 5
258: SW         R7, 0(R26)
259: SUBI       R26, SP, 6
260: SW         R8, 0(R26)
261: SUBI       R26, SP, 7
262: SW         R9, 0(R26)
263: SUBI       R26, SP, 8
264: SW         R10, 0(R26)
265: SUBI       R26, SP, 9
266: SW         R11, 0(R26)
267: SUBI       R26, SP, 10
268: SW         R12, 0(R26)
269: SUBI       R26, SP, 11
270: SW         R13, 0(R26)
271: SUBI       R26, SP, 12
272: SW         R14, 0(R26)
273: SUBI       R26, SP, 13
274: SW         R15, 0(R26)
275: SUBI       SP, SP, 13
276: JAL        3
277: ADDI       SP, SP, 13
278: SUBI       R26, SP, 13
279: LW         R15, 0(R26)
280: SUBI       R26, SP, 12
281: LW         R14, 0(R26)
282: SUBI       R26, SP, 11
283: LW         R13, 0(R26)
284: SUBI       R26, SP, 10
285: LW         R12, 0(R26)
286: SUBI       R26, SP, 9
287: LW         R11, 0(R26)
288: SUBI       R26, SP, 8
289: LW         R10, 0(R26)
290: SUBI       R26, SP, 7
291: LW         R9, 0(R26)
292: SUBI       R26, SP, 6
293: LW         R8, 0(R26)
294: SUBI       R26, SP, 5
295: LW         R7, 0(R26)
296: SUBI       R26, SP, 4
297: LW         R6, 0(R26)
298: SUBI       R26, SP, 3
299: LW         R5, 0(R26)
300: SUBI       R26, SP, 2
301: LW         R3, 0(R26)
302: SUBI       R26, SP, 1
303: LW         R2, 0(R26)
304: MOVE       R2, R1
305: MOVE       R7, R1
306: HALT      
