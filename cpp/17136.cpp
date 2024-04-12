/*
17136��: ������ ���̱�

����
<�׸� 1>�� ���� ���簢�� ����� �� �ټ� ������ �����̰� �ִ�. �������� ũ��� 1��1, 2��2, 3��3, 4��4, 5��5�� �� �ټ� ������ ������, �� ������ �����̴� 5���� ������ �ִ�.



<�׸� 1>

�����̸� ũ�Ⱑ 10��10�� ���� ���� ���̷��� �Ѵ�. ���̴� 1��1 ũ���� ĭ���� �������� ������, ������ ĭ���� 0 �Ǵ� 1�� ���� �ִ�. 1�� ���� ĭ�� ��� �����̷� �������� �Ѵ�. �����̸� ���� ���� ������ ��� ������ �������� �ȵǰ�, ���ĵ� �� �ȴ�. ��, ĭ�� ���� ��ġ�ϰ� �ٿ��� �Ѵ�. 0�� ���� ĭ���� �����̰� ������ �� �ȴ�.

���̰� �־����� ��, 1�� ���� ��� ĭ�� ���̴µ� �ʿ��� �������� �ּ� ������ ���غ���.

�Է�
�� 10���� �ٿ� ������ �� ĭ�� ���� ���� �־�����.

���
��� 1�� ���µ� �ʿ��� �������� �ּ� ������ ����Ѵ�. 1�� ��� ���� ���� �Ұ����� ��쿡�� -1�� ����Ѵ�.


�׸���� Ǯ �� ����. (���x)
5^(10*10)..
dfs �� ��Ʈ��ŷ���� ����


�ּ� ��� � ���� �������� ��Ʈ��ŷ ������ ���� �� �ְڴ�. �ִ��� ��� ���Ѽ��� ���� ������ �����ϱ� ������ �� ����.

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
const int COLOR_ARRAY[COLOR_SIZE] = { 1,2,3,4,5 }; // ���� �̷��� ���
// board = visited �� �Ǿ�� ��.
int board[SIZE][SIZE] = { 0, }; // 1 �̸� ä���� ��
int visited[SIZE][SIZE] = { 0, }; // 1 �̸� ä���� �� (visited ����)
int pivot = GAME_OVER; // ��Ʈ��ŷ �꺸�� �� ���� ���� ���;� �� @@@

// �ϳ��� Ȯ���� �Ÿ� ���� ������ �� �׳� �Լ�ȭ ���Ѽ� ��������.
bool possibleToPlot(INFO info, int i) {
	if (info.p[i - 1] <= 0) return false;  // ������ �����ϴٸ�

	// ��ǥ ������ �� ���� (critical!!! / �� �κ� ������ ������ ���� �ɸ�. ���ʿ� �ٱ��� ���� ���̸� ������ �ʿ� ����.)
	if (info.num / SIZE + i - 1 >= SIZE || info.num % SIZE + i - 1 >= SIZE) return false;

	// �������� Ȯ��
	for (int j = 0; j < i; j++) { // row
		for (int k = 0; k < i; k++) { // column
			int r = info.num / SIZE + j;
			int c = info.num % SIZE + k;
			if (board[r][c] == 0 // �����̸� ���� �� ���ų�
			 /* || visited[r][c] == 1*/) { // �̹� �湮�߰ų� 
				return false;
			}
		}
	}

	return true;
}

int dfs(INFO info) {
	int result = GAME_OVER; // �⺻��
	
	// ���� ���� ���� �� ������ ��뷮
	int count = COLOR_SIZE * 5; // ���� 5���� ����
	for (int i = 0; i < COLOR_SIZE; i++) {
		count -= info.p[i];
	}

	// ��Ʈ��ŷ ���� Ȱ�� - paper �� result ���� ���ٸ� �������� �����Ƿ� ����
	if (count > pivot) return result;
	

	// ������ ���� �ʾƵ� �ȴٸ�, �̵���
	//while (info.num < SIZE * SIZE && board[info.num / SIZE][info.num % SIZE] == visited[info.num / SIZE][info.num % SIZE]) {
	while (info.num < SIZE * SIZE && board[info.num / SIZE][info.num % SIZE] == 0) {
		info.num++;
	}

	// num �� �䱸������ �ѱ� ��� ����
	if (info.num >= SIZE * SIZE) {
		if (count < 0) {
			return GAME_OVER;
		}
		else {
			pivot = MIN(pivot, count); // ��Ʈ��ŷ ���� ���� @@@@@@@@@@@@@@@
			return count;
		}
	}

	// DFS - ���ƾ� �� ���� �´ٸ�,
	for (int i = 1; i <= COLOR_SIZE; i++) { // p1 ~ p5

		bool possible = possibleToPlot(info, i);

		if (possible) {
			// �湮 ó��
			for (int j = 0; j <= i - 1; j++) { // row
				for (int k = 0; k <= i - 1; k++) { // column
					//visited[r][c] = 1;
					board[info.num / SIZE + j][info.num % SIZE + k] = 0;
				}
			}

			// �迭 ���� ���� ���� �ʱ�ȭ�ϴ� �͵� �ð��� �ɸ� (����õ @)
			int save = info.p[i - 1];
			info.p[i - 1] -= 1;

			// next �Ҵ� �� dfs ����
			result = MIN(result, dfs(info));

			// �湮ó�� ���
			for (int j = 0; j <= i - 1; j++) { // row
				for (int k = 0; k <= i - 1; k++) { // column
					//visited[r][c] = 0;
					board[info.num / SIZE + j][info.num % SIZE + k] = 1;
				}
			}

			info.p[i - 1] = save;

		}
		else {
			// �� ���� �͵� �ȵǸ� ū �͵� �� �� ��. --> ������ �����ؼ� ���� �͵� �����ؾ� ��.
			//return result; // ������ �����ؼ� ���� �͵� �����ؾ� ��.
			continue;
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