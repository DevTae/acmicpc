/*
������ȣ���̱�
https://www.acmicpc.net/problem/2667

1. �׷��� ���
  �׷��� ������� �߰��ϱ�
  (1, 2) -> (2, 2), (1, 3) ����
  visited üũ(���� (2,2), (1,3) �� �湮 �Ϸ�)�ϸ鼭 NxN �� ���� �ݺ��� ����.

2. �迭 ���
  (1, 2) �������� �����¿� �������� DFS (��ͷ� ������ ���ϱ�) ����.
  visited �߰��Ͽ� Ȯ�����ֱ�
  
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
			apart[i][j] = num - 48; // 48 ���ִ� �� �߿�! �ƽ�Ű�ڵ� Ȱ��
		}
	}

	// dfs ��� ���� ũ�� ���ϱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && apart[i][j]) {
				int count = dfs(i, j);
				clusters.push_back(count);
			}
		}
	}

	// ���� ����
	sort(clusters.begin(), clusters.end());

	cout << clusters.size() << "\n";

	// ������������ ���� ũ�� ���
	for (auto iter = clusters.begin(); iter != clusters.end(); iter++) {
		cout << *iter << "\n";
	}

	return 0;

}