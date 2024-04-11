/*
17135번: 캐슬 디펜스

문제
캐슬 디펜스는 성을 향해 몰려오는 적을 잡는 턴 방식의 게임이다. 게임이 진행되는 곳은 크기가 N×M인 격자판으로 나타낼 수 있다. 격자판은 1×1 크기의 칸으로 나누어져 있고, 각 칸에 포함된 적의 수는 최대 하나이다. 격자판의 N번행의 바로 아래(N+1번 행)의 모든 칸에는 성이 있다.

성을 적에게서 지키기 위해 궁수 3명을 배치하려고 한다. 궁수는 성이 있는 칸에 배치할 수 있고, 하나의 칸에는 최대 1명의 궁수만 있을 수 있다. 각각의 턴마다 궁수는 적 하나를 공격할 수 있고, 모든 궁수는 동시에 공격한다. 궁수가 공격하는 적은 거리가 D이하인 적 중에서 가장 가까운 적이고, 그러한 적이 여럿일 경우에는 가장 왼쪽에 있는 적을 공격한다. 같은 적이 여러 궁수에게 공격당할 수 있다. 공격받은 적은 게임에서 제외된다. 궁수의 공격이 끝나면, 적이 이동한다. 적은 아래로 한 칸 이동하며, 성이 있는 칸으로 이동한 경우에는 게임에서 제외된다. 모든 적이 격자판에서 제외되면 게임이 끝난다.
"D 이하의 적들 중 가장 가까운 적을 제거"
"여러 궁수에게 공격 당할 수 있다!!!!!"

게임 설명에서 보다시피 궁수를 배치한 이후의 게임 진행은 정해져있다. 따라서, 이 게임은 궁수의 위치가 중요하다. 격자판의 상태가 주어졌을 때, 궁수의 공격으로 제거할 수 있는 적의 최대 수를 계산해보자.

격자판의 두 위치 (r1, c1), (r2, c2)의 거리는 |r1-r2| + |c1-c2|이다.


입력
첫째 줄에 격자판 행의 수 N, 열의 수 M, 궁수의 공격 거리 제한 D가 주어진다. 둘째 줄부터 N개의 줄에는 격자판의 상태가 주어진다. 0은 빈 칸, 1은 적이 있는 칸이다.

출력
첫째 줄에 궁수의 공격으로 제거할 수 있는 적의 최대 수를 출력한다.

제한
3 ≤ N, M ≤ 15
1 ≤ D ≤ 10

N+1 행에 3 명의 궁수가 존재 N * N^3 = N^4 -> 2^8 = 256... DFS 충분
1. 가까운 적 공격
 1-1. 정렬 알고리즘 logN
2. 적 아래로 옮기기 (사라지는 것들 포함)

*/

#include <iostream>
#include <queue>
#include <set>
#define MAX(a, b) ((a > b) ? a : b) 

using namespace std;

struct pos {
	int row;
	int col;
	int count;
};

/*
N : 행
M : 열
D : 공격 거리 제한
*/
int N, M, D;

int ground[15][15];


// 궁수가 죽임 (왼쪽부터 죽이니 왼쪽부터 진행) (--> bfs 적용)
int kill(int ground_cp[15][15], int a[3]) {

	// 죽인 적 누적합
	int killed = 0;

	// 좌표계 정보
	int dr[3] = { 0, -1, 0 };
	int dc[3] = { -1, 0, 1 };
	
	// 공격 당하여 삭제될 적들 넣어두기
	set<pair<int, int>> s;

	// archor 마다 하나씩 몹 잡기
	for (int i = 0; i < 3; i++) {
		bool visited[15][15] = { false, };
		queue<pos> q;
		pos p;
		p.row = N - 1;
		p.col = a[i];
		p.count = 1;
		q.push(p);
		visited[N - 1][a[i]] = true;

		while (!q.empty()) {

			pos now = q.front(); q.pop();

			if (now.count > D) continue;

			if (ground_cp[now.row][now.col] == 1) {
				s.insert(make_pair(now.row, now.col));
				break;
			}
			else {
				for (int dir = 0; dir < 3; dir++) {
					int r = now.row + dr[dir];
					int c = now.col + dc[dir];
					if (!visited[r][c] && r >= 0 && r < N && c >= 0 && c < M) {
						visited[r][c] = true;
						pos next;
						next.row = r;
						next.col = c;
						next.count = now.count + 1;
						q.push(next);
					}
				}
			}
		}
	}

	// 저장해둔 삭제할 적들 제거
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		pair<int, int> t = *iter;
		ground_cp[t.first][t.second] = 0;
		killed++;
	}

	return killed;
}

// 다음 라운드 이동
void next(int ground_cp[15][15]) {
	// 한 줄씩 이동
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < M; j++) {
			ground_cp[i][j] = ground_cp[i - 1][j];
		}
	}

	// 맨 윗 줄 0으로 초기화
	for (int j = 0; j < M; j++) {
		ground_cp[0][j] = 0;
	}

	// debug
	if (false) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << ground_cp[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n\n";
	}
	
}

// simulation of archors
int sm(int a[3]) {

	int killed = 0;

	// ground(전장) 복사본 만들기
	int ground_cp[15][15] = { 0, };
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			ground_cp[i][j] = ground[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		killed += kill(ground_cp, a);
		next(ground_cp);
	}

	return killed;
}

// brute-force
int bf() {
	int max = 0;

	// 모든 궁수 위치 파악에 대한 시나리오 적용 (column 에 대한)
	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			for (int k = j + 1; k < M; k++) {
				// debug
				if (false) {
					if (i == 0 && j == 2 && k == 4) {
						cout << "test";
					}
				}
				int a[3] = { i, j, k };
				max = MAX(max, sm(a));
			}
		}
	}

	return max;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력받기
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char ch = cin.get();
			if (ch == '\n' || ch == ' ')
				ch = cin.get();

			ground[i][j] = ch - 48;
		}
	}

	// 브루트포스 알고리즘 적용
	int result = bf();

	cout << result;
	
	return 0;
}