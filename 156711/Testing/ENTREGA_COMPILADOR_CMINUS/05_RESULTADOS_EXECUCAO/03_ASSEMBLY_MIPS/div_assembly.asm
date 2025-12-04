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
 18: LI         R5, 0
 19: MOVE       R6, R5
 20: SW         R6, 2(FP)
L0:
 21: LW         R2, 0(FP)
 22: LW         R4, 1(FP)
 23: SLT        R7, R2, R4
 24: LI         R1, 1
 25: SUB        R7, R1, R7
 26: BEQ        R7, R0, 38
 27: LW         R2, 0(FP)
 28: LW         R4, 1(FP)
 29: SUB        R8, R2, R4
 30: MOVE       R2, R8
 31: SW         R2, 0(FP)
 32: LI         R9, 1
 33: LW         R6, 2(FP)
 34: ADD        R10, R6, R9
 35: MOVE       R6, R10
 36: SW         R6, 2(FP)
 37: J          21
L1:
 38: LW         R6, 2(FP)
 39: OUTPUTREG  R6
 40: HALT      
