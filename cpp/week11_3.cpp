#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	// �޸� �Ҵ��ϱ� 
	// 
	// float �� ���.
	printf("ù ��° �Է��ϱ�");
	float* arr = (float*)malloc(sizeof(float) * 5);

	for (int i = 0; i < 5; i++) {
		scanf("%f", arr + i);
	}

	for (int i = 0; i < 5; i++) {
		printf("%.1f ", *(arr + i));
	}
	printf("\n");

	printf("�� ��° �Է��ϱ�");
	// double �� ���.
	double* arr_d = (double*)malloc(sizeof(double) * 5);

	for (int i = 0; i < 5; i++) {
		scanf("%lf", arr_d + i);
	}

	for (int i = 0; i < 5; i++) {
		printf("%.1lf ", *(arr_d + i));
	}

	return 0;
}