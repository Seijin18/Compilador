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
 16: MOVE       R5, R2
 17: SW         R5, 3(FP)
 18: LI         R6, 0
 19: MOVE       R2, R6
 20: SW         R2, 0(FP)
 21: LI         R7, 0
 22: MOVE       R8, R7
 23: SW         R8, 2(FP)
L0:
 24: LW         R8, 2(FP)
 25: LW         R4, 1(FP)
 26: SLT        R9, R8, R4
 27: BEQ        R9, R0, 39
 28: LW         R2, 0(FP)
 29: LW         R5, 3(FP)
 30: ADD        R10, R2, R5
 31: MOVE       R2, R10
 32: SW         R2, 0(FP)
 33: LI         R11, 1
 34: LW         R8, 2(FP)
 35: ADD        R12, R8, R11
 36: MOVE       R8, R12
 37: SW         R8, 2(FP)
 38: J          24
L1:
 39: LW         R2, 0(FP)
 40: OUTPUTREG  R2
 41: HALT      
