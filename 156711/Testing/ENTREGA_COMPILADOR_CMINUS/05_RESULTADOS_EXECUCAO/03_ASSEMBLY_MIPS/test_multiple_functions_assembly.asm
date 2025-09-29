# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 164
  1: LI         SP, 255
  2: J          64
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
 13: J          14
add_epilogue:
 14: LW         RA, 7(SP)
 15: LW         FP, 6(SP)
 16: ADDI       SP, SP, 8
 17: JR         RA
multiply:
 18: SUBI       SP, SP, 8
 19: SW         RA, 7(SP)
 20: SW         FP, 6(SP)
 21: MOVE       FP, SP
 22: SW         R4, 0(FP)
 23: SW         R5, 1(FP)
 24: LW         R4, 0(FP)
 25: LW         R5, 1(FP)
 26: MULT       R6, R4, R5
 27: MOVE       R1, R6
 28: J          29
multiply_epilogue:
 29: LW         RA, 7(SP)
 30: LW         FP, 6(SP)
 31: ADDI       SP, SP, 8
 32: JR         RA
calculate:
 33: SUBI       SP, SP, 8
 34: SW         RA, 7(SP)
 35: SW         FP, 6(SP)
 36: MOVE       FP, SP
 37: SW         R4, 0(FP)
 38: SW         R5, 1(FP)
 39: SW         R6, 2(FP)
 40: SW         R7, 3(FP)
 41: LW         R7, 0(FP)
 42: MOVE       R4, R7
 43: LW         R8, 1(FP)
 44: MOVE       R5, R8
 45: JAL        3
 46: MOVE       R9, R1
 47: MOVE       R10, R9
 48: SW         R10, 2(FP)
 49: LI         R11, 2
 50: LW         R10, 2(FP)
 51: MOVE       R4, R10
 52: MOVE       R5, R11
 53: JAL        18
 54: MOVE       R12, R1
 55: MOVE       R13, R12
 56: SW         R13, 3(FP)
 57: LW         R13, 3(FP)
 58: MOVE       R1, R13
 59: J          60
calculate_epilogue:
 60: LW         RA, 7(SP)
 61: LW         FP, 6(SP)
 62: ADDI       SP, SP, 8
 63: JR         RA
main:
 64: SUBI       R2, SP, 2
 65: SW         FP, 0(R2)
 66: SUBI       SP, SP, 2
 67: MOVE       FP, SP
 68: LI         R14, 3
 69: LI         R15, 7
 70: MOVE       R4, R14
 71: MOVE       R5, R15
 72: JAL        33
 73: MOVE       R16, R1
 74: MOVE       R7, R1
 75: MOVE       R17, R16
 76: SW         R17, 0(FP)
 77: LW         R17, 0(FP)
 78: OUTPUTREG  R17
 79: HALT      
