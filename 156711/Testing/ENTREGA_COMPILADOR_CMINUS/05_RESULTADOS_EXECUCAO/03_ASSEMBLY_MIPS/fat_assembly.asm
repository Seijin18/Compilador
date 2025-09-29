# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 136
  1: LI         SP, 255
  2: J          28
fat:
  3: SUBI       SP, SP, 8
  4: SW         RA, 7(SP)
  5: SW         FP, 6(SP)
  6: MOVE       FP, SP
  7: SW         R4, 0(FP)
  8: LI         R1, 0
  9: LW         R2, 0(FP)
 10: BNE        R2, R1, 14
 11: LI         R3, 1
 12: MOVE       R1, R3
 13: J          24
L0:
 14: LI         R4, 1
 15: LW         R2, 0(FP)
 16: SUB        R5, R2, R4
 17: MOVE       R4, R5
 18: JAL        3
 19: MOVE       R6, R1
 20: LW         R2, 0(FP)
 21: MULT       R7, R2, R6
 22: MOVE       R1, R7
 23: J          24
L1:
fat_epilogue:
 24: LW         RA, 7(SP)
 25: LW         FP, 6(SP)
 26: ADDI       SP, SP, 8
 27: JR         RA
main:
 28: SUBI       R2, SP, 2
 29: SW         FP, 0(R2)
 30: SUBI       SP, SP, 2
 31: MOVE       FP, SP
 32: INPUT      R8
 33: OUTPUTREG  R8
 34: MOVE       R2, R8
 35: SW         R2, 0(FP)
 36: LW         R2, 0(FP)
 37: MOVE       R4, R2
 38: JAL        3
 39: MOVE       R9, R1
 40: MOVE       R7, R1
 41: OUTPUTREG  R9
 42: HALT      
