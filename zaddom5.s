.intel_syntax noprefix
.global main
.text

main:
    mov ecx, [esp+8]
	mov ecx, [ecx+4]
	push ecx
	call atoi
	mov ecx, eax
	add esp, 4
	xor eax, eax
	jecxz fibonacci_end
	mov edx, eax
	dec ecx
	inc eax
	jecxz fibonacci_end
fibonacci_loop:
	xchg eax, edx
	add eax, edx
	loop fibonacci_loop
fibonacci_end:
    mov number, eax
    push number
    push offset result
    call printf
    add esp, 8
	ret

.data
number: .int 0
result: .asciz "%d\n"
