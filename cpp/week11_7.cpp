#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int N; 

	int* arr;

	// 1. N 즉, 배열의 크기에 대한 정보를 받음.
	scanf("%d", &N);

	// 배열의 크기만큼 arr 초기화 진행
	arr = (int*)malloc(sizeof(int) * N);

	// N 번만큼의 숫자를 받아서 arr 에 저장하기
	for (int i = 0; i < N; i++) {
		scanf("%d", arr + i);
	}

	// 2. 버블 정렬 진행.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) { // N - i - 1 중요!
			if (*(arr + j) < *(arr + j + 1)) { // j 를 기준으로 j + 1번째의 아이템과 비교하기
				int temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}

	// 3. 내림차순으로 정렬된 숫자들 출력하기
	for (int i = 0; i < N; i++) {
		printf("%d ", *(arr + i));
	}

	return 0;
}