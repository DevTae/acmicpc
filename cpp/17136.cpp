/*
17136번: 색종이 붙이기

문제
<그림 1>과 같이 정사각형 모양을 한 다섯 종류의 색종이가 있다. 색종이의 크기는 1×1, 2×2, 3×3, 4×4, 5×5로 총 다섯 종류가 있으며, 각 종류의 색종이는 5개씩 가지고 있다.



<그림 1>

색종이를 크기가 10×10인 종이 위에 붙이려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 0 또는 1이 적혀 있다. 1이 적힌 칸은 모두 색종이로 덮여져야 한다. 색종이를 붙일 때는 종이의 경계 밖으로 나가서는 안되고, 겹쳐도 안 된다. 또, 칸의 경계와 일치하게 붙여야 한다. 0이 적힌 칸에는 색종이가 있으면 안 된다.

종이가 주어졌을 때, 1이 적힌 모든 칸을 붙이는데 필요한 색종이의 최소 개수를 구해보자.

입력
총 10개의 줄에 종이의 각 칸에 적힌 수가 주어진다.

출력
모든 1을 덮는데 필요한 색종이의 최소 개수를 출력한다. 1을 모두 덮는 것이 불가능한 경우에는 -1을 출력한다.


그리디로 풀 수 없음. (배수x)
5^(10*10)..
dfs 및 백트래킹으로 진행

*/

#include <iostream>
#define MIN(a,b) ((a > b) ? b : a)
#define GAME_OVER 100

using namespace std;

struct INFO {
	int num;
	int *p;
};

const int SIZE = 10;
const int COLOR_SIZE = 5;
const int COLOR_ARRAY[COLOR_SIZE] = { 1,2,3,4,5 }; // 추후 이렇게 사용
// board = visited 가 되어야 함.
int board[SIZE][SIZE] = { 0, }; // 1 이면 채워야 함
int visited[SIZE][SIZE] = { 0, }; // 1 이면 채워진 것 (visited 역할)

// 하나씩 확인할 거면 이중 포문일 때 그냥 함수화 시켜서 내보낸다.
bool possibleToPlot(INFO info, int i) {
	if (info.p[i - 1] <= 0) return false;  // 블럭이 부족하다면

	// 좌표 나갔을 때 제외 (critical!!! / 이 부분 때문에 연산이 오래 걸림. 애초에 바깥에 나갈 놈이면 연산할 필요 없음.)
	if (info.num / SIZE + i - 1 >= SIZE || info.num % SIZE + i - 1 >= SIZE) return false;

	// 가능한지 확인
	for (int j = 0; j < i; j++) { // row
		for (int k = 0; k < i; k++) { // column
			int r = info.num / SIZE + j;
			int c = info.num % SIZE + k;
			if (board[r][c] == 0 // 색종이를 놓을 수 없거나
			 || visited[r][c] == 1) { // 이미 방문했거나 
				return false;
			}
		}
	}

	return true;
}

int dfs(INFO info) {
	int result = GAME_OVER; // 기본값

	// 블럭 모두 다 사용했다면 굳이 더 확인할 필요 없음
	bool pass = false;
	for (int i = 0; i < COLOR_SIZE; i++) {
		if (info.p[i] > 0) {
			pass = true;
		}
	}
	if (!pass) return result;

	// 색종이 놓지 않아도 된다면, 이동함
	while (info.num < SIZE * SIZE && board[info.num / SIZE][info.num % SIZE] == visited[info.num / SIZE][info.num % SIZE]) {
		info.num++;
	}

	// num 이 요구조건을 넘긴 경우 성공
	if (info.num >= SIZE * SIZE) {

		// 남은 블럭 제외
		int count = COLOR_SIZE * 5; // 각각 5개씩 있음
		for (int i = 0; i < COLOR_SIZE; i++) {
			count -= info.p[i];
		}

		if (count < 0) {
			return GAME_OVER;
		}
		else {
			return count;
		}
	}

	// DFS - 놓아야 할 때가 온다면,
	for (int i = 1; i <= COLOR_SIZE; i++) { // p1 ~ p5

		bool possible = possibleToPlot(info, i);

		if (possible) {
			// 방문 처리
			for (int j = 0; j <= i - 1; j++) { // row
				for (int k = 0; k <= i - 1; k++) { // column
					int r = info.num / SIZE + j;
					int c = info.num % SIZE + k;
					visited[r][c] = 1;
				}
			}
			
			INFO next;
			next.num = info.num + 1;
			next.p = new int[COLOR_SIZE];
			for (int j = 1; j <= COLOR_SIZE; j++) {
				int count = info.p[j - 1];
				if (i == j)
					count--;
				next.p[j - 1] = count;
			}

			// next 할당 및 dfs 진행
			result = MIN(result, dfs(next));

			// 방문처리 취소
			for (int j = 0; j < i; j++) { // row
				for (int k = 0; k < i; k++) { // column
					int r = info.num / SIZE + j;
					int c = info.num % SIZE + k;
					visited[r][c] = 0;
				}
			}

		}
		else {
			// 더 작은 것도 안되면 큰 것도 안 될 것.
			return result;
		}
	}

	return result;

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			char ch = cin.get();
			if (ch == ' ' || ch == '\n') {
				ch = cin.get();
			}

			board[i][j] = ch - 48;
		}
	}

	INFO info;
	info.num = 0;
	info.p = new int[COLOR_SIZE] { 5,5,5,5,5 };

	int value = dfs(info);

	if (value == GAME_OVER) {
		value = -1;
	}

	cout << value;

	return 0;
}