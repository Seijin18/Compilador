# Teste físico T2 (keypad → UART)

Use **`ardoomino_controller.c`** — mesmo firmware validado na simulação L3 (`tb_ardoomino_uart.v`).

```powershell
powershell -ExecutionPolicy Bypass -File C:\Projetos\ArDOOMino\scripts\build_rom.ps1 -Target controller
```

Não é necessário `keypad_uart_debug.c` separado: o controller já implementa `read_keypad` + `serial_write` com mapa tecla→ASCII.
