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
 15: LI         R5, 0
 16: MOVE       R6, R5
 17: SW         R6, 2(FP)
L0:
 18: LW         R2, 0(FP)
 19: LW         R4, 1(FP)
 20: SLT        R7, R2, R4
 21: LI         R1, 1
 22: SUB        R7, R1, R7
 23: BEQ        R7, R0, 35
 24: LW         R2, 0(FP)
 25: LW         R4, 1(FP)
 26: SUB        R8, R2, R4
 27: MOVE       R2, R8
 28: SW         R2, 0(FP)
 29: LI         R9, 1
 30: LW         R6, 2(FP)
 31: ADD        R10, R6, R9
 32: MOVE       R6, R10
 33: SW         R6, 2(FP)
 34: J          18
L1:
 35: LW         R6, 2(FP)
 36: OUTPUTREG  R6
 37: HALT      
