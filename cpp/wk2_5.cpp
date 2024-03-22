#include <stdio.h>

int main_wk2_5(void) {
	int a, b;

	scanf_s("%d %d", &a, &b);

	printf("%d / %d = %d...%d", a, b, a / b, a % b);

	return 0;
}