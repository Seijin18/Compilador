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
  7: LI         R1, 10
  8: LI         R2, 0
  9: SLL        R3, R2, 2
 10: ADDI       R0, GP, 0
 11: ADD        R1, R1, R3
 12: SW         R1, 0(R1)
 13: LI         R4, 20
 14: LI         R5, 1
 15: SLL        R3, R5, 2
 16: ADDI       R0, GP, 0
 17: ADD        R4, R4, R3
 18: SW         R4, 0(R4)
 19: LI         R6, 30
 20: LI         R7, 2
 21: SLL        R3, R7, 2
 22: ADDI       R0, GP, 0
 23: ADD        R6, R6, R3
 24: SW         R6, 0(R6)
 25: LI         R2, 0
 26: SLL        R3, R2, 2
 27: ADDI       R0, GP, 0
 28: ADD        R8, R8, R3
 29: LW         R0, 0(R8)
 30: OUTPUTREG  R8
 31: LI         R5, 1
 32: SLL        R3, R5, 2
 33: ADDI       R0, GP, 0
 34: ADD        R9, R9, R3
 35: LW         R0, 0(R9)
 36: OUTPUTREG  R9
 37: LI         R7, 2
 38: SLL        R3, R7, 2
 39: ADDI       R0, GP, 0
 40: ADD        R10, R10, R3
 41: LW         R0, 0(R10)
 42: OUTPUTREG  R10
 43: HALT      
