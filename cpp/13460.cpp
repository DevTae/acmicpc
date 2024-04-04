#include <iostream>
#define MAX_TRIAL 10
#define MAX_SIZE 10
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a > b) ? b : a)

using namespace std;

int N, M;
char board[MAX_SIZE][MAX_SIZE];

// �� ����Ʈ�� ���Ͽ� Ʈ��ŷ ����
int r_r, r_c; // red
int b_r, b_c; // blue
int o_r, o_c; // hole 

bool is_possible(int i, int j) {
	if (board[i][j] == '.' || (i == o_r && j == o_c)) {
		return true;
	}
	return false;
}

bool is_goal(int i, int j) {
	if (i == o_r && j == o_c) {
		return true;
	}
	return false;
}

// board �� �ٲٱ�
void board_swap(int i, int j, int p, int q) {
	int temp = board[i][j];

	board[i][j] = board[p][q];

	board[p][q] = temp;
}

// back-tracking
int back(int remained) {

	int value = MAX_TRIAL + 1; // �⺻��

	// ���� �� Ż�� ���� ��, 10 - r
	if (r_r == o_r && r_c == o_c && !(b_r == o_r && b_c == o_c)) {
		return MAX_TRIAL - remained;
	}
	// Ƚ�� �����̰ų� �Ķ����� ������ ���� �Ǵ�
	else if (remained == 0 || (b_r == o_r && b_c == o_c)) {
		return value;
	}

	// �߷� ����
	// �Ķ��� ���� ���ʿ� ������,
	if (b_c < r_c) {
		int i = b_c;
		for (; i > 0; i--) {
			if (!is_possible(b_r, i-1)) {
				break;
			}
			if (is_goal(b_r, i - 1)) {
				i--;
				break;
			}
		}
		
		board_swap(b_r, b_c, b_r, i);
		int temp_b_c = b_c;
		b_c = i;
		
		int j = r_c;
		for (; j > 0; j--) {
			if (!is_possible(r_r, j-1)) {
				break;
			}
			if (is_goal(r_r, j - 1)) {
				j--;
				break;
			}
		}

		board_swap(r_r, r_c, r_r, j);
		int temp_r_c = r_c;
		r_c = j;

		value = MIN(value, back(remained - 1));

		board_swap(r_r, r_c, r_r, temp_r_c);
		r_c = temp_r_c;

		board_swap(b_r, b_c, b_r, temp_b_c);
		b_c = temp_b_c;
	}
	else {
		int j = r_c;
		for (; j > 0; j--) {
			if (!is_possible(r_r, j-1)) {
				break;
			}
			if (is_goal(r_r, j - 1)) {
				j--;
				break;
			}

		}

		board_swap(r_r, r_c, r_r, j);
		int temp_r_c = r_c;
		r_c = j;

		int i = b_c;
		for (; i > 0; i--) {
			if (!is_possible(b_r, i-1)) {
				break;
			}
			if (is_goal(b_r, i - 1))
			{
				i--;
				break;
			}
		}

		board_swap(b_r, b_c, b_r, i);
		int temp_b_c = b_c;
		b_c = i;

		

		value = MIN(value, back(remained - 1));

		board_swap(b_r, b_c, b_r, temp_b_c);
		b_c = temp_b_c;

		board_swap(r_r, r_c, r_r, temp_r_c);
		r_c = temp_r_c;
		
	}

	// �߷� ������
	if (b_c < r_c) {
		int j = r_c;
		for (; j < MAX_SIZE - 1; j++) {
			if (!is_possible(r_r, j + 1)) {
				break;
			}
			if (is_goal(r_r, j + 1)) {
				j++;
				break;
			}
		}

		board_swap(r_r, r_c, r_r, j);
		int temp_r_c = r_c;
		r_c = j;

		int i = b_c;
		for (; i < MAX_SIZE - 1; i++) {
			if (!is_possible(b_r, i + 1)) {
				break;
			}
			if (is_goal(b_r, i + 1)) {
				i++;
				break;
			}
		}

		board_swap(b_r, b_c, b_r, i);
		int temp_b_c = b_c;
		b_c = i;

		value = MIN(value, back(remained - 1));

		board_swap(b_r, b_c, b_r, temp_b_c);
		b_c = temp_b_c;

		board_swap(r_r, r_c, r_r, temp_r_c);
		r_c = temp_r_c;
	}
	else {

		int i = b_c;
		for (; i < MAX_SIZE - 1; i++) {
			if (!is_possible(b_r, i + 1)) {
				break;
			}
			if (is_goal(b_r, i + 1)) {
				i++;
				break;
			}
		}

		board_swap(b_r, b_c, b_r, i);
		int temp_b_c = b_c;
		b_c = i;

		
		int j = r_c;
		for (; j < MAX_SIZE - 1; j++) {
			if (!is_possible(r_r, j + 1)) {
				break;
			}
			if (is_goal(r_r, j + 1)) {
				j++;
				break;
			}
		}

		board_swap(r_r, r_c, r_r, j);
		int temp_r_c = r_c;
		r_c = j;


		value = MIN(value, back(remained - 1));

		board_swap(r_r, r_c, r_r, temp_r_c);
		r_c = temp_r_c;


		board_swap(b_r, b_c, b_r, temp_b_c);
		b_c = temp_b_c;

		
	}


	// �߷� ��
	if (b_r < r_r) {

		int i = b_r;
		for (; i > 0; i--) {
			if (!is_possible(i - 1, b_c)) {
				break;
			}
			if (is_goal(i - 1, b_c)) {
				i--;
				break;
			}
		}

		board_swap(b_r, b_c, i, b_c);
		int temp_b_r = b_r;
		b_r = i;


		int j;
		for (j = r_r; j > 0; j--) {
			if (!is_possible(j-1, r_c)) {
				break;
			}
			if (is_goal(j - 1, r_c)) {
				j--;
				break;
			}
		}

		board_swap(r_r, r_c, j, r_c);
		int temp_r_r = r_r;
		r_r = j;

		
		value = MIN(value, back(remained - 1));

		board_swap(r_r, r_c, temp_r_r, r_c);
		r_r = temp_r_r;


		board_swap(b_r, b_c, temp_b_r, b_c);
		b_r = temp_b_r;
	}
	else {


		int j = r_r;
		for (; j > 0; j--) {
			if (!is_possible(j - 1, r_c)) {
				break;
			}
			if (is_goal(j - 1, r_c)) {
				j--;
					break;
			}
		}

		board_swap(r_r, r_c, j, r_c);
		int temp_r_r = r_r;
		r_r = j;


		int i = b_r;
		for (; i > 0; i--) {
			if (!is_possible(i - 1, b_c)) {
				break;
			}
			if (is_goal(i - 1, b_c)) {
				i--;
				break;
			}
		}

		board_swap(b_r, b_c, i, b_c);
		int temp_b_r = b_r;
		b_r = i;



		value = MIN(value, back(remained - 1));

		board_swap(b_r, b_c, temp_b_r, b_c);
		b_r = temp_b_r;


		board_swap(r_r, r_c, temp_r_r, r_c);
		r_r = temp_r_r;

	}


	// �߷� �Ʒ�
	if (b_r < r_r) {

		int j = r_r;
		for (; j < MAX_SIZE - 1; j++) {
			if (!is_possible(j + 1, r_c)) {
				break;
			}
			if (is_goal(j + 1, r_c)) {
				j++;
				break;
			}
		}

		board_swap(r_r, r_c, j, r_c);
		int temp_r_r = r_r;
		r_r = j;


		int i = b_r;
		for (; i < MAX_SIZE - 1; i++) {
			if (!is_possible(i + 1, b_c)) {
				break;
			}
			if (is_goal(i + 1, b_c)) {
				i++;
				break;
			}
		}

		board_swap(b_r, b_c, i, b_c);
		int temp_b_r = b_r;
		b_r = i;


		value = MIN(value, back(remained - 1));


		board_swap(b_r, b_c, temp_b_r, b_c);
		b_r = temp_b_r;


		board_swap(r_r, r_c, temp_r_r, r_c);
		r_r = temp_r_r;
		
	}
	else {


		int i = b_r;
		for (; i < MAX_SIZE - 1; i++) {
			if (!is_possible(i + 1, b_c)) {
				break;
			}
			if (is_goal(i + 1, b_c)) {
				i++;
				break;
			}
		}

		board_swap(b_r, b_c, i, b_c);
		int temp_b_r = b_r;
		b_r = i;



		int j = r_r;
		for (; j < MAX_SIZE - 1; j++) {
			if (!is_possible(j + 1, r_c)) {
				break;
			}
			if (is_goal(j + 1, r_c)) {
				j++;
				break;
			}
		}

		board_swap(r_r, r_c, j, r_c);
		int temp_r_r = r_r;
		r_r = j;



		value = MIN(value, back(remained - 1));


		board_swap(r_r, r_c, temp_r_r, r_c);
		r_r = temp_r_r;


		board_swap(b_r, b_c, temp_b_r, b_c);
		b_r = temp_b_r;


	}

	return value;
}

int main(void) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	// N (����), M (����) �Է� ����
	cin >> N >> M;

	// board �Է� �ޱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char ch = cin.get();
			if (ch == '\n')
				ch = cin.get();

			board[i][j] = ch;

			if (ch == 'R') {
				r_r = i;
				r_c = j;
			}
			else if (ch == 'B') {
				b_r = i;
				b_c = j;
			}
			else if (ch == 'O') {
				o_r = i;
				o_c = j;
				board[i][j] = '.';
			}
		}
	}

	// Ƚ�� MAX_TRIAL �ִ뿡 ���Ͽ� �ּ� �� ���� �߷��� �ʿ�����
	int num = back(MAX_TRIAL);

	if (num == MAX_TRIAL + 1) {
		cout << -1;
	}
	else {
		cout << num;
	}

	return 0;
}