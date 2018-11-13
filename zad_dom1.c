#include <stdio.h>

int main() {
// 	int x = 2018;
// 	int y;
// 	asm volatile(
// 	".intel_syntax noprefix;"
// 	"mov eax,%1;"
// 	"xor ecx,ecx;"
// 	"petla:"
// 	"add eax,eax;"
// 	"inc ecx;"
// 	"cmp ecx,10;"
// 	"jnz petla;"
// 	"mov %0, eax;"
// 	".att_syntax prefix;"
// 	:"=r"(y)
// 	:"r"(x)ecx
// 	:"eax","ecx"
// );
// 	printf("y=%i\n", y);
// 	return 0;
        int inputNumber = 0xAAAA;
        countPhraseOccurances(inputNumber);
}


int countPhraseOccurances(int inputNumber) {
    int occurances;
    asm volatile(
    ".intel_syntax noprefix;"
		"mov eax, %1;"
		"mov ecx, 33;"
		"xor edx, edx;"
		"xor ebx, ebx;"		
		"loopPoint:"
		"dec ecx;"
		"jz finish;"
		"mov ebx, eax;"
        "shl eax, 1;"
		"shr ebx, 29;"
		"cmp ebx, 5;"
		"je incrementCounter;"
		"jmp loopPoint;"	
		"incrementCounter:"
		"inc edx;"
		"jmp loopPoint;"	
		"finish:"
		"mov %0, edx;"
		".att_syntax prefix;"
		:"=r"(occurances)
		:"r"(inputNumber)
		:"eax", "ebx", "ecx", "edx"
    );

    printf("y=%i\n", occurances);
}

