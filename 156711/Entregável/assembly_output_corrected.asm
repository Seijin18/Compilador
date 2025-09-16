# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 156
  1: LI         SP, 255
  2: J          3
main:
  3: SUBI       R2, SP, 2
  4: SW         FP, 0(R2)
  5: SUBI       SP, SP, 2
  6: MOVE       FP, SP
  7: LI         R1, 0
  8: MOVE       R2, R1
  9: SW         R2, 0(FP)
L0:
 10: LI         R3, 5
 11: LW         R2, 0(FP)
 12: SLT        R4, R2, R3
 13: BEQ        R4, R0, 30
 14: LI         R5, 1
 15: LW         R2, 0(FP)
 16: ADD        R6, R2, R5
 17: LI         R7, 10
 18: MULT       R8, R6, R7
 19: LW         R2, 0(FP)
 20: SLL        R9, R2, 2
 21: ADDI       R10, GP, 0
 22: ADD        R10, R10, R9
 23: SW         R8, 0(R10)
 24: LI         R11, 1
 25: LW         R2, 0(FP)
 26: ADD        R12, R2, R11
 27: MOVE       R2, R12
 28: SW         R2, 0(FP)
 29: J          10
L1:
 30: LI         R13, 0
 31: MOVE       R2, R13
 32: SW         R2, 0(FP)
 33: LI         R14, 0
 34: MOVE       R15, R14
 35: SW         R15, 1(FP)
L2:
 36: LI         R16, 5
 37: LW         R2, 0(FP)
 38: SLT        R17, R2, R16
 39: BEQ        R17, R0, 55
 40: LW         R2, 0(FP)
 41: SLL        R18, R2, 2
 42: ADDI       R19, GP, 0
 43: ADD        R19, R19, R18
 44: LW         R20, 0(R19)
 45: LW         R15, 1(FP)
 46: ADD        R21, R15, R20
 47: MOVE       R15, R21
 48: SW         R15, 1(FP)
 49: LI         R22, 1
 50: LW         R2, 0(FP)
 51: ADD        R23, R2, R22
 52: MOVE       R2, R23
 53: SW         R2, 0(FP)
 54: J          36
L3:
 55: LW         R15, 1(FP)
 56: OUTPUTREG  R15
 57: LI         R24, 0
 58: MOVE       R2, R24
 59: SW         R2, 0(FP)
L4:
 60: LI         R25, 3
 61: LW         R2, 0(FP)
 62: SLT        R26, R2, R25
 63: BEQ        R26, R0, 76
 64: LW         R2, 0(FP)
 65: SLL        R27, R2, 2
 66: ADDI       R1, GP, 0
 67: ADD        R1, R1, R27
 68: LW         R3, 0(R1)
 69: OUTPUTREG  R3
 70: LI         R4, 1
 71: LW         R2, 0(FP)
 72: ADD        R5, R2, R4
 73: MOVE       R2, R5
 74: SW         R2, 0(FP)
 75: J          60
L5:
 76: HALT      
