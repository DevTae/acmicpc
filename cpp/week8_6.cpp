#include <stdio.h>

int num[10] = { 0, };

void print(int from, int to) {

	if (from >= to) {

		for (int i = 0; i < to; i++) {
			printf("%d ", num[i]);
		}
		printf("\n");

		return;
	}

	
	for (int i = 0; i <= 5; i++) {
		if (from == 0) {
			num[from] = 1 + i;
		}
		else {
			if (num[from - 1] + i > 6) break;

			num[from] = num[from - 1] + i;
		}
		
		print(from + 1, to);
	}
	
}

int main(void) {

	int to;

	scanf_s("%d", &to);

	print(0, to);

	return 0;
}