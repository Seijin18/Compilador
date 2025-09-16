# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 196
  1: LI         SP, 255
  2: J          42
sumarray:
  3: SUBI       SP, SP, 8
  4: SW         RA, 7(SP)
  5: SW         FP, 6(SP)
  6: MOVE       FP, SP
  7: SW         R4, 0(FP)
  8: SW         R5, 1(FP)
  9: SW         R6, 2(FP)
 10: SW         R7, 3(FP)
 11: LI         R1, 0
 12: MOVE       R2, R1
 13: SW         R2, 3(FP)
 14: LI         R3, 0
 15: MOVE       R4, R3
 16: SW         R4, 2(FP)
L0:
 17: LW         R4, 2(FP)
 18: LW         R5, 1(FP)
 19: SLT        R6, R4, R5
 20: BEQ        R6, R0, 36
 21: LW         R4, 2(FP)
 22: SLL        R7, R4, 2
 23: LW         R8, 0(FP)
 24: ADD        R8, R8, R7
 25: LW         R9, 0(R8)
 26: LW         R2, 3(FP)
 27: ADD        R10, R2, R9
 28: MOVE       R2, R10
 29: SW         R2, 3(FP)
 30: LI         R11, 1
 31: LW         R4, 2(FP)
 32: ADD        R12, R4, R11
 33: MOVE       R4, R12
 34: SW         R4, 2(FP)
 35: J          17
L1:
 36: LW         R2, 3(FP)
 37: MOVE       R1, R2
 38: LW         RA, 7(SP)
 39: LW         FP, 6(SP)
 40: ADDI       SP, SP, 8
 41: JR         RA
main:
 42: SUBI       R2, SP, 2
 43: SW         FP, 0(R2)
 44: SUBI       SP, SP, 2
 45: MOVE       FP, SP
 46: LI         R13, 5
 47: LI         R14, 0
 48: SLL        R15, R14, 2
 49: ADDI       R16, GP, 0
 50: ADD        R16, R16, R15
 51: SW         R13, 0(R16)
 52: LI         R17, 10
 53: LI         R18, 1
 54: SLL        R19, R18, 2
 55: ADDI       R20, GP, 0
 56: ADD        R20, R20, R19
 57: SW         R17, 0(R20)
 58: LI         R21, 15
 59: LI         R22, 2
 60: SLL        R23, R22, 2
 61: ADDI       R24, GP, 0
 62: ADD        R24, R24, R23
 63: SW         R21, 0(R24)
 64: LI         R25, 3
 65: ADDI       R26, GP, 0
 66: MOVE       R4, R26
 67: MOVE       R5, R25
 68: JAL        3
 69: MOVE       R27, R1
 70: MOVE       R7, R1
 71: MOVE       R1, R27
 72: SW         R1, 0(FP)
 73: LW         R1, 0(FP)
 74: OUTPUTREG  R1
 75: HALT      
