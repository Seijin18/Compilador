# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 128
  1: LI         SP, 255
  2: J          39
gcd:
  3: SUBI       R2, SP, 1
  4: SW         RA, 0(R2)
  5: SUBI       R2, SP, 2
  6: SW         FP, 0(R2)
  7: SUBI       SP, SP, 2
  8: MOVE       FP, SP
  9: LI         R1, 0
 10: LW         R2, 1(FP)
 11: BNE        R2, R2, 15
 12: LW         R3, 0(FP)
 13: MOVE       R1, R1
 14: JR         RA
L0:
 15: LW         R3, 0(FP)
 16: LW         R2, 1(FP)
 17: DIV        R3, R3
 18: MFLO       R4
 19: LW         R2, 1(FP)
 20: MULT       R4, R4
 21: MFLO       R5
 22: LW         R3, 0(FP)
 23: SUB        R6, R6, R6
 24: SW         RA, 4(FP)
 25: LW         R2, 1(FP)
 26: MOVE       R4, R4
 27: MOVE       R5, R5
 28: JAL        3
 29: LW         RA, 4(FP)
 30: MOVE       R7, R7
 31: MOVE       R1, R1
 32: JR         RA
L1:
 33: MOVE       SP, FP
 34: SUBI       R2, SP, 2
 35: LW         FP, 0(R2)
 36: SUBI       R2, SP, 1
 37: LW         RA, 0(R2)
 38: ADDI       SP, SP, 2
main:
 39: SUBI       R2, SP, 1
 40: SW         RA, 0(R2)
 41: SUBI       R2, SP, 2
 42: SW         FP, 0(R2)
 43: SUBI       SP, SP, 2
 44: MOVE       FP, SP
 45: INPUT      R8
 46: SW         R8, 0(FP)
 47: INPUT      R9
 48: SW         R9, 1(FP)
 49: SW         RA, 4(FP)
 50: LW         R8, 0(FP)
 51: MOVE       R4, R4
 52: LW         R9, 1(FP)
 53: MOVE       R5, R5
 54: JAL        3
 55: LW         RA, 4(FP)
 56: MOVE       R10, R10
 57: OUTPUTREG  R10
 58: MOVE       SP, FP
 59: SUBI       R2, SP, 2
 60: LW         FP, 0(R2)
 61: SUBI       R2, SP, 1
 62: LW         RA, 0(R2)
 63: ADDI       SP, SP, 2
 64: HALT      
