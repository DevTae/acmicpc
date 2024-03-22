#include <stdio.h>

int main_wk2_3(void) {
	int a, b;

	scanf_s("%d %d", &a, &b);

	printf("%d > %d --- %d\n", a, b, a > b);
	printf("%d < %d --- %d\n", a, b, a < b);
	printf("%d >= %d --- %d\n", a, b, a >= b);
	printf("%d <= %d --- %d\n", a, b, a <= b);

	return 0;

}