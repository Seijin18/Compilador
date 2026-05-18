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
  7: READ_KEYPAD
  8: MOVE       R2, R1
  9: SW         R2, 0(FP)
 10: HALT      
