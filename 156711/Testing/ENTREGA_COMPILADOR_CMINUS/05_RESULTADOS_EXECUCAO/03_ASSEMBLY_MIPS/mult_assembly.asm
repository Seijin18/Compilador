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
L0:
 15: LW         R5, 2(FP)
 16: LW         R4, 1(FP)
 17: SLT        R6, R5, R4
 18: BEQ        R6, R0, 30
 19: LI         R7, 1
 20: LW         R2, 0(FP)
 21: ADD        R8, R2, R7
 22: MOVE       R2, R8
 23: SW         R2, 0(FP)
 24: LI         R9, 1
 25: LW         R5, 2(FP)
 26: ADD        R10, R5, R9
 27: MOVE       R5, R10
 28: SW         R5, 2(FP)
 29: J          15
L1:
 30: LW         R2, 0(FP)
 31: OUTPUTREG  R2
 32: HALT      
