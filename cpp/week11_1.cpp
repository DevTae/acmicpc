#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int a;
	int* b = &a;
	
	scanf("%d", &a);

	printf("%p %d", b, a);

	// 16���� 16�ڸ��� ����. 16������ 2^4 --> 4��Ʈ�� ����. 4bit * 16 = 64bit �� ��.

	return 0;
}