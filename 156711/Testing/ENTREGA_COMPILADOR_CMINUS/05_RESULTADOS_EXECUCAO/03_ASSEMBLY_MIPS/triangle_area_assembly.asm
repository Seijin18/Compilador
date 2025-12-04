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
 19: LW         R4, 1(FP)
 20: MULT       R5, R2, R4
 21: LI         R6, 2
 22: DIV        R7, R5, R6
 23: OUTPUTREG  R7
 24: HALT      
