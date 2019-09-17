; EPITECH PROJECT, 2019
; B4-x86-64_Assembly
; File description:
; strcspn.asm

[BITS 64]
	global strcspn:function

strcspn:
    ENTER 0, 0
	mov rax, 0
	dec rdi
	dec rax

loop:
	inc rdi
	inc rax

	cmp byte[rdi], 0
	je end

	mov r9, rsi
	dec r9

comp:
	inc r9
	mov dl, byte [rdi]
	mov cl, byte [r9]

	cmp cl, 0
	jz loop

	cmp dl, cl
	je end

	jmp comp

end:
    leave
    ret