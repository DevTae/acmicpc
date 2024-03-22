#include <stdio.h>

int main_wk2_1(void) {
	int a, b;

	scanf_s("%d %d", &a, &b);
	
	a += 100;

	b %= 10;

	printf("%d %d", a, b);

	return 0;
}