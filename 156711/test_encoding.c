// Simple test to verify parameter mapping in add_instruction
#include <stdio.h>
#include <stdint.h>

// Simulate the encoding logic
void test_encoding() {
    // Test parameters: opcode=0x1B, rs=0, rt=1, rd=0, immediate=0
    int opcode = 0x1B;
    int rs = 0;
    int rt = 1;
    int rd = 0;
    int immediate = 0;
    
    uint32_t machine_code = 0;
    
    // Formato: [31:26] OPCODE | [25:20] RS | [19:14] RT | [13:8] RD | [7:0] IMMEDIATE
    machine_code |= (opcode & 0x3F) << 26;
    machine_code |= (rs & 0x3F) << 20;
    machine_code |= (rt & 0x3F) << 14;
    machine_code |= (rd & 0x3F) << 8;
    machine_code |= (immediate & 0xFF);
    
    printf("Expected LI R1, 0 encoding:\n");
    printf("opcode=0x%02X, rs=%d, rt=%d, rd=%d, imm=%d\n", opcode, rs, rt, rd, immediate);
    printf("Binary: ");
    for (int bit = 31; bit >= 0; bit--) {
        printf("%d", (machine_code >> bit) & 1);
    }
    printf("\n");
    
    // Decode the actual output from our assembler
    uint32_t actual = 0b01101100000000000000000100000000;
    printf("\nActual output from assembler:\n");
    printf("Binary: 01101100000000000000000100000000\n");
    
    int actual_opcode = (actual >> 26) & 0x3F;
    int actual_rs = (actual >> 20) & 0x3F;
    int actual_rt = (actual >> 14) & 0x3F;
    int actual_rd = (actual >> 8) & 0x3F;
    int actual_imm = actual & 0xFF;
    
    printf("Decoded: opcode=0x%02X, rs=%d, rt=%d, rd=%d, imm=%d\n", 
           actual_opcode, actual_rs, actual_rt, actual_rd, actual_imm);
    
    printf("\nComparison:\n");
    printf("Opcode: expected=0x%02X, actual=0x%02X %s\n", opcode, actual_opcode, (opcode == actual_opcode) ? "✓" : "✗");
    printf("RS: expected=%d, actual=%d %s\n", rs, actual_rs, (rs == actual_rs) ? "✓" : "✗");
    printf("RT: expected=%d, actual=%d %s\n", rt, actual_rt, (rt == actual_rt) ? "✓" : "✗");
    printf("RD: expected=%d, actual=%d %s\n", rd, actual_rd, (rd == actual_rd) ? "✓" : "✗");
    printf("IMM: expected=%d, actual=%d %s\n", immediate, actual_imm, (immediate == actual_imm) ? "✓" : "✗");
}

int main() {
    test_encoding();
    return 0;
}
