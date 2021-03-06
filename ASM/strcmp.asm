; EPITECH PROJECT, 2019
; B4-x86-64_Assembly
; File description:
; strcmp.asm

[BITS 64]
    global strcmp:function

strcmp:
    ENTER 0, 0
    jmp loop                    ; jump to loop

loop:
    cmp BYTE[rdi], 0            ; compare char of first arg to '\0'
    je end                      ; if true jump to end

    cmp BYTE[rsi], 0            ; compare char of second arg to '\0'
    je end                      ; if true jump to end

    mov cl, BYTE[rdi]           ; move rdi in cl to compare them
    cmp cl, BYTE[rsi]           ; compare them
    jne end                     ; if false jump to end
        
    inc rdi                     ; rdi++
    inc rsi                     ; rsi++
    jmp loop                    ; jump to the start of the loop

end:
    mov al, BYTE[rdi]           ; move byte[rsi]
    sub al, BYTE[rsi]           ; sub al and rsi
    movsx rax, al               ; mov from 8bit register to 64bit
    leave
    ret                         ; return rax