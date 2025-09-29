# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 144
  1: LI         SP, 255
  2: J          26
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
 21: J          22
testscope_epilogue:
 22: LW         RA, 7(SP)
 23: LW         FP, 6(SP)
 24: ADDI       SP, SP, 8
 25: JR         RA
main:
 26: SUBI       R2, SP, 2
 27: SW         FP, 0(R2)
 28: SUBI       SP, SP, 2
 29: MOVE       FP, SP
 30: LI         R8, 100
 31: MOVE       R7, R8
 32: SW         R7, 0(GP)
 33: LI         R9, 10
 34: MOVE       R4, R9
 35: JAL        3
 36: MOVE       R10, R1
 37: MOVE       R7, R1
 38: MOVE       R11, R10
 39: SW         R11, 0(FP)
 40: LW         R11, 0(FP)
 41: OUTPUTREG  R11
 42: LW         R7, 0(GP)
 43: OUTPUTREG  R7
 44: LW         R7, 0(GP)
 45: LW         R11, 0(FP)
 46: ADD        R12, R7, R11
 47: MOVE       R7, R12
 48: SW         R7, 0(GP)
 49: LW         R7, 0(GP)
 50: OUTPUTREG  R7
 51: HALT      
