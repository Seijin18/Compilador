# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 128
  1: LI         SP, 255
  2: J          3
main:
  3: SUBI       R2, SP, 2
  4: SW         FP, 0(R2)
  5: SUBI       SP, SP, 2
  6: MOVE       FP, SP
  7: INPUT      R1
  8: OUTPUTREG  R1
  9: MOVE       R2, R1
 10: SW         R2, 0(FP)
 11: INPUT      R3
 12: OUTPUTREG  R3
 13: MOVE       R4, R3
 14: SW         R4, 1(FP)
 15: LW         R2, 0(FP)
 16: LW         R4, 1(FP)
 17: ADD        R5, R2, R4
 18: MOVE       R6, R5
 19: SW         R6, 2(FP)
 20: LW         R6, 2(FP)
 21: OUTPUTREG  R6
 22: LW         R2, 0(FP)
 23: LW         R4, 1(FP)
 24: SUB        R7, R2, R4
 25: MOVE       R6, R7
 26: SW         R6, 2(FP)
 27: LW         R6, 2(FP)
 28: OUTPUTREG  R6
 29: LW         R2, 0(FP)
 30: LW         R4, 1(FP)
 31: MULT       R8, R2, R4
 32: MOVE       R6, R8
 33: SW         R6, 2(FP)
 34: LW         R6, 2(FP)
 35: OUTPUTREG  R6
 36: LW         R2, 0(FP)
 37: LW         R4, 1(FP)
 38: DIV        R9, R2, R4
 39: MOVE       R6, R9
 40: SW         R6, 2(FP)
 41: LW         R6, 2(FP)
 42: OUTPUTREG  R6
 43: LW         R2, 0(FP)
 44: LW         R4, 1(FP)
 45: BGTE       R2, R4, 49
 46: LI         R10, 1
 47: OUTPUTREG  R10
 48: J          51
L0:
 49: LI         R11, 0
 50: OUTPUTREG  R11
L1:
 51: LW         R2, 0(FP)
 52: LW         R4, 1(FP)
 53: BLTE       R2, R4, 57
 54: LI         R12, 1
 55: OUTPUTREG  R12
 56: J          59
L2:
 57: LI         R13, 0
 58: OUTPUTREG  R13
L3:
 59: LW         R2, 0(FP)
 60: LW         R4, 1(FP)
 61: BNE        R2, R4, 65
 62: LI         R14, 1
 63: OUTPUTREG  R14
 64: J          67
L4:
 65: LI         R15, 0
 66: OUTPUTREG  R15
L5:
 67: LW         R2, 0(FP)
 68: LW         R4, 1(FP)
 69: BEQ        R2, R4, 73
 70: LI         R16, 1
 71: OUTPUTREG  R16
 72: J          75
L6:
 73: LI         R17, 0
 74: OUTPUTREG  R17
L7:
 75: HALT      
