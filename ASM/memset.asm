; EPITECH PROJECT, 2019
; B4-x86-64_Assembly
; File description:
; memset.asm

[BITS 64]
    global memset:function

memset:
    ENTER 0, 0
    mov r8, rdi
    jmp loop

loop:
    cmp byte[rdi], 0
    je end

    mov byte[rdi], sil
    inc rdi

    dec rdx
    je end

    jmp loop

end:
    mov rax, r8
    leave
    ret