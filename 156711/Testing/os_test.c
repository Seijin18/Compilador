void reti(void) { return; }
void enableTimer(void) { return; }
void disableTimer(void) { return; }
void setQuantum(int q) { return; }

void isr(void) {
    int x;
    x = 55; /* Write to R1 (which maps to R33 in OS mode) */
    output(x, 0);
    reti();
}

void main(void) {
    int i;
    i = 0;
    
    setQuantum(10);
    enableTimer();
    
    while(1) {
        i = i + 1;
    }
}
