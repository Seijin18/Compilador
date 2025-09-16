# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 144
  1: LI         SP, 255
  2: J          25
testscope:
  3: SUBI       SP, SP, 8
  4: SW         RA, 7(SP)
  5: SW         FP, 6(SP)
  6: MOVE       FP, SP
  7: SW         R4, 0(FP)
  8: SW         R5, 1(FP)
  9: LI         R1, 5
 10: LW         R2, 0(FP)
 11: ADD        R3, R2, R1
 12: MOVE       R4, R3
 13: SW         R4, 1(FP)
 14: LI         R5, 2
 15: LW         R4, 1(FP)
 16: MULT       R6, R4, R5
 17: MOVE       R7, R6
 18: SW         R7, 0(GP)
 19: LW         R4, 1(FP)
 20: MOVE       R1, R4
 21: LW         RA, 7(SP)
 22: LW         FP, 6(SP)
 23: ADDI       SP, SP, 8
 24: JR         RA
main:
 25: SUBI       R2, SP, 2
 26: SW         FP, 0(R2)
 27: SUBI       SP, SP, 2
 28: MOVE       FP, SP
 29: LI         R8, 100
 30: MOVE       R7, R8
 31: SW         R7, 0(GP)
 32: LI         R9, 10
 33: MOVE       R4, R9
 34: JAL        3
 35: MOVE       R10, R1
 36: MOVE       R7, R1
 37: MOVE       R11, R10
 38: SW         R11, 0(FP)
 39: LW         R11, 0(FP)
 40: OUTPUTREG  R11
 41: LW         R7, 0(GP)
 42: OUTPUTREG  R7
 43: LW         R7, 0(GP)
 44: LW         R11, 0(FP)
 45: ADD        R12, R7, R11
 46: MOVE       R7, R12
 47: SW         R7, 0(GP)
 48: LW         R7, 0(GP)
 49: OUTPUTREG  R7
 50: HALT      
