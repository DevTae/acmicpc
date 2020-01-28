; 1번째 방법 : printf 이용
section .data
	data : db "Hello World!", 0xA, 0
	extern printf

section .text
	global main

main:
	push ebp
	mov ebp, esp
	push data
	call printf
	add esp, 4
	mov eax, 0 ; 레지스터 eax에 리턴 값 0을 집어 넣어줌.
	leave
	ret

; 2번째 방법 : 시스템콜 이용
;section .data
;	msg : db "Hello World!"
;
;section .text
;	global main
;
;main:
;	push ebp
;	mov ebp, esp
;	mov eax, 4 ; sys_write
;	mov ebx, 1 ; 출력 모드
;	mov ecx, msg
;	mov edx, 12
;	int 0x80 ; syscall 와 같음 32비트 컴파일 시에는 int 0x80 사용해야 함.
;	leave
;	ret
