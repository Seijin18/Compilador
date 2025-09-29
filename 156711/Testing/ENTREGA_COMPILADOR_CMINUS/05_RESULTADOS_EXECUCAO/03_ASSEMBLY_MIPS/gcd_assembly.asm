# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 144
  1: LI         SP, 255
  2: J          33
gcd:
  3: SUBI       SP, SP, 8
  4: SW         RA, 7(SP)
  5: SW         FP, 6(SP)
  6: MOVE       FP, SP
  7: SW         R4, 0(FP)
  8: SW         R5, 1(FP)
  9: LI         R1, 0
 10: LW         R2, 1(FP)
 11: BNE        R2, R1, 15
 12: LW         R3, 0(FP)
 13: MOVE       R1, R3
 14: J          29
L0:
 15: LW         R3, 0(FP)
 16: LW         R2, 1(FP)
 17: DIV        R4, R3, R2
 18: LW         R2, 1(FP)
 19: MULT       R5, R4, R2
 20: LW         R3, 0(FP)
 21: SUB        R6, R3, R5
 22: LW         R2, 1(FP)
 23: MOVE       R4, R2
 24: MOVE       R5, R6
 25: JAL        3
 26: MOVE       R7, R1
 27: MOVE       R1, R7
 28: J          29
L1:
gcd_epilogue:
 29: LW         RA, 7(SP)
 30: LW         FP, 6(SP)
 31: ADDI       SP, SP, 8
 32: JR         RA
main:
 33: SUBI       R2, SP, 2
 34: SW         FP, 0(R2)
 35: SUBI       SP, SP, 2
 36: MOVE       FP, SP
 37: INPUT      R8
 38: OUTPUTREG  R8
 39: MOVE       R9, R8
 40: SW         R9, 0(FP)
 41: INPUT      R10
 42: OUTPUTREG  R10
 43: MOVE       R11, R10
 44: SW         R11, 1(FP)
 45: LW         R9, 0(FP)
 46: MOVE       R4, R9
 47: LW         R11, 1(FP)
 48: MOVE       R5, R11
 49: JAL        3
 50: MOVE       R12, R1
 51: MOVE       R7, R1
 52: OUTPUTREG  R12
 53: HALT      
