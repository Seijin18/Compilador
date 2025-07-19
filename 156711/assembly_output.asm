# Assembly gerado automaticamente
# Processador MIPS Customizado
# Assembler Corrigido

  0: J          21
gcd:
  1: LI         R1, 0
  2: LW         R2, 1(R29)
  3: BNE        R2, R1, 7
  4: LW         R3, 0(R29)
  5: MOVE       R1, R3
  6: JR         R31
L0:
  7: DIV        R3, R2
  8: MFLO       R4
  9: MULT       R4, R2
 10: MFLO       R5
 11: SUB        R6, R3, R5
 12: SW         R2, 0(R29)
 13: SW         R6, 1(R29)
 14: SW         R31, 2(R29)
 15: JAL        1
 16: LW         R31, 2(R29)
 17: MOVE       R7, R1
 18: MOVE       R1, R7
 19: JR         R31
L1:
 20: JR         R31
main:
 21: INPUT      R8
 22: MOVE       R9, R8
 23: INPUT      R10
 24: MOVE       R11, R10
 25: SW         R9, 0(R29)
 26: SW         R11, 1(R29)
 27: SW         R31, 2(R29)
 28: JAL        1
 29: LW         R31, 2(R29)
 30: MOVE       R12, R1
 31: OUTPUTREG  R12
 32: JR         R31
 33: HALT
