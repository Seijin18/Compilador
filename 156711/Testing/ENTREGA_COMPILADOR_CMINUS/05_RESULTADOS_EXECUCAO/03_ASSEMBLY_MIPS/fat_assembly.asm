# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 136
  1: LI         SP, 255
  2: J          26
fat:
  3: SUBI       SP, SP, 8
  4: SW         RA, 7(SP)
  5: SW         FP, 6(SP)
  6: MOVE       FP, SP
  7: SW         R4, 0(FP)
  8: LI         R1, 0
  9: LW         R2, 0(FP)
 10: BNE        R2, R1, 13
 11: LI         R3, 1
 12: MOVE       R1, R3
L0:
 13: LI         R4, 1
 14: LW         R2, 0(FP)
 15: SUB        R5, R2, R4
 16: MOVE       R4, R5
 17: JAL        3
 18: MOVE       R6, R1
 19: LW         R2, 0(FP)
 20: MULT       R7, R2, R6
 21: MOVE       R1, R7
L1:
 22: LW         RA, 7(SP)
 23: LW         FP, 6(SP)
 24: ADDI       SP, SP, 8
 25: JR         RA
main:
 26: SUBI       R2, SP, 2
 27: SW         FP, 0(R2)
 28: SUBI       SP, SP, 2
 29: MOVE       FP, SP
 30: INPUT      R8
 31: OUTPUTREG  R8
 32: MOVE       R2, R8
 33: SW         R2, 0(FP)
 34: LW         R2, 0(FP)
 35: MOVE       R4, R2
 36: JAL        3
 37: MOVE       R9, R1
 38: MOVE       R7, R1
 39: OUTPUTREG  R9
 40: HALT      
