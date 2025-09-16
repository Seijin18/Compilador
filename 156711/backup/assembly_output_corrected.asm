# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 132
  1: LI         SP, 255
  2: J          3
main:
  3: SUBI       R2, SP, 2
  4: SW         FP, 0(R2)
  5: SUBI       SP, SP, 2
  6: MOVE       FP, SP
  7: LI         R1, 10
  8: MOVE       R2, R1
  9: SW         R2, 0(GP)
 10: LI         R3, 20
 11: MOVE       R2, R3
 12: SW         R2, 0(GP)
 13: LI         R4, 30
 14: MOVE       R2, R4
 15: SW         R2, 0(GP)
 16: LI         R5, 0
 17: SLL        R6, R6, 2
 18: ADDI       R6, GP, 0
 19: ADD        R6, R6, R6
 20: LW         R7, 0(R6)
 21: OUTPUTREG  R7
 22: LI         R8, 1
 23: SLL        R6, R6, 2
 24: ADDI       R6, GP, 0
 25: ADD        R6, R6, R6
 26: LW         R9, 0(R6)
 27: OUTPUTREG  R9
 28: LI         R10, 2
 29: SLL        R6, R6, 2
 30: ADDI       R6, GP, 0
 31: ADD        R6, R6, R6
 32: LW         R11, 0(R6)
 33: OUTPUTREG  R11
 34: HALT      
