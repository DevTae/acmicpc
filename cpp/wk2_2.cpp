#include <stdio.h>

int main_wk2_2(void) {
	int a, b;

	scanf_s("%d %d", &a, &b);

	int c = a++ * --b;

	printf("%d %d %d", a, b, c);

	return 0;
}