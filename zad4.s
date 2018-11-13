.intel_syntax noprefix
.global main
.text

main:
    mov eax, offset s
    push eax
    call printf
    add esp, 4
    ret
.data
s:.asciz "Hello, world\n"
