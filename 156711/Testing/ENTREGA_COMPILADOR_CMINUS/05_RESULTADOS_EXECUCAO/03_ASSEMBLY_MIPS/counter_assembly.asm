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
 10: LI         R1, 0
 11: MOVE       R2, R1
 12: SW         R2, 0(FP)
 13: LI         R3, 0
 14: MOVE       R4, R3
 15: SW         R4, 1(FP)
L0:
 16: LI         R5, 10
 17: LW         R4, 1(FP)
 18: SLT        R6, R4, R5
 19: BEQ        R6, R0, 33
 20: LI         R7, 1
 21: LW         R2, 0(FP)
 22: ADD        R8, R2, R7
 23: MOVE       R2, R8
 24: SW         R2, 0(FP)
 25: LW         R2, 0(FP)
 26: OUTPUTREG  R2
 27: LI         R9, 1
 28: LW         R4, 1(FP)
 29: ADD        R10, R4, R9
 30: MOVE       R4, R10
 31: SW         R4, 1(FP)
 32: J          16
L1:
 33: LW         R2, 0(FP)
 34: OUTPUTREG  R2
 35: HALT      
