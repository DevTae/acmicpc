/*
단지번호붙이기
https://www.acmicpc.net/problem/2667

1. 그래프 방식
  그래프 방식으로 추가하기
  (1, 2) -> (2, 2), (1, 3) 연결
  visited 체크(이후 (2,2), (1,3) 은 방문 완료)하면서 NxN 에 대한 반복문 돌림.

2. 배열 방식
  (1, 2) 에서부터 상하좌우 방향으로 DFS (재귀로 누적합 구하기) 진행.
  visited 추가하여 확인해주기
  
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> clusters;

int apart[25][25];
int visited[25][25] = { {0, } };

int dfs(int r, int c) {
	if (visited[r][c] == 0 && apart[r][c] == 1 && r >= 0 && r <= 24 && c >= 0 && c <= 24) {
		visited[r][c] = 1;

		return 1 + dfs(r + 1, c) + dfs(r - 1, c) + dfs(r, c + 1) + dfs(r, c - 1);
	}
	else {
		return 0;
	}
}

int main_2667(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num = cin.get();
			if (num == '\n') {
				num = cin.get();
			}
			apart[i][j] = num - 48; // 48 빼주는 거 중요! 아스키코드 활용
		}
	}

	// dfs 기반 단지 크기 구하기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && apart[i][j]) {
				int count = dfs(i, j);
				clusters.push_back(count);
			}
		}
	}

	// 정렬 진행
	sort(clusters.begin(), clusters.end());

	cout << clusters.size() << "\n";

	// 오름차순으로 단지 크기 출력
	for (auto iter = clusters.begin(); iter != clusters.end(); iter++) {
		cout << *iter << "\n";
	}

	return 0;

}