void main(void) {
    int key;
    int last;
    last = 0;
    while (1) {
        key = read_keypad();
        if (key != last) {
            if (last != 0) {
                serial_write(32);
            }
            if (key == 2) {
                serial_write(87);
            } else {
                if (key == 32) {
                    serial_write(83);
                } else {
                    if (key == 16) {
                        serial_write(65);
                    } else {
                        if (key == 64) {
                            serial_write(68);
                        } else {
                            if (key == 1) {
                                serial_write(81);
                            } else {
                                if (key == 4) {
                                    serial_write(69);
                                } else {
                                    if (key == 16384) {
                                        serial_write(70);
                                    } else {
                                        if (key == 4096) {
                                            serial_write(82);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            last = key;
        }
    }
}