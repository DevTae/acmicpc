/*
14500: 테트로미노

문제
폴리오미노란 크기가 1×1인 정사각형을 여러 개 이어서 붙인 도형이며, 다음과 같은 조건을 만족해야 한다.

정사각형은 서로 겹치면 안 된다.
도형은 모두 연결되어 있어야 한다.
정사각형의 변끼리 연결되어 있어야 한다. 즉, 꼭짓점과 꼭짓점만 맞닿아 있으면 안 된다.
정사각형 4개를 이어 붙인 폴리오미노는 테트로미노라고 하며, 다음과 같은 5가지가 있다.



아름이는 크기가 N×M인 종이 위에 테트로미노 하나를 놓으려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 정수가 하나 쓰여 있다.

테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.

테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며, 회전이나 대칭을 시켜도 된다.

입력
첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)

둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다. i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 쓰여 있는 수이다. 입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.

출력
첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.

2^2 * 5 * N * M = 2^2 * 5 * 2^18 = 2^24 = 약 1600만 --> 0.16초 --> BruteForce 적용 가능

*/

#include <iostream>
#include <queue>
#include <set>
#define MAX(a,b) ((a > b) ? a : b)

using namespace std;

int N, M;
int board[500][500];

// 90, 180, 270 회전
int mult[2] = { 1, -1 };

int dr[5][3] = { {0, 0, 0}, {0, 1, 0}, {1, 1, 0}, {1, 0, 1}, {0, 1, -1} };
int dc[5][3] = { {1, 1, 1}, {1, 0, -1}, {0, 0, 1}, {0, 1, 0}, {1, 0, 1} };

// brute-force
int bf() {
	int max = 0;

	for (int i = 0; i < N; i++) { // start row
		for (int j = 0; j < M; j++) { // start column
			for (int p = 0; p < 5; p++) { // 도형 모양
				for (int k = 0; k < 2; k++) { // 대칭 - 1
					for (int w = 0; w < 2; w++) { // 대칭 - 2
						int r, c, sum;
							
						// 기본
						r = i, c = j, sum = board[r][c];
						for (int q = 0; q < 3; q++) { // 도형 모양에 따른 순차 좌표 데이터
							r += mult[k] * dr[p][q];
							c += mult[w] * dc[p][q];
							if (r >= 0 && r < N && c >= 0 && c < M) {
								sum += board[r][c];
							}
							else {
								sum = 0;
								break;
							}
						}
						max = MAX(max, sum);

						// y=x 대칭
						r = i, c = j, sum = board[r][c];
						for (int q = 0; q < 3; q++) {
							r += mult[k] * dc[p][q];
							c += mult[w] * dr[p][q];
							if (r >= 0 && r < N && c >= 0 && c < M) {
								sum += board[r][c];
							}
							else {
								sum = 0;
								break;
							}
						}
						max = MAX(max, sum);
					}
				}
			}
		}
	}

	return max;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 입력 받기
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	
	int value = bf();
	
	cout << value;

	return 0;
}