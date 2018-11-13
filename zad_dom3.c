#include <stdio.h>
int main(){
  char *s="Abc";
  int y;

  asm volatile (
	".intel_syntax noprefix;"
	"mov ebx, %1;"
	"xor ecx, ecx;"

	"petla:"
	"mov al, [ebx];"
	"cmp al,0;"
	"je zeruj;"
	"push al;"
	"inc ecx;"
	"inc ebx;"
	"jmp petla;"
	
	"zeruj:"
	"xor ebx, ebx;"
	"jmp koniec;"

	"koniec:"
	"pop al;"
	"mov [ebx], al;"
	"dec ecx;"
	"inc ebx;"
	"cmp ecx, 0;"
	"je ultimate_koniec;"

	"ultimate_koniec:"
	"mov %1, ebx;"
	
	".att_syntax prefix;"
	:"=r"(y)
	:"r"(*s)
	:"eax","ebx", "ecx"
	);
  //printf("y=%i\n", y);
  return 0;
  
}