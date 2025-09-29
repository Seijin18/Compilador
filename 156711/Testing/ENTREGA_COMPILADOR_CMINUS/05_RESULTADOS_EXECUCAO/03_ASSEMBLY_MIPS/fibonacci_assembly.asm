# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 136
  1: LI         SP, 255
  2: J          33
fibonacci:
  3: SUBI       SP, SP, 8
  4: SW         RA, 7(SP)
  5: SW         FP, 6(SP)
  6: MOVE       FP, SP
  7: SW         R4, 0(FP)
  8: LI         R1, 1
  9: LW         R2, 0(FP)
 10: BLTE       R2, R1, 26
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
 25: J          29
L0:
 26: LW         R2, 0(FP)
 27: MOVE       R1, R2
 28: J          29
L1:
fibonacci_epilogue:
 29: LW         RA, 7(SP)
 30: LW         FP, 6(SP)
 31: ADDI       SP, SP, 8
 32: JR         RA
main:
 33: SUBI       R2, SP, 2
 34: SW         FP, 0(R2)
 35: SUBI       SP, SP, 2
 36: MOVE       FP, SP
 37: INPUT      R10
 38: OUTPUTREG  R10
 39: MOVE       R2, R10
 40: SW         R2, 0(FP)
 41: LW         R2, 0(FP)
 42: MOVE       R4, R2
 43: JAL        3
 44: MOVE       R11, R1
 45: MOVE       R7, R1
 46: OUTPUTREG  R11
 47: HALT      
