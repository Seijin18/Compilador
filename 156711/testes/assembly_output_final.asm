# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 128
  1: LI         SP, 255
  2: J          55
gcd:
  3: SUBI       R2, SP, 1
  4: SW         RA, 0(R2)
  5: SUBI       R2, SP, 2
  6: SW         FP, 0(R2)
  7: SUBI       SP, SP, 2
  8: MOVE       FP, SP
  9: SUBI       R2, SP, 1
 10: SW         RA, 0(R2)
 11: SUBI       R2, SP, 2
 12: SW         FP, 0(R2)
 13: SUBI       SP, SP, 2
 14: MOVE       FP, SP
 15: SW         R4, 0(FP)
 16: SW         R5, 1(FP)
 17: LI         R1, 0
 18: LW         R2, 1(FP)
 19: BNE        R2, R1, 23
 20: LW         R3, 0(FP)
 21: MOVE       R1, R3
 22: JR         RA
L0:
 23: LW         R3, 0(FP)
 24: LW         R2, 1(FP)
 25: DIV        R3, R2
 26: MFLO       R4
 27: LW         R2, 1(FP)
 28: MULT       R4, R2
 29: MFLO       R5
 30: LW         R3, 0(FP)
 31: SUB        R6, R3, R5
 32: SUBI       R2, FP, 3
 33: SW         RA, 0(R2)
 34: LW         R2, 1(FP)
 35: MOVE       R4, R2
 36: MOVE       R5, R6
 37: JAL        3
 38: SUBI       R2, FP, 3
 39: LW         RA, 0(R2)
 40: MOVE       R7, R1
 41: MOVE       R1, R7
 42: JR         RA
L1:
 43: MOVE       SP, FP
 44: SUBI       R2, SP, 2
 45: LW         FP, 0(R2)
 46: SUBI       R2, SP, 1
 47: LW         RA, 0(R2)
 48: ADDI       SP, SP, 2
 49: MOVE       SP, FP
 50: SUBI       R2, SP, 2
 51: LW         FP, 0(R2)
 52: SUBI       R2, SP, 1
 53: LW         RA, 0(R2)
 54: ADDI       SP, SP, 2
main:
 55: SUBI       R2, SP, 1
 56: SW         RA, 0(R2)
 57: SUBI       R2, SP, 2
 58: SW         FP, 0(R2)
 59: SUBI       SP, SP, 2
 60: MOVE       FP, SP
 61: SUBI       R2, SP, 2
 62: SW         FP, 0(R2)
 63: SUBI       SP, SP, 2
 64: MOVE       FP, SP
 65: INPUT      R8
 66: MOVE       R9, R8
 67: SW         R9, 0(FP)
 68: INPUT      R10
 69: MOVE       R11, R10
 70: SW         R11, 1(FP)
 71: SUBI       R2, FP, 3
 72: SW         RA, 0(R2)
 73: LW         R9, 0(FP)
 74: MOVE       R4, R9
 75: LW         R11, 1(FP)
 76: MOVE       R5, R11
 77: JAL        3
 78: SUBI       R2, FP, 3
 79: LW         RA, 0(R2)
 80: MOVE       R12, R1
 81: OUTPUTREG  R7
 82: HALT      
 83: MOVE       SP, FP
 84: SUBI       R2, SP, 2
 85: LW         FP, 0(R2)
 86: SUBI       R2, SP, 1
 87: LW         RA, 0(R2)
 88: ADDI       SP, SP, 2
