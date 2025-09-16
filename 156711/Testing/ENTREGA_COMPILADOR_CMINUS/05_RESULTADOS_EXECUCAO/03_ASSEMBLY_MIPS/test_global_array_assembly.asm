# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 152
  1: LI         SP, 255
  2: J          3
main:
  3: SUBI       R2, SP, 2
  4: SW         FP, 0(R2)
  5: SUBI       SP, SP, 2
  6: MOVE       FP, SP
  7: LI         R1, 0
  8: MOVE       R2, R1
  9: SW         R2, 0(FP)
 10: LI         R3, 10
 11: LI         R4, 0
 12: SLL        R5, R4, 2
 13: ADDI       R6, GP, 0
 14: ADD        R6, R6, R5
 15: SW         R3, 0(R6)
 16: LI         R7, 20
 17: LI         R8, 1
 18: SLL        R9, R8, 2
 19: ADDI       R10, GP, 0
 20: ADD        R10, R10, R9
 21: SW         R7, 0(R10)
 22: LI         R11, 30
 23: LI         R12, 2
 24: SLL        R13, R12, 2
 25: ADDI       R14, GP, 0
 26: ADD        R14, R14, R13
 27: SW         R11, 0(R14)
 28: LI         R15, 0
 29: SLL        R16, R15, 2
 30: ADDI       R17, GP, 0
 31: ADD        R17, R17, R16
 32: LW         R18, 0(R17)
 33: OUTPUTREG  R18
 34: LI         R19, 1
 35: SLL        R20, R19, 2
 36: ADDI       R21, GP, 0
 37: ADD        R21, R21, R20
 38: LW         R22, 0(R21)
 39: OUTPUTREG  R22
 40: LI         R23, 2
 41: SLL        R24, R23, 2
 42: ADDI       R25, GP, 0
 43: ADD        R25, R25, R24
 44: LW         R26, 0(R25)
 45: OUTPUTREG  R26
 46: HALT      
