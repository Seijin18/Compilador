# Assembly Corrigido Manualmente - Processador MIPS Customizado
# Teste do test_global_array.c

  0: LI         GP, 128
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
 11: SW         R3, 0(GP)
 12: LI         R5, 20
 13: SW         R5, 1(GP)
 14: LI         R6, 30
 15: SW         R6, 2(GP)
 16: LW         R9, 0(GP)
 17: OUTPUTREG  R9
 18: LW         R11, 1(GP)
 19: OUTPUTREG  R11
 20: LW         R13, 2(GP)
 21: OUTPUTREG  R13
 22: HALT      