# Assembly gerado automaticamente
# Processador MIPS Customizado
# Assembler Corrigido

  0: J          26
gcd:
  1: LI         R1, 0
  2: LW         R2, 1(R29)
  3: BNE        R2, R1, 8
  4: LW         R3, 0(R29)
  5: MOVE       R1, R3
  6: LW         R31, 6(R29)
  7: JR         R31
L0:
  8: LW         R3, 0(R29)
  9: LW         R2, 1(R29)
 10: DIV        R3, R2
 11: MFHI       R4
 12: LW         R2, 1(R29)
 13: MULT       R4, R2
 14: MFLO       R5
 15: LW         R3, 0(R29)
 16: SUB        R6, R3, R5
 17: LW         R2, 1(R29)
 18: SW         R2, 0(R29)
 19: SW         R6, 1(R29)
 20: SW         R31, 8(R29)
 21: JAL        1
 22: MOVE       R7, R1
 23: MOVE       R1, R7
 24: LW         R31, 6(R29)
 25: JR         R31
L1:
main:
 26: INPUT      R8
 27: MOVE       R9, R8
 28: SW         R9, 0(R29)
 29: INPUT      R10
 30: MOVE       R11, R10
 31: SW         R11, 1(R29)
 32: LW         R9, 0(R29)
 33: SW         R9, 0(R29)
 34: LW         R11, 1(R29)
 35: SW         R11, 1(R29)
 36: SW         R31, 6(R29)
 37: JAL        1
 38: LW         R31, 6(R29)
 39: MOVE       R12, R1
 40: OUTPUTREG  R12
 41: JR         R31
 42: HALT
