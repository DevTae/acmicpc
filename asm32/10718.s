section .data
	msg : db "강한친구 대한육군", 0xA
	len : equ $ - msg ; length

section .text
	global main

main:
	push ebp
	mov ebp, esp

	sub esp, 8
	mov dword [esp+4], msg
	mov dword [esp], len
	call print
	call print

	add esp, 12
	xor eax, eax
	ret

print:
	mov eax, 4 ; sys_write
	mov ebx, 1 ; 출력 모드
	mov ecx, dword [esp+8] ; msg
	mov edx, dword [esp+4] ; len
	int 0x80
	ret
