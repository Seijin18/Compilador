# Assembly CORRIGIDO
# Processador MIPS Customizado
# Correções aplicadas nas inconsistências identificadas

  0: J           25
gcd:
  1: LW          R1, 1(R29)
  2: BNE         R1, R0, 6
  3: LW          R3, 0(R29)
  4: MOVE        R1, R3
  5: JR          R31
L0:
  6: LW          R3, 0(R29)
  7: LW          R1, 1(R29)
  8: DIV         R3, R1
  9: MFHI        R4
 10: LW          R1, 1(R29)
 11: MULT        R4, R1
 12: MFLO        R5
 13: LW          R3, 0(R29)
 14: SUB         R6, R3, R5
 15: SW          R6, 1(R29)
 16: LW          R1, 1(R29)
 17: SW          R1, 0(R29)
 18: SW          R31, 2(R29)
 19: JAL         1
 20: LW          R31, 2(R29)
 21: MOVE        R7, R1
 22: MOVE        R1, R7
 23: JR          R31
L1:
 24: JR          R31
main:
 25: INPUT       R8
 26: SW          R8, 0(R29)
 27: INPUT       R9
 28: SW          R9, 1(R29)
 29: LW          R10, 1(R29)
 30: SW          R10, 1(R29)
 31: LW          R11, 0(R29)
 32: SW          R11, 0(R29)
 33: SW          R31, 2(R29)
 34: JAL         1
 35: LW          R31, 2(R29)
 36: MOVE        R12, R1
 37: OUTPUTREG   R12
 38: HALT
