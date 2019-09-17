; EPITECH PROJECT, 2019
; B4-x86-64_Assembly
; File description:
; strlen.asm

[BITS 64]
    global strlen:function

strlen:
    ENTER 0, 0
    mov rax, 0                  ; init rax to 0
    jmp loop                    ; jump to comp rule

loop:
    cmp BYTE[rdi], 0            ; compare char of 1st arg to "\0"
    je end                      ; if true jump to end
    inc rax                     ; rax++
    inc rdi                     ; rdi++
    jmp loop                    ; jump to the start of the loop

end:
    leave
    ret                         ; return rdi