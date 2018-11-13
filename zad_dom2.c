#include <stdio.h>
    
int main() {
    int x = 0x0FF0F;
    int y;

    asm volatile(
        ".intel_syntax noprefix;"
        "mov eax, %1;"
        "mov ebx, 33;"
        "xor edx, edx;"
		"xor ecx, ecx;"
        "loopstart:"
        "xor edx, edx;"
        "dec ebx;"
        "jz finish;"
        "innerloop:"
        "shl eax, 1;"
        "jnc loopstart;"
        "inc edx;"
        "cmp edx, ecx;"
        "jl innerloop;"
        "mov ecx, edx;" 
        "jmp innerloop;"
        "finish:"
        "mov %0, ecx;"
        ".att_syntax prefix;"
        :"=r"(y)
		:"r"(x)
        :"eax", "ebx", "ecx", "edx"
        );

        printf("y=%i\n", y);
}