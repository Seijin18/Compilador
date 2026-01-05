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
  7: LI         R1, 0
  8: MOVE       R2, R1
  9: SW         R2, 0(FP)
 10: LI         R3, 0
 11: MOVE       R4, R3
 12: SW         R4, 1(FP)
L0:
 13: LI         R5, 10
 14: LW         R4, 1(FP)
 15: SLT        R6, R4, R5
 16: BEQ        R6, R0, 30
 17: LI         R7, 1
 18: LW         R2, 0(FP)
 19: ADD        R8, R2, R7
 20: MOVE       R2, R8
 21: SW         R2, 0(FP)
 22: LW         R2, 0(FP)
 23: OUTPUTREG  R2
 24: LI         R9, 1
 25: LW         R4, 1(FP)
 26: ADD        R10, R4, R9
 27: MOVE       R4, R10
 28: SW         R4, 1(FP)
 29: J          13
L1:
 30: LW         R2, 0(FP)
 31: OUTPUTREG  R2
 32: HALT      
