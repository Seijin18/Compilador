# Assembly gerado automaticamente
# Processador MIPS Customizado
# Assembler Avançado com suporte a funções

  0: J           21
gcd:
  1: LW          R1, 1(R29)
  2: BNE         R1, R0, 6
  3: LW          R2, 0(R29)
  4: MOVE        R1, R2
  5: JR          R31
L0:
  6: LW          R2, 0(R29)
  7: LW          R1, 1(R29)
  8: DIV         R2, R1
  9: MFLO        R3
 10: LW          R1, 1(R29)
 11: MULT        R3, R1
 12: MFLO        R4
 13: LW          R2, 0(R29)
 14: SUB         R5, R2, R4
 15: LW          R1, 1(R29)
 16: SUBI        R29, R29, 3
 17: SW          R1, 0(R29)
 18: SW          R5, 1(R29)
 19: SW          R31, 2(R29)
 20: JAL         1
 21: LW          R31, 2(R29)
 22: ADDI        R29, R29, 3
 23: MOVE        R6, R1
 24: MOVE        R1, R6
 25: JR          R31
L1:
 26: JR          R31
main:
 27: INPUT       R7
 28: SW          R7, 0(R29)
 29: INPUT       R8
 30: SW          R8, 1(R29)
 31: SUBI        R29, R29, 3
 32: SW          R7, 0(R29)
 33: SW          R8, 1(R29)
 34: SW          R31, 2(R29)
 35: JAL         1
 36: LW          R31, 2(R29)
 37: ADDI        R29, R29, 3
 38: MOVE        R9, R1
 39: OUTPUTREG   R9
 40: HALT        
