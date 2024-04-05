/*

���� Ż�� 2

��ŸƮ��ũ���� �Ǹ��ϴ� ��̿� �峭�� �߿��� ���� �αⰡ ���� ��ǰ�� ���� Ż���̴�. ���� Ż���� ���簢�� ���忡 ���� ������ �Ķ� ������ �ϳ��� ���� ����, "���� ����"�� ������ ���� ������ �����̴�.

������ ���� ũ��� N, ���� ũ��� M�̰�, ���ǻ� 1��1ũ���� ĭ���� �������� �ִ�. ���� �ٱ� ��� ���� ��� ������ �ְ�, ���忡�� ������ �ϳ� �ִ�. ���� ������ �Ķ� ������ ũ��� ���忡�� 1��1ũ���� ĭ�� ���� ä��� �������̰�, ���� �ϳ��� �� �ִ�. ������ ��ǥ�� ���� ������ ������ ���ؼ� ������ ���̴�. �̶�, �Ķ� ������ ���ۿ� ���� �� �ȴ�.

�̶�, ������ ������ �ǵ帱 ���� ����, �߷��� �̿��ؼ� �̸� ���� ������ �Ѵ�. �������� ����̱�, ���������� ����̱�, �������� ����̱�, �Ʒ������� ����̱�� ���� �� ���� ������ �����ϴ�.

������ ���ۿ��� ���� ���ÿ� �����δ�. ���� ������ ���ۿ� ������ ����������, �Ķ� ������ ���ۿ� ������ �����̴�. ���� ������ �Ķ� ������ ���ÿ� ���ۿ� ������ �����̴�. ���� ������ �Ķ� ������ ���ÿ� ���� ĭ�� ���� �� ����. ��, ���� ������ �Ķ� ������ ũ��� �� ĭ�� ��� �����Ѵ�. ����̴� ������ �׸��ϴ� ���� �� �̻� ������ �������� ���� �� �����̴�.

������ ���°� �־����� ��, �ּ� �� �� ���� ���� ������ ������ ���� ���� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�� ���� : NxM �� �迭���� ���� ������ ���� ���� ����, N,M �ִ�� 10�̰� Ƚ���� 10ȸ�����̱� ������, 10 * 4^10 = �� 1000�� ������, ����Ž���� �����ϱ� ��.
������, BFS �� Ǯ�� �� ����������. 10 * 4 * 2^9 (ù �� ���⿡ ���� ó�� ���Ŀ��� �ݴ� ���� X, ���� ���� X, �����ϰ� ���� ���������� 2���� �������� �� �� ����.


�Է�

ù ��° �ٿ��� ������ ����, ���� ũ�⸦ �ǹ��ϴ� �� ���� N, M (3 �� N, M �� 10)�� �־�����. ���� N���� �ٿ� ������ ����� ��Ÿ���� ���� M�� ���ڿ��� �־�����. �� ���ڿ��� '.', '#', 'O', 'R', 'B' �� �̷���� �ִ�. '.'�� �� ĭ�� �ǹ��ϰ�, '#'�� ���� �̵��� �� ���� ��ֹ� �Ǵ� ���� �ǹ��ϸ�, 'O'�� ������ ��ġ�� �ǹ��Ѵ�. 'R'�� ���� ������ ��ġ, 'B'�� �Ķ� ������ ��ġ�̴�.

�ԷµǴ� ��� ������ �����ڸ����� ��� '#'�� �ִ�. ������ ������ �� �� �̸�, ���� ������ �Ķ� ������ �׻� 1���� �־�����.


���

�ּ� �� �� ���� ���� ������ ������ ���� ���� �� �ִ��� ����Ѵ�. ����, 10�� ���Ϸ� �������� ���� ������ ������ ���� ���� �� ������ -1�� ����Ѵ�.

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

int N, M; // ���� ũ��
char board[10][10] = { 0, };

int bfs(INFO first) {

	// �����¿� ��ǥ�� ���� (������ ���̽��� �ش� �ڵ�� ���� �� ����)
	int dc[4] = { 0, 0, -1, 1 }; // column
	int dr[4] = { 1, -1, 0, 0 }; // row

	bool visited[10][10][10][10] = { false, };
	int answer = -1;

	queue<INFO> q;
	q.push(first);
	visited[first.r_r][first.r_c][first.b_r][first.b_c] = true; // ó�� ��ȯ�� ���� �湮 ó��
	
	while (!q.empty()) {
		INFO cur = q.front(); q.pop();

		// ���� ��ȯ
		if (cur.count > 10) break;

		// �ű� ���Ŀ�, ���� ��ȯ
		if (board[cur.r_r][cur.r_c] == 'O') {
			if (board[cur.b_r][cur.b_c] != 'O') {
				answer = cur.count;
				break;
			}
			else {
				continue;
			}
		}

		// �� ���� �� �۾� ����
		for (int dir = 0; dir < 4; dir++) {
			int r_r = cur.r_r;
			int r_c = cur.r_c;
			int b_r = cur.b_r;
			int b_c = cur.b_c;

			// ���� �� �ű��
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

			// �Ķ� �� �ű��
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

			// "������ �ƴ� ��쿡 ���Ͽ�" ���� �� Ȥ�� ���̾��� ��, (��ġ�� ���)
			if (b_r == r_r && b_c == r_c && board[b_r][b_c] != 'O') {
				int diff_r = abs(cur.r_r - r_r) + abs(cur.r_c - r_c);
				int diff_b = abs(cur.b_r - b_r) + abs(cur.b_c - b_c);

				// r �� �� ���ٸ�, r �ű��
				if (diff_r > diff_b) {
					r_r -= dr[dir];
					r_c -= dc[dir];
				}
				// �ƴ϶��, b �ű��
				else {
					b_r -= dr[dir];
					b_c -= dc[dir];
				}
			}
			
			// ������ �Ŀ�, �б������� �ľ� �� dfs ����
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

	// �� �о����
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