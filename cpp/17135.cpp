/*
17135��: ĳ�� ���潺

����
ĳ�� ���潺�� ���� ���� �������� ���� ��� �� ����� �����̴�. ������ ����Ǵ� ���� ũ�Ⱑ N��M�� ���������� ��Ÿ�� �� �ִ�. �������� 1��1 ũ���� ĭ���� �������� �ְ�, �� ĭ�� ���Ե� ���� ���� �ִ� �ϳ��̴�. �������� N������ �ٷ� �Ʒ�(N+1�� ��)�� ��� ĭ���� ���� �ִ�.

���� �����Լ� ��Ű�� ���� �ü� 3���� ��ġ�Ϸ��� �Ѵ�. �ü��� ���� �ִ� ĭ�� ��ġ�� �� �ְ�, �ϳ��� ĭ���� �ִ� 1���� �ü��� ���� �� �ִ�. ������ �ϸ��� �ü��� �� �ϳ��� ������ �� �ְ�, ��� �ü��� ���ÿ� �����Ѵ�. �ü��� �����ϴ� ���� �Ÿ��� D������ �� �߿��� ���� ����� ���̰�, �׷��� ���� ������ ��쿡�� ���� ���ʿ� �ִ� ���� �����Ѵ�. ���� ���� ���� �ü����� ���ݴ��� �� �ִ�. ���ݹ��� ���� ���ӿ��� ���ܵȴ�. �ü��� ������ ������, ���� �̵��Ѵ�. ���� �Ʒ��� �� ĭ �̵��ϸ�, ���� �ִ� ĭ���� �̵��� ��쿡�� ���ӿ��� ���ܵȴ�. ��� ���� �����ǿ��� ���ܵǸ� ������ ������.
"D ������ ���� �� ���� ����� ���� ����"
"���� �ü����� ���� ���� �� �ִ�!!!!!"

���� ������ ���ٽ��� �ü��� ��ġ�� ������ ���� ������ �������ִ�. ����, �� ������ �ü��� ��ġ�� �߿��ϴ�. �������� ���°� �־����� ��, �ü��� �������� ������ �� �ִ� ���� �ִ� ���� ����غ���.

�������� �� ��ġ (r1, c1), (r2, c2)�� �Ÿ��� |r1-r2| + |c1-c2|�̴�.


�Է�
ù° �ٿ� ������ ���� �� N, ���� �� M, �ü��� ���� �Ÿ� ���� D�� �־�����. ��° �ٺ��� N���� �ٿ��� �������� ���°� �־�����. 0�� �� ĭ, 1�� ���� �ִ� ĭ�̴�.

���
ù° �ٿ� �ü��� �������� ������ �� �ִ� ���� �ִ� ���� ����Ѵ�.

����
3 �� N, M �� 15
1 �� D �� 10

N+1 �࿡ 3 ���� �ü��� ���� N * N^3 = N^4 -> 2^8 = 256... DFS ���
1. ����� �� ����
 1-1. ���� �˰��� logN
2. �� �Ʒ��� �ű�� (������� �͵� ����)

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
N : ��
M : ��
D : ���� �Ÿ� ����
*/
int N, M, D;

int ground[15][15];


// �ü��� ���� (���ʺ��� ���̴� ���ʺ��� ����) (--> bfs ����)
int kill(int ground_cp[15][15], int a[3]) {

	// ���� �� ������
	int killed = 0;

	// ��ǥ�� ����
	int dr[3] = { 0, -1, 0 };
	int dc[3] = { -1, 0, 1 };
	
	// ���� ���Ͽ� ������ ���� �־�α�
	set<pair<int, int>> s;

	// archor ���� �ϳ��� �� ���
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

	// �����ص� ������ ���� ����
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		pair<int, int> t = *iter;
		ground_cp[t.first][t.second] = 0;
		killed++;
	}

	return killed;
}

// ���� ���� �̵�
void next(int ground_cp[15][15]) {
	// �� �پ� �̵�
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < M; j++) {
			ground_cp[i][j] = ground_cp[i - 1][j];
		}
	}

	// �� �� �� 0���� �ʱ�ȭ
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

	// ground(����) ���纻 �����
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

	// ��� �ü� ��ġ �ľǿ� ���� �ó����� ���� (column �� ����)
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

	// �Է¹ޱ�
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char ch = cin.get();
			if (ch == '\n' || ch == ' ')
				ch = cin.get();

			ground[i][j] = ch - 48;
		}
	}

	// ���Ʈ���� �˰��� ����
	int result = bf();

	cout << result;
	
	return 0;
}