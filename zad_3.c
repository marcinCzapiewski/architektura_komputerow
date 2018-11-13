#include <stdio.h>

int main() {
    char *s = "Abc";
    int y;

    asm volatile (
        ".intel_syntax noprefix;"
        "mov ebx, %1;"
        "xor ecx, ecx;"
        "petla:"
        "mov al, [ebx];"
        "cmp al, 0;"
        "je koniec;"
        "inc ecx;"
        "inc ebx;"
        "jmp petla;"
        "koniec:"
        "mov %0, ecx;"
        ".att_syntax prefix;"
            :"=r"(y)
            :"r"(s)
            :"eax", "ebx", "ecx"
    );

    printf("y=%i\n", y);
}