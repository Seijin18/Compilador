int x;
int preemption;
int progs[10];

void scheduler(void) {
    int counter;
    int found;
    counter = 10;
    found = 0;
    while(counter > 0) {
        if(x > 9) x = 0;
        if(progs[x] == 1) {
            set_program(x);
            found = 1;
            counter = 0;
        } else {
            counter = counter - 1;
            if(counter > 0) x = x + 1;
        }
    }
    
    if(found == 1) {
        load_prog(x);
        restore_context();
        if(preemption == 1) {
            set_timer(100);
            enable_timer();
        }
        x = x + 1;
    } else {
        x = 0;
    }
    RETI();
}

void irq(void) {
    disable_timer();
    save_context();
    scheduler();
}

void halt(void) {
    disable_timer();
    progs[x] = 0;
    irq();
}

int main(void) {
    int i;
    i = 0;
    preemption = input();
    while(i < 10) {
        progs[i] = input();
        i = i + 1;
    }
    scheduler();
}
