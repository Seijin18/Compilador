# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 128
  1: LI         SP, 255
  2: J          51
gcd:
  3: SUBI       R2, SP, 1
  4: SW         RA, 0(R2)
  5: SUBI       R2, SP, 2
  6: SW         FP, 0(R2)
  7: SUBI       SP, SP, 8
  8: ADDI       FP, SP, 4
  9: SW         R4, 0(FP)
 10: SW         R5, 1(FP)
 11: LI         R1, 0
 12: LW         R2, 1(FP)
 13: BNE        R2, R1, 23
 14: LW         R3, 0(FP)
 15: MOVE       R1, R3
 16: ADDI       SP, FP, 4
 17: SUBI       R2, SP, 2
 18: LW         FP, 0(R2)
 19: SUBI       R2, SP, 1
 20: LW         RA, 0(R2)
 21: ADDI       SP, SP, 8
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
 32: LW         R2, 1(FP)
 33: MOVE       R4, R2
 34: MOVE       R5, R6
 35: JAL        3
 36: MOVE       R7, R1
 37: MOVE       R1, R7
 38: ADDI       SP, FP, 4
 39: SUBI       R2, SP, 2
 40: LW         FP, 0(R2)
 41: SUBI       R2, SP, 1
 42: LW         RA, 0(R2)
 43: ADDI       SP, SP, 8
 44: JR         RA
L1:
 45: ADDI       SP, FP, 4
 46: SUBI       R2, SP, 2
 47: LW         FP, 0(R2)
 48: SUBI       R2, SP, 1
 49: LW         RA, 0(R2)
 50: ADDI       SP, SP, 8
main:
 51: SUBI       R2, SP, 2
 52: SW         FP, 0(R2)
 53: SUBI       SP, SP, 2
 54: MOVE       FP, SP
 55: INPUT      R8
 56: MOVE       R9, R8
 57: SW         R9, 0(FP)
 58: INPUT      R10
 59: MOVE       R11, R10
 60: SW         R11, 1(FP)
 61: LW         R9, 0(FP)
 62: MOVE       R4, R9
 63: LW         R11, 1(FP)
 64: MOVE       R5, R11
 65: JAL        3
 66: MOVE       R12, R1
 67: MOVE       R7, R1
 68: OUTPUTREG  R7
 69: HALT      
