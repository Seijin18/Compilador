# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 164
  1: LI         SP, 255
  2: J          61
add:
  3: SUBI       SP, SP, 8
  4: SW         RA, 7(SP)
  5: SW         FP, 6(SP)
  6: MOVE       FP, SP
  7: SW         R4, 0(FP)
  8: SW         R5, 1(FP)
  9: LW         R1, 0(FP)
 10: LW         R2, 1(FP)
 11: ADD        R3, R1, R2
 12: MOVE       R1, R3
 13: LW         RA, 7(SP)
 14: LW         FP, 6(SP)
 15: ADDI       SP, SP, 8
 16: JR         RA
multiply:
 17: SUBI       SP, SP, 8
 18: SW         RA, 7(SP)
 19: SW         FP, 6(SP)
 20: MOVE       FP, SP
 21: SW         R4, 0(FP)
 22: SW         R5, 1(FP)
 23: LW         R4, 0(FP)
 24: LW         R5, 1(FP)
 25: MULT       R6, R4, R5
 26: MOVE       R1, R6
 27: LW         RA, 7(SP)
 28: LW         FP, 6(SP)
 29: ADDI       SP, SP, 8
 30: JR         RA
calculate:
 31: SUBI       SP, SP, 8
 32: SW         RA, 7(SP)
 33: SW         FP, 6(SP)
 34: MOVE       FP, SP
 35: SW         R4, 0(FP)
 36: SW         R5, 1(FP)
 37: SW         R6, 2(FP)
 38: SW         R7, 3(FP)
 39: LW         R7, 0(FP)
 40: MOVE       R4, R7
 41: LW         R8, 1(FP)
 42: MOVE       R5, R8
 43: JAL        3
 44: MOVE       R9, R1
 45: MOVE       R10, R9
 46: SW         R10, 2(FP)
 47: LI         R11, 2
 48: LW         R10, 2(FP)
 49: MOVE       R4, R10
 50: MOVE       R5, R11
 51: JAL        17
 52: MOVE       R12, R1
 53: MOVE       R13, R12
 54: SW         R13, 3(FP)
 55: LW         R13, 3(FP)
 56: MOVE       R1, R13
 57: LW         RA, 7(SP)
 58: LW         FP, 6(SP)
 59: ADDI       SP, SP, 8
 60: JR         RA
main:
 61: SUBI       R2, SP, 2
 62: SW         FP, 0(R2)
 63: SUBI       SP, SP, 2
 64: MOVE       FP, SP
 65: LI         R14, 3
 66: LI         R15, 7
 67: MOVE       R4, R14
 68: MOVE       R5, R15
 69: JAL        31
 70: MOVE       R16, R1
 71: MOVE       R7, R1
 72: MOVE       R17, R16
 73: SW         R17, 0(FP)
 74: LW         R17, 0(FP)
 75: OUTPUTREG  R17
 76: HALT      
