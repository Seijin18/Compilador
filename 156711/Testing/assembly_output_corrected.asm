# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 196
  1: LI         SP, 255
  2: J          45
sumarray:
  3: SUBI       R2, SP, 1
  4: SW         RA, 0(R2)
  5: SUBI       R2, SP, 2
  6: SW         FP, 0(R2)
  7: SUBI       SP, SP, 8
  8: MOVE       FP, SP
  9: SW         R4, 0(FP)
 10: SW         R5, 1(FP)
 11: LI         R1, 0
 12: MOVE       R2, R1
 13: SW         R2, 3(FP)
 14: LI         R3, 0
 15: MOVE       R4, R3
 16: SW         R4, 2(FP)
L0:
 17: LW         R4, 2(FP)
 18: LW         R5, 1(FP)
 19: SLT        R6, R4, R5
 20: BEQ        R6, R0, 36
 21: LW         R4, 2(FP)
 22: SLL        R7, R4, 2
 23: LW         R8, 0(FP)
 24: ADD        R8, R8, R7
 25: LW         R9, 0(R8)
 26: LW         R2, 3(FP)
 27: ADD        R10, R2, R9
 28: MOVE       R2, R10
 29: SW         R2, 3(FP)
 30: LI         R11, 1
 31: LW         R4, 2(FP)
 32: ADD        R12, R4, R11
 33: MOVE       R4, R12
 34: SW         R4, 2(FP)
 35: J          17
L1:
 36: LW         R2, 3(FP)
 37: MOVE       R1, R2
 38: ADDI       SP, FP, 8
 39: SUBI       R2, SP, 2
 40: LW         FP, 0(R2)
 41: SUBI       R2, SP, 1
 42: LW         RA, 0(R2)
 43: ADDI       SP, SP, 8
 44: JR         RA
main:
 45: SUBI       R2, SP, 2
 46: SW         FP, 0(R2)
 47: SUBI       SP, SP, 2
 48: MOVE       FP, SP
 49: LI         R13, 5
 50: LI         R14, 0
 51: SLL        R7, R14, 2
 52: ADDI       R8, GP, 0
 53: ADD        R8, R8, R7
 54: SW         R13, 0(R8)
 55: LI         R15, 10
 56: LI         R16, 1
 57: SLL        R7, R16, 2
 58: ADDI       R8, GP, 0
 59: ADD        R8, R8, R7
 60: SW         R15, 0(R8)
 61: LI         R17, 15
 62: LI         R18, 2
 63: SLL        R7, R18, 2
 64: ADDI       R8, GP, 0
 65: ADD        R8, R8, R7
 66: SW         R17, 0(R8)
 67: LI         R19, 3
 68: ADDI       R20, GP, 0
 69: MOVE       R4, R20
 70: MOVE       R5, R19
 71: JAL        3
 72: MOVE       R21, R1
 73: MOVE       R7, R1
 74: MOVE       R22, R21
 75: SW         R22, 0(FP)
 76: LW         R22, 0(FP)
 77: OUTPUTREG  R22
 78: HALT      
