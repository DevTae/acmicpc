/*
2178. 미로 탐색
https://www.acmicpc.net/problem/2178
*/

#include <iostream>
#include <queue>

using namespace std;


queue<pair<int, pair<int, int>>> path;

int N, M;
int miro[101][101];
int visited[101][101] = { {0, } };

int bfs() {
	// (1,1) 에서 시작
	pair<int, pair<int, int>> start;
	start = make_pair(1, make_pair(1, 1));
	visited[1][1] = 1;
	path.push(start);

	while (!path.empty()) {
		pair<int, pair<int, int>> front = path.front();

		int count = front.first;
		int r = front.second.first;
		int c = front.second.second;

		path.pop();

		if (r == N && c == M) {
			return count;
		}	
		else {
			int p_r, p_c;

			p_r = r - 1;
			p_c = c;
			if (p_r >= 1 && p_r <= N && p_c >= 1 && p_c <= M && miro[p_r][p_c] && !visited[p_r][p_c]) {
				visited[p_r][p_c] = 1;
				path.push(make_pair(count + 1, make_pair(p_r, p_c)));
			}
			p_r = r + 1;
			p_c = c;
			if (p_r >= 1 && p_r <= N && p_c >= 1 && p_c <= M && miro[p_r][p_c] && !visited[p_r][p_c]) {
				visited[p_r][p_c] = 1;
				path.push(make_pair(count + 1, make_pair(p_r, p_c)));
			}
			p_r = r;
			p_c = c + 1;
			if (p_r >= 1 && p_r <= N && p_c >= 1 && p_c <= M && miro[p_r][p_c] && !visited[p_r][p_c]) {
				visited[p_r][p_c] = 1;
				path.push(make_pair(count + 1, make_pair(p_r, p_c)));
			}
			p_r = r;
			p_c = c - 1;
			if (p_r >= 1 && p_r <= N && p_c >= 1 && p_c <= M && miro[p_r][p_c] && !visited[p_r][p_c]) {
				visited[p_r][p_c] = 1;
				path.push(make_pair(count + 1, make_pair(p_r, p_c)));
			}
		}
	}
}

int main_2178(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int num = cin.get();
			if (num == '\n')
				num = cin.get();
			miro[i][j] = num - 48;
		}
	}

	int num = bfs();
	
	cout << num;

	return 0;
}