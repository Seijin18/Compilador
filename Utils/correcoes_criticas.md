# CORREÇÕES CRÍTICAS E IMPLEMENTAÇÃO IMEDIATA

## PROBLEMAS IDENTIFICADOS E SOLUÇÕES

### 1. CORREÇÃO NA ULA - MULTIPLICAÇÃO E DIVISÃO

#### Problema Atual na ULA.v
```verilog
// CÓDIGO ATUAL (INCORRETO)
4'b0010: // MULT
    begin
    result_32 = in1 * in2;      // Só retorna 32 bits
    result_64 = 64'd0;          // Não usa HI:LO
    out1 = 1'b0;
    end

4'b0011: // DIV  
    begin
    result_32 = in1 / in2;      // Só retorna quociente
    result_64 = 64'd0;          // Não calcula resto
    out1 = 1'b0; 
    end
```

#### Solução Corrigida
```verilog
// CÓDIGO CORRIGIDO
4'b0010: // MULT
    begin
    result_64 = in1 * in2;              // Multiplicação completa 64-bit
    result_32 = result_64[31:0];        // LO = parte baixa
    out1 = 1'b0;
    sign_hilo = 1'b1;                   // Indica que HI:LO está válido
    end

4'b0011: // DIV
    begin
    if (in2 != 32'd0) begin             // Proteção divisão por zero
        result_64[63:32] = in1 / in2;   // HI = quociente  
        result_64[31:0] = in1 % in2;    // LO = resto
        result_32 = result_64[63:32];   // Retorna quociente por padrão
        sign_hilo = 1'b1;               // Indica que HI:LO está válido
    end else begin
        result_64 = 64'd0;              // Divisão por zero = 0
        result_32 = 32'd0;
        sign_hilo = 1'b0;
    end
    out1 = 1'b0;
    end
```

### 2. IMPLEMENTAÇÃO DE INSTRUÇÕES MFHI E MFLO

#### Verificação no Banco de Registradores
```verilog
// Em Registradores.v - verificar se está implementado:
always @(posedge clk) begin
    if (writeregs) begin
        case (controleRegInput)
            3'b110: registers[writeAddr] <= hi_reg;      // MFHI
            3'b111: registers[writeAddr] <= lo_reg;      // MFLO
            // ... outros casos
        endcase
    end
end

// Atualização de HI e LO após operações
always @(posedge clk) begin
    if (sign_hilo && writeregs) begin
        hi_reg <= out64ULA[63:32];    // Parte alta
        lo_reg <= out64ULA[31:0];     // Parte baixa  
    end
end
```

### 3. CORREÇÃO NO CONTROLE PARA MFHI/MFLO

#### Controle.v - Adicionar casos para MFHI e MFLO
```verilog
// MFHI (001001)
6'b001001:
    begin
    controleULA = 4'b0000;          // Operação passthrough
    controleImediato = 1'b0;
    controleWriteRegs = 1'b1;
    controleRegInput = 3'b110;      // Seleciona HI
    controleMemWrite = 1'b0;
    controleJump = 1'b0;
    controleBranch = 1'b0;
    movhi = 1'b1;                   // Sinal específico para MFHI
    movlo = 1'b0;
    rTD = 2'b10;                    // Destino = RD
    end

// MFLO (001010)  
6'b001010:
    begin
    controleULA = 4'b0000;          // Operação passthrough
    controleImediato = 1'b0;
    controleWriteRegs = 1'b1;
    controleRegInput = 3'b111;      // Seleciona LO
    controleMemWrite = 1'b0;
    controleJump = 1'b0;
    controleBranch = 1'b0;
    movhi = 1'b0;
    movlo = 1'b1;                   // Sinal específico para MFLO
    rTD = 2'b10;                    // Destino = RD
    end
```

### 4. CORREÇÃO NO ASSEMBLER PARA SUPORTE COMPLETO

#### Implementação de Multiplicação com HI/LO
```c
// Em assembler.c - função para multiplicação completa
void generate_multiplication_full(const char* rs, const char* rt, const char* rd_lo, const char* rd_hi) {
    // Gera multiplicação
    emit_instruction("MULT", rs, rt, "", "");
    
    // Move resultado para registradores
    if (rd_lo && strlen(rd_lo) > 0) {
        emit_instruction("MFLO", "", "", rd_lo, "");  // Parte baixa
    }
    if (rd_hi && strlen(rd_hi) > 0) {
        emit_instruction("MFHI", "", "", rd_hi, "");  // Parte alta
    }
}

// Função para divisão com resto
void generate_division_full(const char* rs, const char* rt, const char* rd_quot, const char* rd_rem) {
    // Gera divisão
    emit_instruction("DIV", rs, rt, "", "");
    
    // Move resultados
    if (rd_quot && strlen(rd_quot) > 0) {
        emit_instruction("MFHI", "", "", rd_quot, "");  // Quociente
    }
    if (rd_rem && strlen(rd_rem) > 0) {
        emit_instruction("MFLO", "", "", rd_rem, "");   // Resto
    }
}
```

### 5. EXTENSÃO DO CÓDIGO INTERMEDIÁRIO

#### Novas Quadruplas para Operações Complexas
```c
// Em intermediate.c - extensões para multiplicação e divisão
static char* genMultiplication(AASNode* node, FILE* out) {
    char* left = genNode(node->children, out);
    char* right = genNode(node->children->sibling, out);
    
    // Para números pequenos, usar multiplicação simples
    // Para números grandes, usar MULT + MFLO/MFHI
    char* temp_result = newTemp();
    char* temp_hi = newTemp();
    
    emitQuad("mult", left, right, temp_result);
    emitQuad("mflo", "", "", temp_result);      // Resultado principal
    emitQuad("mfhi", "", "", temp_hi);          // Overflow/parte alta
    
    return temp_result;
}

static char* genDivision(AASNode* node, FILE* out) {
    char* left = genNode(node->children, out);
    char* right = genNode(node->children->sibling, out);
    
    char* temp_quot = newTemp();
    char* temp_rem = newTemp();
    
    emitQuad("div", left, right, temp_quot);
    emitQuad("mfhi", "", "", temp_quot);        // Quociente
    emitQuad("mflo", "", "", temp_rem);         // Resto
    
    return temp_quot;  // Retorna quociente por padrão
}

// Função para módulo (resto da divisão)
static char* genModulo(AASNode* node, FILE* out) {
    char* left = genNode(node->children, out);
    char* right = genNode(node->children->sibling, out);
    
    char* temp_quot = newTemp();
    char* temp_rem = newTemp();
    
    emitQuad("div", left, right, temp_quot);
    emitQuad("mfhi", "", "", temp_quot);        // Quociente (não usado)
    emitQuad("mflo", "", "", temp_rem);         // Resto
    
    return temp_rem;  // Retorna resto
}
```

### 6. TESTE DE VALIDAÇÃO PARA MULTIPLICAÇÃO/DIVISÃO

#### Programa de Teste C-
```c
// teste_mult_div.c
void main(void) {
    int a, b;
    int mult_result, div_result, mod_result;
    
    a = input();  // Ex: 15
    b = input();  // Ex: 4
    
    mult_result = a * b;  // 15 * 4 = 60
    div_result = a / b;   // 15 / 4 = 3
    mod_result = a % b;   // 15 % 4 = 3 (resto)
    
    output(mult_result);  // Deve mostrar 60
    output(div_result);   // Deve mostrar 3
    output(mod_result);   // Deve mostrar 3
}
```

#### Assembly Esperado (após correções)
```assembly
# Input a
input $t0
move $s0, $t0       # a = $s0

# Input b  
input $t1
move $s1, $t1       # b = $s1

# Multiplicação: a * b
mult $s0, $s1       # HI:LO = a * b
mflo $t2            # $t2 = resultado multiplicação
outputreg $t2       # Output: 60

# Divisão: a / b
div $s0, $s1        # HI = a/b, LO = a%b  
mfhi $t3            # $t3 = quociente
outputreg $t3       # Output: 3

# Módulo: a % b
mflo $t4            # $t4 = resto
outputreg $t4       # Output: 3

halt
```

### 7. IMPLEMENTAÇÃO IMEDIATA - CHECKLIST

#### Arquivos a Modificar:

1. **ULA.v**
   - [ ] Corrigir operações MULT e DIV
   - [ ] Implementar suporte completo a HI:LO
   - [ ] Adicionar proteção divisão por zero

2. **Controle.v**
   - [ ] Adicionar casos para MFHI e MFLO
   - [ ] Configurar sinais de controle corretos

3. **Registradores.v**
   - [ ] Verificar atualização de HI e LO
   - [ ] Implementar MFHI/MFLO no multiplexador

4. **assembler.c**
   - [ ] Adicionar funções para mult/div completas
   - [ ] Implementar geração de MFHI/MFLO

5. **intermediate.c**
   - [ ] Estender geração para operações complexas
   - [ ] Adicionar suporte a módulo (%)

### 8. SCRIPT DE TESTE AUTOMATIZADO

```bash
#!/bin/bash
# test_corrections.sh

echo "Testando correções do sistema..."

# Compilar sistema
echo "1. Compilando compilador..."
bison -d bison.y
gcc -o compiler bison.tab.c funcs.c intermediate.c

echo "2. Compilando assembler..."
gcc -o assembler assembler.c

# Testar multiplicação/divisão
echo "3. Testando multiplicação e divisão..."
./compiler teste_mult_div.c
./assembler intermediate.txt

echo "4. Verificando código binário gerado..."
if [ -f "binary_output.txt" ]; then
    echo "✅ Binário gerado com sucesso"
    head -10 binary_output.txt
else
    echo "❌ Erro na geração do binário"
fi

echo "5. Carregar binary_output.txt no Quartus e testar..."
echo "   Inputs: 15, 4"  
echo "   Outputs esperados: 60, 3, 3"
```

### 9. CRONOGRAMA DE IMPLEMENTAÇÃO

#### Prioridade Alta (Implementar primeiro)
1. Correção ULA.v (MULT/DIV) - **2 horas**
2. Atualização Controle.v (MFHI/MFLO) - **1 hora** 
3. Teste básico multiplicação - **30 min**

#### Prioridade Média  
4. Extensão assembler.c - **3 horas**
5. Atualização intermediate.c - **2 horas**
6. Testes completos - **1 hora**

#### Prioridade Baixa
7. Otimizações adicionais
8. Documentação atualizada
9. Suite de testes ampliada

**Total estimado: 9.5 horas de implementação**
