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
 29: HALT      
