#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

	int* a = (int*)malloc(sizeof(int));
	int* b = (int*)malloc(sizeof(int));
	int* c = (int*)malloc(sizeof(int));

	scanf("%d %d", a, b);

	//printf("%d %d\n", *a, *b);

	*c = abs(*a - *b);

	printf("%d", *c);

	return 0;
}