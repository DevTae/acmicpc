/*
17070���� ������ �ű��
https://www.acmicpc.net/problem/17070

����
�����̰� �� ������ �̻��ߴ�. �� ���� ũ��� N��N�� ���������� ��Ÿ�� �� �ְ�, 1��1ũ���� ���簢�� ĭ���� �������� �ִ�. ������ ĭ�� (r, c)�� ��Ÿ�� �� �ִ�. ���⼭ r�� ���� ��ȣ, c�� ���� ��ȣ�̰�, ��� ���� ��ȣ�� 1���� �����Ѵ�. ������ ĭ�� �� ĭ�̰ų� ���̴�.

������ �� ������ ���ؼ� ������ �ϳ��� �ű���� �Ѵ�. �������� �Ʒ��� ���� �����̰�, 2���� ���ӵ� ĭ�� �����ϴ� ũ���̴�.

�������� ȸ����ų �� ������, �Ʒ��� ���� 3���� ������ �����ϴ�.

�������� �ſ� ���̱� ������, �����̴� �������� �о �̵���Ű���� �Ѵ�. ������ ���ο� ������ �߶��� ������, �������� ���� ������ �� �ȴ�. ��, �������� �׻� �� ĭ�� �����ؾ� �Ѵ�.

�������� �� �� �ִ� ������ �� 3������ ������, ��, ��, �� �����̴�. �������� �и鼭 ȸ����ų �� �ִ�. ȸ���� 45���� ȸ����ų �� ������, �̴� ������ ������, �Ʒ�, �Ǵ� ������ �Ʒ� �밢�� �����̾�� �Ѵ�.

�������� ���η� ������ ��쿡 ������ �̵� ����� �� 2����, ���η� ������ ��쿡�� 2����, �밢�� �������� ������ ��쿡�� 3������ �ִ�.

�Ʒ� �׸��� �������� ������ ���⿡ ���� �̵��� �� �ִ� ����� ��� ��Ÿ�� ���̰�, �� �� ĭ�̾�� �ϴ� ���� ������ ǥ�õǾ��� �ִ�.

����

����

�밢��

���� ó���� �������� (1, 1)�� (1, 2)�� �����ϰ� �ְ�, ������ �����̴�. �������� ���� ���� (N, N)�� �̵���Ű�� ����� ������ ���غ���.


�Է�
ù° �ٿ� ���� ũ�� N(3 �� N �� 16)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���� ���°� �־�����. �� ĭ�� 0, ���� 1�� �־�����. (1, 1)�� (1, 2)�� �׻� �� ĭ�̴�.


���
ù° �ٿ� �������� ���� ���� (N, N)���� �̵���Ű�� ����� ���� ����Ѵ�. �̵���ų �� ���� ��쿡�� 0�� ����Ѵ�. ����� ���� �׻� 1,000,000���� �۰ų� ����.


row 1, column 1 ~ 2 �� ��ġ��

3^16 = �� 4300�� ���� �����̹Ƿ�, 1�� ���� ���� ����.

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
//bool visited[17][17] = { false, }; // false �� �ʱ�ȭ

// �׷��� ������ ��� ����
int dc_horizontal[2] = { 1, 1 };
int dr_horizontal[2] = { 0, 1 };
int dc_vertical[2] = { 0, 1 };
int dr_vertical[2] = { 1, 1 };
int dc_diagonal[3] = { 1, 0, 1 };
int dr_diagonal[3] = { 0, 1, 1 };

// ������ ������ ���� enum ��ȯ
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
	* ��� �׽�Ʈ
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