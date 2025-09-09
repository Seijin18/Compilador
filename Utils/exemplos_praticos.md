# EXEMPLOS PRÁTICOS DE IMPLEMENTAÇÃO

## OPERAÇÕES LÓGICAS BÁSICAS

### 1. IMPLEMENTAÇÃO DE if (x == 0)

#### Código C- Original
```c
void main(void) {
    int x;
    x = input();
    
    if (x == 0) {
        output(1);    // Verdadeiro
    } else {
        output(0);    // Falso
    }
}
```

#### Código Intermediário Gerado
```
(goto,main, , )
(fun,main, , )
(input, , ,t0)
(asn,t0, ,x)
(==,x,0,t1)
(if_f,t1, ,L1)
(output,1, , )
(goto,L2, , )
(label,L1, , )
(output,0, , )
(label,L2, , )
(endfun, , , )
```

#### Assembly MIPS Gerado
```assembly
j main
main:
    # Input
    input $t0
    move $s0, $t0         # x = $s0
    
    # Comparação x == 0
    li $t1, 0
    beq $s0, $t1, L_true
    
    # Caso falso
    li $t2, 0
    outputreg $t2
    j L_end
    
L_true:
    # Caso verdadeiro
    li $t2, 1
    outputreg $t2
    
L_end:
    halt
```

#### Binário para Processador
```
01110000000000000000000000000001  ; J 1 (main)
10001000000000001000000000000000  ; INPUT $t0
00101100000010000000100000000000  ; MOVE $s0, $t0
01101100000000001000100000000000  ; LI $t1, 0
01001100010000001000100000000110  ; BEQ $s0, $t1, 6 (L_true)
01101100000000001001000000000000  ; LI $t2, 0
10000000001001000000000000000000  ; OUTPUTREG $t2
01110000000000000000000000001000  ; J 8 (L_end)
01101100000000001001000000000001  ; LI $t2, 1 (L_true)
10000000001001000000000000000000  ; OUTPUTREG $t2
01111000000000000000000000000000  ; HALT (L_end)
```

### 2. ADAPTAÇÕES PARA DIFERENTES COMPARAÇÕES

#### if (x > y)
```c
if (x > y) {
    output(1);
} else {
    output(0);
}
```

**Assembly:**
```assembly
bgt $x, $y, L_true
li $t0, 0
outputreg $t0
j L_end
L_true:
    li $t0, 1
    outputreg $t0
L_end:
```

#### if (x != y)
```c
if (x != y) {
    output(1);
} else {
    output(0);
}
```

**Assembly:**
```assembly
bne $x, $y, L_true
li $t0, 0
outputreg $t0
j L_end
L_true:
    li $t0, 1
    outputreg $t0
L_end:
```

#### Tabela de Mapeamento Completa
| Operador C- | Assembly MIPS | Opcode | Comportamento |
|-------------|---------------|--------|---------------|
| x == y | beq $x, $y, label | 010011 | Pula se x igual a y |
| x != y | bne $x, $y, label | 010100 | Pula se x diferente de y |
| x > y | bgt $x, $y, label | 010101 | Pula se x maior que y |
| x >= y | bgte $x, $y, label | 010110 | Pula se x maior ou igual a y |
| x < y | blt $x, $y, label | 010111 | Pula se x menor que y |
| x <= y | blte $x, $y, label | 011000 | Pula se x menor ou igual a y |

### 3. ESTRUTURAS DE CONTROLE COMPLEXAS

#### if-else-if
```c
void classificar(void) {
    int nota;
    nota = input();
    
    if (nota >= 90) {
        output(4);        // A
    } else if (nota >= 80) {
        output(3);        // B
    } else if (nota >= 70) {
        output(2);        // C
    } else {
        output(1);        // D
    }
}
```

**Assembly Gerado:**
```assembly
classificar:
    input $s0             # nota = $s0
    
    # if (nota >= 90)
    li $t0, 90
    bgte $s0, $t0, L_A
    
    # else if (nota >= 80)
    li $t0, 80
    bgte $s0, $t0, L_B
    
    # else if (nota >= 70)
    li $t0, 70
    bgte $s0, $t0, L_C
    
    # else
    li $t1, 1
    outputreg $t1
    j L_end
    
L_A:
    li $t1, 4
    outputreg $t1
    j L_end
    
L_B:
    li $t1, 3
    outputreg $t1
    j L_end
    
L_C:
    li $t1, 2
    outputreg $t1
    
L_end:
    jr $ra
```

## OPERAÇÕES ARITMÉTICAS AVANÇADAS

### 4. MULTIPLICAÇÃO COMO SOMA REPETIDA

#### Implementação Simples
```c
int multiplicar(int a, int b) {
    int resultado = 0;
    int contador = 0;
    
    while (contador < b) {
        resultado = resultado + a;
        contador = contador + 1;
    }
    
    return resultado;
}
```

**Assembly:**
```assembly
multiplicar:
    # Parâmetros: $a0 = a, $a1 = b
    # Variáveis locais: $s0 = resultado, $s1 = contador
    
    li $s0, 0             # resultado = 0
    li $s1, 0             # contador = 0
    
L_loop:
    bgte $s1, $a1, L_end  # if (contador >= b) goto L_end
    
    add $s0, $s0, $a0     # resultado = resultado + a
    addi $s1, $s1, 1      # contador = contador + 1
    
    j L_loop
    
L_end:
    move $v0, $s0         # return resultado
    jr $ra
```

### 5. DIVISÃO POR SUBTRAÇÃO SUCESSIVA

#### Implementação
```c
int dividir(int dividendo, int divisor) {
    int quociente = 0;
    
    while (dividendo >= divisor) {
        dividendo = dividendo - divisor;
        quociente = quociente + 1;
    }
    
    return quociente;
}
```

**Assembly:**
```assembly
dividir:
    # $a0 = dividendo, $a1 = divisor
    # $s0 = quociente
    
    li $s0, 0             # quociente = 0
    
L_div_loop:
    blt $a0, $a1, L_div_end   # if (dividendo < divisor) goto end
    
    sub $a0, $a0, $a1     # dividendo = dividendo - divisor
    addi $s0, $s0, 1      # quociente = quociente + 1
    
    j L_div_loop
    
L_div_end:
    move $v0, $s0         # return quociente
    jr $ra
```

### 6. OPERAÇÕES COMPLEXAS USANDO BÁSICAS

#### Potenciação
```c
int potencia(int base, int expoente) {
    int resultado = 1;
    int i = 0;
    
    while (i < expoente) {
        resultado = resultado * base;
        i = i + 1;
    }
    
    return resultado;
}
```

#### Raiz Quadrada Inteira (por aproximação)
```c
int raiz_quadrada(int n) {
    int resultado = 0;
    int impar = 1;
    
    while (n >= impar) {
        n = n - impar;
        impar = impar + 2;
        resultado = resultado + 1;
    }
    
    return resultado;
}
```

#### Máximo Divisor Comum (Euclides)
```c
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```

**Assembly MDC:**
```assembly
mdc:
    # $a0 = a, $a1 = b
    
L_mdc_loop:
    beq $a1, $zero, L_mdc_end  # if (b == 0) goto end
    
    # Calcular a % b usando divisão
    move $t0, $a0         # temp = a
    move $t1, $a1         # temp_b = b
    
    # a % b = a - (a/b)*b
    div $a0, $a1          # Usar instrução DIV
    mfhi $t2              # quociente
    mflo $t3              # resto
    
    move $a0, $a1         # a = b
    move $a1, $t3         # b = resto
    
    j L_mdc_loop
    
L_mdc_end:
    move $v0, $a0         # return a
    jr $ra
```

### 7. EXEMPLO COMPLETO: CALCULADORA

#### Código C-
```c
void calculadora(void) {
    int a, b, op, resultado;
    
    a = input();          // Primeiro número
    b = input();          // Segundo número
    op = input();         // Operação (1=+, 2=-, 3=*, 4=/)
    
    if (op == 1) {
        resultado = a + b;
    } else if (op == 2) {
        resultado = a - b;
    } else if (op == 3) {
        resultado = a * b;
    } else if (op == 4) {
        resultado = a / b;
    } else {
        resultado = 0;    // Operação inválida
    }
    
    output(resultado);
}

void main(void) {
    calculadora();
}
```

#### Assembly Completo
```assembly
j main

calculadora:
    # Inputs
    input $s0             # a
    input $s1             # b  
    input $s2             # operação
    
    # Switch da operação
    li $t0, 1
    beq $s2, $t0, L_soma
    
    li $t0, 2
    beq $s2, $t0, L_subtracao
    
    li $t0, 3
    beq $s2, $t0, L_multiplicacao
    
    li $t0, 4
    beq $s2, $t0, L_divisao
    
    # Operação inválida
    li $s3, 0
    j L_output
    
L_soma:
    add $s3, $s0, $s1
    j L_output
    
L_subtracao:
    sub $s3, $s0, $s1
    j L_output
    
L_multiplicacao:
    mult $s0, $s1
    mflo $s3              # Parte baixa da multiplicação
    j L_output
    
L_divisao:
    div $s0, $s1
    mfhi $s3              # Quociente
    j L_output
    
L_output:
    outputreg $s3
    jr $ra

main:
    jal calculadora
    halt
```

### 8. TESTE DE VALIDAÇÃO COMPLETO

#### Programa de Teste Abrangente
```c
// teste_completo.c
int teste_aritmetica(int a, int b) {
    int soma, diff, mult, div;
    
    soma = a + b;
    diff = a - b;
    mult = a * b;
    div = a / b;
    
    output(soma);
    output(diff);
    output(mult);
    output(div);
    
    return soma + diff + mult + div;
}

int teste_logica(int x, int y) {
    if (x == y) {
        return 1;
    } else if (x > y) {
        return 2;
    } else if (x < y) {
        return 3;
    } else {
        return 0;
    }
}

void main(void) {
    int a, b, resultado;
    
    a = input();          // Ex: 10
    b = input();          // Ex: 3
    
    resultado = teste_aritmetica(a, b);
    output(resultado);    // Soma de todas as operações
    
    resultado = teste_logica(a, b);
    output(resultado);    // Resultado da comparação
}
```

#### Entrada e Saída Esperada
```
Input: 10, 3
Output: 
  13    (10 + 3)
  7     (10 - 3)
  30    (10 * 3)
  3     (10 / 3)
  53    (13 + 7 + 30 + 3)
  2     (10 > 3, então resultado = 2)
```

### 9. DEBUGGING E VALIDAÇÃO

#### Checklist de Validação

1. **Operações Básicas**
   - [ ] Adição funciona corretamente
   - [ ] Subtração funciona corretamente
   - [ ] Multiplicação retorna resultado correto
   - [ ] Divisão calcula quociente e resto

2. **Comparações**
   - [ ] == (igualdade) funciona
   - [ ] != (diferente) funciona
   - [ ] >, >=, <, <= funcionam corretamente

3. **Estruturas de Controle**
   - [ ] if-else simples funciona
   - [ ] if-else-if múltiplo funciona
   - [ ] Loops while funcionam
   - [ ] Loops aninhados funcionam

4. **Funções**
   - [ ] Chamadas de função funcionam
   - [ ] Passagem de parâmetros funciona
   - [ ] Retorno de valores funciona
   - [ ] Recursão funciona (limitada)

#### Ferramentas de Debug

```bash
# Script de teste automatizado
#!/bin/bash

echo "=== TESTE DO SISTEMA COMPILADOR-PROCESSADOR ==="

# Teste 1: Operações básicas
echo "Teste 1: Operações aritméticas básicas"
echo "int a = 10, b = 3;" > teste1.c
echo "output(a + b); output(a - b); output(a * b); output(a / b);" >> teste1.c

# Teste 2: Comparações
echo "Teste 2: Operações lógicas"
echo "if (10 == 10) output(1); else output(0);" > teste2.c

# Teste 3: Loops
echo "Teste 3: Estruturas de repetição"
echo "int i = 1, sum = 0; while(i <= 5) { sum += i; i++; } output(sum);" > teste3.c

echo "Execute estes testes no simulador Quartus"
echo "Resultados esperados:"
echo "Teste 1: 13, 7, 30, 3"
echo "Teste 2: 1"
echo "Teste 3: 15"
```

Este documento fornece exemplos práticos completos para implementar e testar operações lógicas e aritméticas no sistema compilador-processador MIPS customizado.
