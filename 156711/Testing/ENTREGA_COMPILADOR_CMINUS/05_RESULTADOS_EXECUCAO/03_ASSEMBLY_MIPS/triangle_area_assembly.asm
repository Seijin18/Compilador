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
 17: MULT       R5, R2, R4
 18: LI         R6, 2
 19: DIV        R7, R5, R6
 20: OUTPUTREG  R7
 21: HALT      
