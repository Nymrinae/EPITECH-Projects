; EPITECH PROJECT, 2019
; B4-x86-64_Assembly
; File description:
; memcpy.asm

[BITS 64]
	global memcpy:function

memcpy:
    ENTER 0,0
	mov rax, 0
	mov r13, rdi
	
loop:
	cmp rax, rdx
	jge end

	mov cl, byte [rsi]
	mov byte[rdi], cl

	inc rdi
	inc rax
	inc rsi
	jmp loop

end:
	mov rax, r13
    leave
    ret