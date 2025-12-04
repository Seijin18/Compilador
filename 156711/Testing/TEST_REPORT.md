# Relatório de Teste de Integração do Compilador

**Data:** 02/12/2025
**Teste:** Compilação de `CMinusCodes/gcd.c`
**Objetivo:** Verificar a geração de instruções nativas `INPUT`, `OUTPUTREG` e `HALT` para o processador MIPS customizado.

## 1. Procedimento
1.  Compilação do compilador e assembler via `Makefile`.
2.  Compilação do código fonte `CMinusCodes/gcd.c` para código intermediário.
3.  Tradução do código intermediário para Assembly MIPS customizado.

## 2. Resultados

### Geração de Código Intermediário
O arquivo `intermediate.txt` gerado mostra o uso correto das quadruplas de I/O:
```
(input, , ,t5)
(asn,t5, ,x)
...
(output,t7,0, )
```

### Geração de Assembly
O arquivo `assembly_output.asm` confirma a substituição de `syscall` por instruções nativas:

*   **Entrada de Dados (`input()`):**
    ```asm
    INPUT R8
    OUTPUTREG R8  ; Echo para confirmação visual
    ```
    *Opcode gerado:* 34 (0x22) - Correto conforme especificação.

*   **Saída de Dados (`output()`):**
    ```asm
    OUTPUTREG R12
    ```
    *Opcode gerado:* 32 (0x20) - Correto conforme especificação.

*   **Finalização (`main`):**
    ```asm
    HALT
    ```
    *Opcode gerado:* 30 (0x1E) - Correto conforme especificação.

## 3. Conclusão
As modificações no `assembler.c` e `bison.y` foram validadas com sucesso. O compilador agora gera código totalmente compatível com o hardware do processador MIPS customizado, eliminando dependências de chamadas de sistema não suportadas.
