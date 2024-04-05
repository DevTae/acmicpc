/*

구슬 탈출 2

스타트링크에서 판매하는 어린이용 장난감 중에서 가장 인기가 많은 제품은 구슬 탈출이다. 구슬 탈출은 직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣은 다음, "빨간 구슬"을 구멍을 통해 빼내는 게임이다.

보드의 세로 크기는 N, 가로 크기는 M이고, 편의상 1×1크기의 칸으로 나누어져 있다. 가장 바깥 행과 열은 모두 막혀져 있고, 보드에는 구멍이 하나 있다. 빨간 구슬과 파란 구슬의 크기는 보드에서 1×1크기의 칸을 가득 채우는 사이즈이고, 각각 하나씩 들어가 있다. 게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것이다. 이때, 파란 구슬이 구멍에 들어가면 안 된다.

이때, 구슬을 손으로 건드릴 수는 없고, 중력을 이용해서 이리 저리 굴려야 한다. 왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기와 같은 네 가지 동작이 가능하다.

각각의 동작에서 공은 동시에 움직인다. 빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다. 빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다. 빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다. 또, 빨간 구슬과 파란 구슬의 크기는 한 칸을 모두 차지한다. 기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.

보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성하시오.

→ 정리 : NxM 의 배열에서 빨간 구슬을 빼는 것이 목적, N,M 최대는 10이고 횟수는 10회까지이기 때문에, 10 * 4^10 = 약 1000만 정도로, 완전탐색도 가능하긴 함.
하지만, BFS 로 풀면 더 간단해진다. 10 * 4 * 2^9 (첫 네 방향에 대한 처리 이후에는 반대 방향 X, 가던 방향 X, 제외하고 왼쪽 오른쪽으로 2가지 방향으로 갈 수 있음.


입력

첫 번째 줄에는 보드의 세로, 가로 크기를 의미하는 두 정수 N, M (3 ≤ N, M ≤ 10)이 주어진다. 다음 N개의 줄에 보드의 모양을 나타내는 길이 M의 문자열이 주어진다. 이 문자열은 '.', '#', 'O', 'R', 'B' 로 이루어져 있다. '.'은 빈 칸을 의미하고, '#'은 공이 이동할 수 없는 장애물 또는 벽을 의미하며, 'O'는 구멍의 위치를 의미한다. 'R'은 빨간 구슬의 위치, 'B'는 파란 구슬의 위치이다.

입력되는 모든 보드의 가장자리에는 모두 '#'이 있다. 구멍의 개수는 한 개 이며, 빨간 구슬과 파란 구슬은 항상 1개가 주어진다.


출력

최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 출력한다. 만약, 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다.

*/


#include <iostream>
#include <queue>

using namespace std;

struct INFO {
	int r_r;
	int r_c;
	int b_r;
	int b_c;
	int count;
};

int N, M; // 보드 크기
char board[10][10] = { 0, };

int bfs(INFO first) {

	// 상하좌우 좌표계 정리 (수많던 케이스를 해당 코드로 줄일 수 있음)
	int dc[4] = { 0, 0, -1, 1 }; // column
	int dr[4] = { 1, -1, 0, 0 }; // row

	bool visited[10][10][10][10] = { false, };
	int answer = -1;

	queue<INFO> q;
	q.push(first);
	visited[first.r_r][first.r_c][first.b_r][first.b_c] = true; // 처음 순환에 대한 방문 처리
	
	while (!q.empty()) {
		INFO cur = q.front(); q.pop();

		// 오답 반환
		if (cur.count > 10) break;

		// 옮긴 이후에, 정답 반환
		if (board[cur.r_r][cur.r_c] == 'O') {
			if (board[cur.b_r][cur.b_c] != 'O') {
				answer = cur.count;
				break;
			}
			else {
				continue;
			}
		}

		// 각 각도 별 작업 진행
		for (int dir = 0; dir < 4; dir++) {
			int r_r = cur.r_r;
			int r_c = cur.r_c;
			int b_r = cur.b_r;
			int b_c = cur.b_c;

			// 빨간 공 옮기기
			while (true) {
				/*
				if (board[r_r][r_c] != '#' && board[r_r][r_c] != 'O') {
					r_r += dr[dir];
					r_c += dc[dir];
				}
				else {
					if (board[r_r][r_c] == '#') {
						r_r -= dr[dir];
						r_c -= dc[dir];
					}
					break;
				}
				*/

				if (board[r_r][r_c] == '.') {
					r_r += dr[dir];
					r_c += dc[dir];
				}
				else if (board[r_r][r_c] == 'O') {
					break;
				}
				else if (board[r_r][r_c] == '#') {
					r_r -= dr[dir];
					r_c -= dc[dir];
					break;
				}
				
			}

			// 파란 공 옮기기
			while (true) {
				/*
				if (board[b_r][b_c] != '#' && board[b_r][b_c] != 'O') {
					b_r += dr[dir];
					b_c += dc[dir];
				}
				else {
					if (board[b_r][b_c] == '#') {
						b_r -= dr[dir];
						b_c -= dc[dir];
					}
					break;
				}
				*/

				if (board[b_r][b_c] == '.') {
					b_r += dr[dir];
					b_c += dc[dir];
				}
				else if (board[b_r][b_c] == 'O') {
					break;
				}
				else if (board[b_r][b_c] == '#') {
					b_r -= dr[dir];
					b_c -= dc[dir];
					break;
				}
				
			}

			// "구멍이 아닌 경우에 대하여" 같은 행 혹은 열이었을 때, (겹치는 경우)
			if (b_r == r_r && b_c == r_c && board[b_r][b_c] != 'O') {
				int diff_r = abs(cur.r_r - r_r) + abs(cur.r_c - r_c);
				int diff_b = abs(cur.b_r - b_r) + abs(cur.b_c - b_c);

				// r 이 더 갔다면, r 옮기기
				if (diff_r > diff_b) {
					r_r -= dr[dir];
					r_c -= dc[dir];
				}
				// 아니라면, b 옮기기
				else {
					b_r -= dr[dir];
					b_c -= dc[dir];
				}
			}
			
			// 움직인 후에, 분기점으로 파악 후 dfs 진행
			if (!visited[r_r][r_c][b_r][b_c]) {
				visited[r_r][r_c][b_r][b_c] = true;

				INFO next;
				next.r_r = r_r;
				next.r_c = r_c;
				next.b_r = b_r;
				next.b_c = b_c;
				next.count = cur.count + 1;

				q.push(next);
			}
		}
	}

	return answer;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	INFO start;

	// 판 읽어오기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char ch = cin.get();
			if (ch == '\n')
				ch = cin.get();

			if (ch == 'R') {
				board[i][j] = '.';
				start.r_r = i;
				start.r_c = j;
			}
			else if (ch == 'B') {
				board[i][j] = '.';
				start.b_r = i;
				start.b_c = j;
			}
			else {
				board[i][j] = ch;
			} 
		}
	}

	start.count = 0;

	int value = bfs(start);

	cout << value;

	return 0;

}