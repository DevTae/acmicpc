#include <stdio.h>

int main_wk2_4(void) {
	int a, b, c;

	scanf_s("%d %d %d", &a, &b, &c);

	if (a > b && a > c) {
		printf("1 ");
	}
	else {
		printf("0 ");
	}

	if (a == b && b == c) {
		printf("1");
	}
	else {
		printf("0");
	}

	return 0;
}