# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 144
  1: LI         SP, 255
  2: J          3
main:
  3: SUBI       R2, SP, 2
  4: SW         FP, 0(R2)
  5: SUBI       SP, SP, 2
  6: MOVE       FP, SP
  7: LI         R1, 100
  8: LI         R2, 0
  9: SLL        R3, R2, 2
 10: ADDI       R4, GP, 0
 11: ADD        R4, R4, R3
 12: SW         R1, 0(R4)
 13: LI         R5, 200
 14: LI         R6, 1
 15: SLL        R7, R6, 2
 16: ADDI       R8, GP, 0
 17: ADD        R8, R8, R7
 18: SW         R5, 0(R8)
 19: LI         R9, 300
 20: LI         R10, 2
 21: SLL        R11, R10, 2
 22: ADDI       R12, GP, 0
 23: ADD        R12, R12, R11
 24: SW         R9, 0(R12)
 25: LI         R13, 400
 26: LI         R14, 3
 27: SLL        R15, R14, 2
 28: ADDI       R16, GP, 0
 29: ADD        R16, R16, R15
 30: SW         R13, 0(R16)
 31: LI         R17, 0
 32: SLL        R18, R17, 2
 33: ADDI       R19, GP, 0
 34: ADD        R19, R19, R18
 35: LW         R20, 0(R19)
 36: OUTPUTREG  R20
 37: LI         R21, 1
 38: SLL        R22, R21, 2
 39: ADDI       R23, GP, 0
 40: ADD        R23, R23, R22
 41: LW         R24, 0(R23)
 42: OUTPUTREG  R24
 43: LI         R25, 2
 44: SLL        R26, R25, 2
 45: ADDI       R27, GP, 0
 46: ADD        R27, R27, R26
 47: LW         R2, 0(R27)
 48: OUTPUTREG  R2
 49: LI         R3, 3
 50: SLL        R4, R3, 2
 51: ADDI       R1, GP, 0
 52: ADD        R1, R1, R4
 53: LW         R6, 0(R1)
 54: OUTPUTREG  R6
 55: HALT      
