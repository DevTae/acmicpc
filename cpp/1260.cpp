/*
DFS �� BFS
https://www.acmicpc.net/problem/1260
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
int arr[n + 1][n + 1];  (���� ��� ���)
vector<int> graph[n+1]; (��ũ�帮��Ʈ ���)

@@@ ��°� visited üũ�� ���ÿ� ����. @@@
*/

vector<int> graph[1001];

queue<int> q; // bfs ������ ���� ť

bool visited_dfs[1001] = { false, };
bool visited_bfs[1001] = { false, };



void dfs(int i) {

	cout << i << " ";
	visited_dfs[i] = true;

	for (auto iter = graph[i].begin(); iter != graph[i].end(); iter++) {
		if (visited_dfs[*iter] == false) {
			dfs(*iter);
		}
	}
}

void bfs(int start) {

	q.push(start); // ����

	while (!q.empty()) {
		int num = q.front();
		q.pop();

		cout << num << " ";
		visited_bfs[num] = true;

		for (auto iter = graph[num].begin(); iter != graph[num].end(); iter++) {

			if (visited_bfs[*iter] == false) {
				visited_bfs[*iter] = true;
				q.push(*iter);
			}
		}
	}

	cout << "\n";
}


int main_1260(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V;

	cin >> N >> M >> V;
	
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// ����
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(V);
	cout << "\n";

	bfs(V);

	return 0;
}