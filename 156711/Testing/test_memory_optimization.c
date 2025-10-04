/* Teste de Otimização de Memória
 * 
 * Programa simples para validar:
 * 1. Array de 10 elementos ocupa 10 posições (não 40)
 * 2. GP fixo em 128 (0x80)
 * 3. Acesso correto aos elementos sem multiplicar por 4
 */

int arr[10];

void main(void) {
    int i;
    
    // Inicializar array
    i = 0;
    while (i < 10) {
        arr[i] = i * 11;  // arr[0]=0, arr[1]=11, arr[2]=22, ...
        i = i + 1;
    }
    
    // Ler e exibir valores
    i = 0;
    while (i < 10) {
        output(arr[i]);
        i = i + 1;
    }
}
