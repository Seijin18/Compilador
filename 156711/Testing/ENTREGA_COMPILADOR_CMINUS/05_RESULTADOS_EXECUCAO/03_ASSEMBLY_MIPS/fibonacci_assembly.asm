# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 136
  1: LI         SP, 255
  2: J          31
fibonacci:
  3: SUBI       SP, SP, 8
  4: SW         RA, 7(SP)
  5: SW         FP, 6(SP)
  6: MOVE       FP, SP
  7: SW         R4, 0(FP)
  8: LI         R1, 1
  9: LW         R2, 0(FP)
 10: BLTE       R2, R1, 25
 11: LI         R3, 1
 12: LW         R2, 0(FP)
 13: SUB        R4, R2, R3
 14: MOVE       R4, R4
 15: JAL        3
 16: MOVE       R5, R1
 17: LI         R6, 2
 18: LW         R2, 0(FP)
 19: SUB        R7, R2, R6
 20: MOVE       R4, R7
 21: JAL        3
 22: MOVE       R8, R1
 23: ADD        R9, R5, R8
 24: MOVE       R1, R9
L0:
 25: LW         R2, 0(FP)
 26: MOVE       R1, R2
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
 35: INPUT      R10
 36: OUTPUTREG  R10
 37: MOVE       R2, R10
 38: SW         R2, 0(FP)
 39: LW         R2, 0(FP)
 40: MOVE       R4, R2
 41: JAL        3
 42: MOVE       R11, R1
 43: MOVE       R7, R1
 44: OUTPUTREG  R11
 45: HALT      
