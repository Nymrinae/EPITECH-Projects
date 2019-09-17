; EPITECH PROJECT, 2019
; B4-x86-64_Assembly
; File description:
; rindex.asm

[BITS 64]
    global rindex:function

rindex:
    ENTER 0, 0
    mov r8, 0
    mov rax, rdi
    jmp loop

loop:
    cmp sil, 0                  ; imagine passing a '\0' in 2nd arg ...
    je end

    cmp BYTE[rax], sil
    je occ

    cmp BYTE[rax], 0
    je end

    inc rax
    jmp loop

occ:
    mov r8, rax
    inc rax
    jmp loop

end:
    mov rax, r8
    leave
    ret