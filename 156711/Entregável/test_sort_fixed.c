int vet[5];

int minloc(int a[], int low, int high) {
    int i; int x; int k;
    k = low;
    x = a[low];
    i = low + 1;
    while (i < high) {
        if (a[i] < x) {
            x = a[i];
            k = i;
        }
        i = i + 1;
    }
    return k;
}

void sort(int a[], int low, int high) {
    int i; int k;
    i = low;
    while (i < high - 1) {
        int t;
        k = minloc(a, i, high);
        t = a[k];
        a[k] = a[i];
        a[i] = t;
        i = i + 1;
    }
}

int main(void) {
    int i;
    vet[0] = 4;
    vet[1] = 2;
    vet[2] = 5;
    vet[3] = 1;
    vet[4] = 3;
    
    sort(vet, 0, 5);
    
    i = 0;
    while (i < 5) {
        output(vet[i]);
        i = i + 1;
    }
}
