# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 128
  1: LI         SP, 255
  2: J          6
  3: ADD        R0, R0, R0
  4: J          0
  5: J          6
main:
  6: SUBI       R2, SP, 2
  7: SW         FP, 0(R2)
  8: SUBI       SP, SP, 2
  9: MOVE       FP, SP
 10: INPUT      R1
 11: OUTPUTREG  R1
 12: MOVE       R2, R1
 13: SW         R2, 0(FP)
 14: INPUT      R3
 15: OUTPUTREG  R3
 16: MOVE       R4, R3
 17: SW         R4, 1(FP)
 18: LW         R2, 0(FP)
 19: LW         R4, 1(FP)
 20: ADD        R5, R2, R4
 21: MOVE       R6, R5
 22: SW         R6, 2(FP)
 23: LW         R6, 2(FP)
 24: OUTPUTREG  R6
 25: LW         R2, 0(FP)
 26: LW         R4, 1(FP)
 27: SUB        R7, R2, R4
 28: MOVE       R6, R7
 29: SW         R6, 2(FP)
 30: LW         R6, 2(FP)
 31: OUTPUTREG  R6
 32: LW         R2, 0(FP)
 33: LW         R4, 1(FP)
 34: MULT       R8, R2, R4
 35: MOVE       R6, R8
 36: SW         R6, 2(FP)
 37: LW         R6, 2(FP)
 38: OUTPUTREG  R6
 39: LW         R2, 0(FP)
 40: LW         R4, 1(FP)
 41: DIV        R9, R2, R4
 42: MOVE       R6, R9
 43: SW         R6, 2(FP)
 44: LW         R6, 2(FP)
 45: OUTPUTREG  R6
 46: LW         R2, 0(FP)
 47: LW         R4, 1(FP)
 48: BGTE       R2, R4, 52
 49: LI         R10, 1
 50: OUTPUTREG  R10
 51: J          54
L0:
 52: LI         R11, 0
 53: OUTPUTREG  R11
L1:
 54: LW         R2, 0(FP)
 55: LW         R4, 1(FP)
 56: BLTE       R2, R4, 60
 57: LI         R12, 1
 58: OUTPUTREG  R12
 59: J          62
L2:
 60: LI         R13, 0
 61: OUTPUTREG  R13
L3:
 62: LW         R2, 0(FP)
 63: LW         R4, 1(FP)
 64: BNE        R2, R4, 68
 65: LI         R14, 1
 66: OUTPUTREG  R14
 67: J          70
L4:
 68: LI         R15, 0
 69: OUTPUTREG  R15
L5:
 70: LW         R2, 0(FP)
 71: LW         R4, 1(FP)
 72: BEQ        R2, R4, 76
 73: LI         R16, 1
 74: OUTPUTREG  R16
 75: J          78
L6:
 76: LI         R17, 0
 77: OUTPUTREG  R17
L7:
 78: HALT      
