; EPITECH PROJECT, 2019
; B4-x86-64_Assembly
; File description:
; strstr.asm

[BITS 64]
    global strstr:function

strstr:
    ENTER 0,0

init:
    mov r8, rdi
    mov r9, rsi
    jmp nullstr

loop:
    mov dl, byte[r8]
    mov cl, byte[r9]

    cmp cl, 0
    je end

    inc r8
    inc r9

    cmp dl, cl
    je loop

    inc rdi
    jmp init

null:
    mov rax, 0
    leave
    ret

nullstr:
    cmp byte[rdi], 0
    je null

    jmp loop

end:
    mov rax, rdi
    leave
    ret