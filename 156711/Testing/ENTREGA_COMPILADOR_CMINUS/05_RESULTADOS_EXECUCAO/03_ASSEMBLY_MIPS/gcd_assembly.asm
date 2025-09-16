# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 144
  1: LI         SP, 255
  2: J          31
gcd:
  3: SUBI       SP, SP, 8
  4: SW         RA, 7(SP)
  5: SW         FP, 6(SP)
  6: MOVE       FP, SP
  7: SW         R4, 0(FP)
  8: SW         R5, 1(FP)
  9: LI         R1, 0
 10: LW         R2, 1(FP)
 11: BNE        R2, R1, 14
 12: LW         R3, 0(FP)
 13: MOVE       R1, R3
L0:
 14: LW         R3, 0(FP)
 15: LW         R2, 1(FP)
 16: DIV        R4, R3, R2
 17: LW         R2, 1(FP)
 18: MULT       R5, R4, R2
 19: LW         R3, 0(FP)
 20: SUB        R6, R3, R5
 21: LW         R2, 1(FP)
 22: MOVE       R4, R2
 23: MOVE       R5, R6
 24: JAL        3
 25: MOVE       R7, R1
 26: MOVE       R1, R7
L1:
 27: LW         RA, 7(SP)
 28: LW         FP, 6(SP)
 29: ADDI       SP, SP, 8
 30: JR         RA
main:
 31: SUBI       R2, SP, 2
 32: SW         FP, 0(R2)
 33: SUBI       SP, SP, 2
 34: MOVE       FP, SP
 35: INPUT      R8
 36: OUTPUTREG  R8
 37: MOVE       R9, R8
 38: SW         R9, 0(FP)
 39: INPUT      R10
 40: OUTPUTREG  R10
 41: MOVE       R11, R10
 42: SW         R11, 1(FP)
 43: LW         R9, 0(FP)
 44: MOVE       R4, R9
 45: LW         R11, 1(FP)
 46: MOVE       R5, R11
 47: JAL        3
 48: MOVE       R12, R1
 49: MOVE       R7, R1
 50: OUTPUTREG  R12
 51: HALT      
