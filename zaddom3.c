#include <stdio.h>
int main() {
    char string[] = "marcin";
    int y;
    asm volatile(
    ".intel_syntax noprefix;"
    "mov ebx, %1;"
    "xor ecx, ecx;" 

    "setInputLength:"
        "mov al, [ebx];"
        "cmp al, 0;"
        "je getFirstAndLast;"
        "inc ecx;" 
        "inc ebx;"
        "jmp setInputLength;"       
    "getFirstAndLast:"
        "mov ebx, %1;"
        "mov esi, ebx;"
        "add ebx, ecx;"  
        "mov edi, ebx;"
        "dec edi;"     
    "reverse:"
        "mov al, [esi];"
        "mov bl, [edi];"
        "mov [esi], bl;"
        "mov [edi], al;"
        "inc esi;"
        "dec edi;"
        "dec ecx;"
        "dec ecx;"
        "cmp ecx,0;"
        "jg reverse;"

    ".att_syntax prefix;"
    : "=r"(y)
    : "r" (string)
    : "eax", "ebx", "ecx"
    );
    printf("s = %s\n", string);
    return 0;
}