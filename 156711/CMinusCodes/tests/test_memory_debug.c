/* Teste simplificado para debugar corrupcao de memoria */
int data[4];

void main(void) {
    /* Inicializacao basica */
    data[0] = 100;  /* MEM[148] = 100 */
    data[1] = 200;  /* MEM[152] = 200 */  
    data[2] = 300;  /* MEM[156] = 300 */
    data[3] = 400;  /* MEM[160] = 400 */
    
    /* Teste de leitura imediata (sem operacoes intermediarias) */
    output(data[0]);  /* Deve ser 100 */
    output(data[1]);  /* Deve ser 200 */
    output(data[2]);  /* Deve ser 300 */
    output(data[3]);  /* Deve ser 400 */
}