.intel_syntax noprefix
.global main
.text

main:
    push offset number
    push offset format
    call scanf
    add ESP, 8

    mov eax, number
    shl eax
    mov number, eax

    push number
    push offset result
    call printf
    add ESP, 8

    push 0
    call exit
.data
number: .long 0
format: .asciz "%d"
result: .asciz "%d\n"
