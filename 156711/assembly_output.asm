# Assembly Corrigido - Processador MIPS Customizado
# Implementa:
# - Gerenciamento de pilha com Frame Pointer
# - Suporte a arrays
# - Variáveis globais com $gp
# - Passagem robusta de parâmetros

  0: LI         GP, 128
  1: LI         SP, 255
  2: J          3
main:
  3: SUBI       R26, SP, 2
  4: SW         FP, 0(R26)
  5: SUBI       SP, SP, 2
  6: MOVE       FP, SP
  7: LI         R1, 0
  8: MOVE       R2, R1
  9: SW         R2, 1(FP)
L0:
 10: LI         R3, 1
 11: BEQ        R3, R0, 77
 12: READ_KEYPAD
 13: MOVE       R5, R4
 14: SW         R5, 0(FP)
 15: LW         R5, 0(FP)
 16: LW         R2, 1(FP)
 17: BEQ        R5, R2, 76
 18: LI         R6, 0
 19: LW         R2, 1(FP)
 20: BEQ        R2, R6, 24
 21: LI         R7, 32
 22: UART_WRITE_CHAR R7, R0
 23: J          24
L4:
L5:
 24: LI         R8, 2
 25: LW         R5, 0(FP)
 26: BNE        R5, R8, 30
 27: LI         R9, 87
 28: UART_WRITE_CHAR R9, R0
 29: J          72
L6:
 30: LI         R10, 32
 31: LW         R5, 0(FP)
 32: BNE        R5, R10, 36
 33: LI         R11, 83
 34: UART_WRITE_CHAR R11, R0
 35: J          72
L8:
 36: LI         R12, 16
 37: LW         R5, 0(FP)
 38: BNE        R5, R12, 42
 39: LI         R13, 65
 40: UART_WRITE_CHAR R13, R0
 41: J          72
L10:
 42: LI         R14, 64
 43: LW         R5, 0(FP)
 44: BNE        R5, R14, 48
 45: LI         R15, 68
 46: UART_WRITE_CHAR R15, R0
 47: J          72
L12:
 48: LI         R16, 1
 49: LW         R5, 0(FP)
 50: BNE        R5, R16, 54
 51: LI         R17, 81
 52: UART_WRITE_CHAR R17, R0
 53: J          72
L14:
 54: LI         R18, 4
 55: LW         R5, 0(FP)
 56: BNE        R5, R18, 60
 57: LI         R19, 69
 58: UART_WRITE_CHAR R19, R0
 59: J          72
L16:
 60: LI         R20, 16384
 61: LW         R5, 0(FP)
 62: BNE        R5, R20, 66
 63: LI         R21, 70
 64: UART_WRITE_CHAR R21, R0
 65: J          72
L18:
 66: LI         R22, 4096
 67: LW         R5, 0(FP)
 68: BNE        R5, R22, 72
 69: LI         R23, 82
 70: UART_WRITE_CHAR R23, R0
 71: J          72
L20:
L21:
L19:
L17:
L15:
L13:
L11:
L9:
L7:
 72: LW         R5, 0(FP)
 73: MOVE       R2, R5
 74: SW         R2, 1(FP)
 75: J          76
L2:
L3:
 76: J          10
L1:
 77: HALT      
