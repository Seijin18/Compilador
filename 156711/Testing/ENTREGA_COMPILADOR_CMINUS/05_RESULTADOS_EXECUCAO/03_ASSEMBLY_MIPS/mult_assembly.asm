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
 18: LW         R2, 0(FP)
 19: MOVE       R5, R2
 20: SW         R5, 3(FP)
 21: LI         R6, 0
 22: MOVE       R2, R6
 23: SW         R2, 0(FP)
 24: LI         R7, 0
 25: MOVE       R8, R7
 26: SW         R8, 2(FP)
L0:
 27: LW         R8, 2(FP)
 28: LW         R4, 1(FP)
 29: SLT        R9, R8, R4
 30: BEQ        R9, R0, 42
 31: LW         R2, 0(FP)
 32: LW         R5, 3(FP)
 33: ADD        R10, R2, R5
 34: MOVE       R2, R10
 35: SW         R2, 0(FP)
 36: LI         R11, 1
 37: LW         R8, 2(FP)
 38: ADD        R12, R8, R11
 39: MOVE       R8, R12
 40: SW         R8, 2(FP)
 41: J          27
L1:
 42: LW         R2, 0(FP)
 43: OUTPUTREG  R2
 44: HALT      
