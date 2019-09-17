; EPITECH PROJECT, 2019
; B4-x86-64_Assembly
; File description:
; strchr.asm

[BITS 64]
    global strchr:function

strchr:
    ENTER 0, 0
    mov rax, rdi            ; put str in rax
    jmp loop                ; jump to loop

loop:
    cmp BYTE[rax], sil      ; compare rax and char passed as parameter
    je end                  ; if true jump to end

    cmp BYTE[rax], 0        ; compare rax and '\0'
    je nf                   ; jump to notfound

    inc rax                 ; increment rax

    jmp loop                ; do loop

nf:
    mov rax, 0
    leave
    ret                     ; return null

end:
    leave
    ret                     ; return the string