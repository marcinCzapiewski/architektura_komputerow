.intel_syntax noprefix
.global main
.text
main:
	mov eax, [esp+8]
	mov eax, [eax+4]
	push eax
	call atoi
	add esp, 4

	push eax
	call check
	add esp, 4

	jmp end

check:
	mov eax, [esp+4]
	cmp eax, 2
	jg fib
	mov eax, 1
	ret

fib:
	dec eax
	push eax
	push eax
	call check
	add esp, 4
	pop ebx
	push eax
	dec ebx
	push ebx
	call check
	add esp, 4
	pop ebx
	add eax, ebx
	ret

end:
    push eax
    push offset result
    call printf
    add esp, 8
	ret

.data
result: .asciz "%d\n"
