#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int a;
	int* b = &a;
	
	scanf("%d", &a);

	printf("%p %d", b, a);

	// 16진수 16자리가 나옴. 16진수는 2^4 --> 4비트가 나옴. 4bit * 16 = 64bit 가 됨.

	return 0;
}