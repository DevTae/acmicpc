#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int N; 

	int* arr;

	// 1. N ��, �迭�� ũ�⿡ ���� ������ ����.
	scanf("%d", &N);

	// �迭�� ũ�⸸ŭ arr �ʱ�ȭ ����
	arr = (int*)malloc(sizeof(int) * N);

	// N ����ŭ�� ���ڸ� �޾Ƽ� arr �� �����ϱ�
	for (int i = 0; i < N; i++) {
		scanf("%d", arr + i);
	}

	// 2. ���� ���� ����.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) { // N - i - 1 �߿�!
			if (*(arr + j) < *(arr + j + 1)) { // j �� �������� j + 1��°�� �����۰� ���ϱ�
				int temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}

	// 3. ������������ ���ĵ� ���ڵ� ����ϱ�
	for (int i = 0; i < N; i++) {
		printf("%d ", *(arr + i));
	}

	return 0;
}