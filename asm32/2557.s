section .data
	msg db "Hello World!"

section .text
	global _start

_start:
	mov eax, 4 ; sys_write
	mov ebx, 1 ; 출력 모드
	mov ecx, msg
	mov edx, 12
	int 0x80 ; syscall 와 같음 32비트 컴파일 시에는 int 0x80 사용해야 함.

end:
	mov eax, 1 ; sys_exit
	mov ebx, 0
	int 0x80 ; 위와 마찬가지
