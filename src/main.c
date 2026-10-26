#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint8_t program[] = {1, 3, 3, 1, 1, 4, 9, 8, 11, 7, 2, 0};
    int pc = 0;
    int stack[256]; // stack[0]が一番下　staxk[sp-1]が一番上
    int sp = 0;     // stack pointer 空
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
        case 4: // sub
            if (sp < 2) {
                printf("error: stack underflow\n");
                running = 0;
                break;
            }
            stack[sp - 2] = stack[sp - 2] - stack[sp - 1];
            sp--;
            break;
        case 5: // mul
            if (sp < 2) {
                printf("error: stack underflow\n");
                running = 0;
                break;
            }
            stack[sp - 2] = stack[sp - 2] * stack[sp - 1];
            sp--;
            break;
        case 6: // div
            if (sp < 2) {
                printf("error: stack underflow\n");
                running = 0;
                break;
            }
            if (stack[sp - 1] == 0) {
                printf("error: division by zero\n");
                running = 0;
                break;
            }
            stack[sp - 2] = stack[sp - 2] / stack[sp - 1];
            sp--;
            break;
        case 7: // jmp
            pc = program[pc];
            break;
        case 8: // jz
            if (sp < 1) {
                printf("error: stack underflow\n");
                running = 0;
                break;
            }
            sp--;
            if (stack[sp] == 0) {
                pc = program[pc];
            } else {
                pc++;
            }
            break;
        case 9:
            if (sp < 1) {
                printf("error: stack underflow\n");
                running = 0;
                break;
            }
            stack[sp] = stack[sp - 1];
            sp++;
            break;
        }
    }
    return 0;
}
