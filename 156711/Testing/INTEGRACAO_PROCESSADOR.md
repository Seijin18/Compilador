# Integração do Compilador C-Minus com Processador MIPS Customizado

Este documento detalha o estado atual do compilador C-Minus (localizado em `d:\Projetinhos\Compilador\156711\Testing`) e as modificações realizadas para integrá-lo totalmente ao processador MIPS customizado desenvolvido no Quartus.

## 1. Estado Atual do Compilador

O compilador é composto por três estágios principais:
1.  **Frontend (Léxico/Sintático):** Implementado em `bison.y`, `funcs.c` e `dfa.c`. Gera uma Árvore de Sintaxe Abstrata (AST).
2.  **Código Intermediário:** Implementado em `intermediate.c`. Percorre a AST e gera código de três endereços (Quadruplas).
3.  **Backend (Assembler):** Implementado em `assembler.c`. Traduz as quadruplas para instruções Assembly MIPS.

### Características Principais:
*   **Linguagem Fonte:** C-Minus (subset de C).
*   **Suporte:** Variáveis globais e locais, vetores, funções com parâmetros, controle de fluxo (if/else, while), recursão.
*   **Geração de Código:** Gera Assembly MIPS customizado, adaptado para o hardware FPGA.

## 2. Compatibilidade com o Processador

O processador MIPS customizado possui algumas particularidades que diferem do MIPS padrão (R2000/R3000) e que o compilador agora respeita.

### 2.1. Instruções Suportadas vs. Geradas

| Instrução MIPS Padrão | Processador Customizado | Status no Compilador | Observação |
| :--- | :--- | :--- | :--- |
| `ADD`, `SUB`, `AND`, `OR` | Suportado | **OK** | Nenhuma. |
| `MULT`, `DIV` | Suportado (32 bits result) | **OK** | O compilador usa `MFHI`/`MFLO` apenas quando necessário. |
| `LW`, `SW` | Suportado | **OK** | Nenhuma. |
| `BEQ`, `BNE` | Suportado | **OK** | Nenhuma. |
| `SLT` | Suportado | **OK** | Nenhuma. |
| `J`, `JAL`, `JR` | Suportado | **OK** | Nenhuma. |
| `ADDI` | Suportado | **OK** | Nenhuma. |
| `LI` (Pseudo) | Suportado (Hardware) | **OK** | O processador tem instrução `LI` nativa (Opcode `011011`). |
| `LA` (Pseudo) | Suportado (Hardware) | **OK** | O processador tem instrução `LA` nativa (Opcode `001110`). |
| `MOVE` (Pseudo) | Suportado (Hardware) | **OK** | O processador tem instrução `MOVE` nativa (Opcode `001011`). |
| `SYSCALL` | **NÃO SUPORTADO** | **REMOVIDO** | Substituído por `INPUT` e `OUTPUTREG`. |

### 2.2. Instruções Específicas do Processador (Implementadas)

O compilador agora suporta nativamente as instruções de I/O e Sistema:

*   `INPUT` (Opcode `100010`): Lê entrada dos switches.
*   `OUTPUTREG` (Opcode `100000`): Escreve registrador no display.
*   `HALT` (Opcode `011110`): Para o processador ao final da execução.

## 3. Mudanças Implementadas

As seguintes alterações foram realizadas e validadas:

### 3.1. Substituição de I/O
O compilador não utiliza mais chamadas de sistema (`syscall`).
*   **Implementação:**
    *   `input()` em C-Minus gera a instrução `INPUT $reg` seguida de `OUTPUTREG $reg` (echo).
    *   `output(x)` em C-Minus gera a instrução `OUTPUTREG $reg`.

### 3.2. Mapeamento de Opcodes
O `assembler.c` foi atualizado para garantir que os opcodes binários correspondam exatamente à tabela do processador (`Controle.v`):
*   `LI`: `011011` (27)
*   `LA`: `001110` (14)
*   `MOVE`: `001011` (11)
*   `HALT`: `011110` (30)
*   `INPUT`: `100010` (34)
*   `OUTPUTREG`: `100000` (32)

### 3.3. Finalização de Programa
A função `main` agora termina automaticamente com a instrução `HALT`, garantindo que o processador pare de executar instruções inválidas após o término do programa.

## 4. Validação

A integração foi validada com o teste `CMinusCodes/gcd.c` (MDC).

### Resultados do Teste (02/12/2025)
*   **Compilação:** Sucesso.
*   **Geração de Assembly:** O arquivo `assembly_output.asm` contém as instruções corretas:
    ```asm
    INPUT R8
    OUTPUTREG R8
    ...
    OUTPUTREG R12
    HALT
    ```
*   **Conclusão:** O compilador está pronto para uso com o processador customizado.

## 5. Próximos Passos (Opcionais)

*   **Suporte a Interrupções:** Para desenvolvimento de SO, adicionar suporte a instruções privilegiadas (`RETI`, `SET_QUANTUM`) via *inline assembly* ou funções intrínsecas.
*   **Otimização de Registradores:** O alocador de registradores atual é funcional, mas pode ser otimizado para reduzir o uso de memória (spills).
