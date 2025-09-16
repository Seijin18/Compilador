# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 140
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
 38: BGTE       R2, R4, 42
 39: LI         R9, 1
 40: OUTPUTREG  R9
 41: J          44
L0:
 42: LI         R10, 0
 43: OUTPUTREG  R10
L1:
 44: LW         R2, 0(FP)
 45: LW         R4, 1(FP)
 46: BLTE       R2, R4, 50
 47: LI         R11, 1
 48: OUTPUTREG  R11
 49: J          52
L2:
 50: LI         R12, 0
 51: OUTPUTREG  R12
L3:
 52: LW         R2, 0(FP)
 53: LW         R4, 1(FP)
 54: BNE        R2, R4, 58
 55: LI         R13, 1
 56: OUTPUTREG  R13
 57: J          60
L4:
 58: LI         R14, 0
 59: OUTPUTREG  R14
L5:
 60: LW         R2, 0(FP)
 61: LW         R4, 1(FP)
 62: BEQ        R2, R4, 66
 63: LI         R15, 1
 64: OUTPUTREG  R15
 65: J          68
L6:
 66: LI         R16, 0
 67: OUTPUTREG  R16
L7:
 68: HALT      
