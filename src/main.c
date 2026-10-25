#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint8_t program[] = {1, 2, 1, 3, 2, 3, 0};
    int pc = 0;
    int stack[256];
    int sp = 0;
    int running = 1;

    while (running) {
        uint8_t op = program[pc];
        pc++;
        switch (op) {
        case 0: // halt
            running = 0;
            break;
        case 1: // push
            stack[sp] = program[pc];
            sp++;
            pc++;
            break;
        case 2: // add
            if (sp < 2) {
                printf("error: stack underflow\n");
                running = 0;
                break;
            }
            stack[sp - 2] = stack[sp - 2] + stack[sp - 1];
            sp--;
            break;
        case 3: // print
            if (sp < 1) {
                printf("error: stack underflow\n");
                running = 0;
                break;
            }
            printf("%d\n", stack[sp - 1]);
            break;
        }
    }
    return 0;
}
