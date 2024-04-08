/*
17070버니 파이프 옮기기
https://www.acmicpc.net/problem/17070

문제
유현이가 새 집으로 이사했다. 새 집의 크기는 N×N의 격자판으로 나타낼 수 있고, 1×1크기의 정사각형 칸으로 나누어져 있다. 각각의 칸은 (r, c)로 나타낼 수 있다. 여기서 r은 행의 번호, c는 열의 번호이고, 행과 열의 번호는 1부터 시작한다. 각각의 칸은 빈 칸이거나 벽이다.

오늘은 집 수리를 위해서 파이프 하나를 옮기려고 한다. 파이프는 아래와 같은 형태이고, 2개의 연속된 칸을 차지하는 크기이다.

파이프는 회전시킬 수 있으며, 아래와 같이 3가지 방향이 가능하다.

파이프는 매우 무겁기 때문에, 유현이는 파이프를 밀어서 이동시키려고 한다. 벽에는 새로운 벽지를 발랐기 때문에, 파이프가 벽을 긁으면 안 된다. 즉, 파이프는 항상 빈 칸만 차지해야 한다.

파이프를 밀 수 있는 방향은 총 3가지가 있으며, →, ↘, ↓ 방향이다. 파이프는 밀면서 회전시킬 수 있다. 회전은 45도만 회전시킬 수 있으며, 미는 방향은 오른쪽, 아래, 또는 오른쪽 아래 대각선 방향이어야 한다.

파이프가 가로로 놓여진 경우에 가능한 이동 방법은 총 2가지, 세로로 놓여진 경우에는 2가지, 대각선 방향으로 놓여진 경우에는 3가지가 있다.

아래 그림은 파이프가 놓여진 방향에 따라서 이동할 수 있는 방법을 모두 나타낸 것이고, 꼭 빈 칸이어야 하는 곳은 색으로 표시되어져 있다.

가로

세로

대각선

가장 처음에 파이프는 (1, 1)와 (1, 2)를 차지하고 있고, 방향은 가로이다. 파이프의 한쪽 끝을 (N, N)로 이동시키는 방법의 개수를 구해보자.


입력
첫째 줄에 집의 크기 N(3 ≤ N ≤ 16)이 주어진다. 둘째 줄부터 N개의 줄에는 집의 상태가 주어진다. 빈 칸은 0, 벽은 1로 주어진다. (1, 1)과 (1, 2)는 항상 빈 칸이다.


출력
첫째 줄에 파이프의 한쪽 끝을 (N, N)으로 이동시키는 방법의 수를 출력한다. 이동시킬 수 없는 경우에는 0을 출력한다. 방법의 수는 항상 1,000,000보다 작거나 같다.


row 1, column 1 ~ 2 에 위치함

3^16 = 약 4300만 개의 연산이므로, 1초 내에 연산 가능.

*/

#include <iostream>

using namespace std;

enum class Shape {
	HORIZONTAL, 
	VERTICAL,
	DIAGONAL
};

struct INFO {
	int row;
	int column;
	Shape shape;
};

int N;
int room[17][17];
//bool visited[17][17] = { false, }; // false 로 초기화

// 그래프 움직임 모두 저장
int dc_horizontal[2] = { 1, 1 };
int dr_horizontal[2] = { 0, 1 };
int dc_vertical[2] = { 0, 1 };
int dr_vertical[2] = { 1, 1 };
int dc_diagonal[3] = { 1, 0, 1 };
int dr_diagonal[3] = { 0, 1, 1 };

// 움직인 각도에 대한 enum 반환
Shape getShapeOfMoving(int dr, int dc) {
	if (dc == 0 && dr == 1) {
		return Shape::VERTICAL;
	}
	else if (dc == 1 && dr == 0) {
		return Shape::HORIZONTAL;
	}
	else if (dc == 1 && dr == 1) {
		return Shape::DIAGONAL;
	}
}

int dfs(INFO start) {

	int sum = 0;
	
	if (start.row == N && start.column == N) {
		return 1;
	}
	
	switch (start.shape) {
	case Shape::HORIZONTAL:
		for (int i = 0; i < 2; i++) {
			int row = start.row + dr_horizontal[i];
			int column = start.column + dc_horizontal[i];
			if (row <= N && column <= N) {

				bool possible = true;
				for (int r = start.row; r <= row; r++) {
					for (int c = start.column; c <= column; c++) {
						if (r == start.row && c == start.column) continue;
						if (room[r][c] == 1) possible = false;
					}
				}
				if (!possible) continue;

				INFO next;
				next.row = row;
				next.column = column;
				next.shape = getShapeOfMoving(dr_horizontal[i], dc_horizontal[i]);
				sum += dfs(next);
			}
		}
		break;

	case Shape::VERTICAL:
		for (int i = 0; i < 2; i++) {
			int row = start.row + dr_vertical[i];
			int column = start.column + dc_vertical[i];
			if (row <= N && column <= N) {

				bool possible = true;
				for (int r = start.row; r <= row; r++) {
					for (int c = start.column; c <= column; c++) {
						if (r == start.row && c == start.column) continue;
						if (room[r][c] == 1) possible = false;
					}
				}
				if (!possible) continue;

				INFO next;
				next.row = row;
				next.column = column;
				next.shape = getShapeOfMoving(dr_vertical[i], dc_vertical[i]);
				sum += dfs(next);
			}
		}
		break;

	case Shape::DIAGONAL:
		for (int i = 0; i < 3; i++) {
			int row = start.row + dr_diagonal[i];
			int column = start.column + dc_diagonal[i];
			if (row <= N && column <= N) {

				bool possible = true;
				for (int r = start.row; r <= row; r++) {
					for (int c = start.column; c <= column; c++) {
						if (r == start.row && c == start.column) continue;
						if (room[r][c] == 1) possible = false;
					}
				}
				if (!possible) continue;

				INFO next;
				next.row = row;
				next.column = column;
				next.shape = getShapeOfMoving(dr_diagonal[i], dc_diagonal[i]);
				sum += dfs(next);
			}
		}
		break;
	}

	return sum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char ch = cin.get();
			if (ch == ' ' || ch == '\n') {
				ch = cin.get();
			}

			room[i+1][j+1] = ch - 48;
		}
	}

	/*
	* 출력 테스트
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << room[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	INFO start;
	start.row = 1;
	start.column = 2;
	start.shape = Shape::HORIZONTAL;

	int value = dfs(start);

	cout << value;

	return 0;
}