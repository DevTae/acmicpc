/*
https://www.acmicpc.net/problem/16637

16637��: ��ȣ �߰��ϱ�

����
���̰� N�� ������ �ִ�. ������ 0���� ũ�ų� ����, 9���� �۰ų� ���� ������ ������(+, -, ��)�� �̷���� �ִ�. 
������ �켱������ ��� �����ϱ� ������, ������ ����� ���� ���ʿ������� ������� ����ؾ� �Ѵ�. 
���� ���, 3+8��7-9��2�� ����� 136�̴�.

���Ŀ� ��ȣ�� �߰��ϸ�, ��ȣ �ȿ� ����ִ� ���� ���� ����ؾ� �Ѵ�. ��, ��ȣ �ȿ��� �����ڰ� �ϳ��� ��� �־�� �Ѵ�. 
���� ���, 3+8��7-9��2�� ��ȣ�� 3+(8��7)-(9��2)�� ���� �߰�������, ���� ����� 41�� �ȴ�. 
������, ��ø�� ��ȣ�� ����� �� ����. ��, 3+((8��7)-9)��2, 3+((8��7)-(9��2))�� ��� ��ȣ �ȿ� ��ȣ�� �ֱ� ������, �ùٸ� ���� �ƴϴ�.

������ �־����� ��, ��ȣ�� ������ �߰��� ���� �� �ִ� ���� ����� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 
�߰��ϴ� ��ȣ ������ ������ ������, �߰����� �ʾƵ� �ȴ�.

�Է�
ù° �ٿ� ������ ���� N(1 �� N �� 19)�� �־�����. ��° �ٿ��� ������ �־�����. 
���Ŀ� ���Ե� ������ ��� 0���� ũ�ų� ����, 9���� �۰ų� ����. ���ڿ��� ������ �����ϰ�, 
�����ڿ� ������ �����ư��鼭 ���´�. �����ڴ� +, -, * �� �ϳ��̴�. ���⼭ *�� ���ϱ� ������ ��Ÿ���� �� �����̴�. 
�׻� �ùٸ� ���ĸ� �־����� ������, N�� Ȧ���̴�.

���
ù° �ٿ� ��ȣ�� ������ �߰��ؼ� ���� �� �ִ� ����� �ִ��� ����Ѵ�. 
������ 231���� �۰�, -231���� ũ��.

*/

#include <iostream>
#define MAX(a,b) ((a > b) ? a : b)

using namespace std;

int N;
char expr[20];

// +, -, * �� ���Ͽ� ���� ��� ���� ���� ����
int calc(char op, int a, int b) {
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	default:
		// return nothing (cause exception)
		break;
	}
}

// from ���� to ������ ����� ���� (from �� to �� �ش�Ǵ� �ڸ����� ���ڰ� ��)
int calc_rec(int from, int to) {
	if (from >= to) {
		return expr[to] - 48;
	}
	else {
		return calc(expr[from + 1], expr[from] - 48, calc_rec(from + 2, to));
	}
}

// ����ϱ� ������ �� �ִ� ���ڿ� ���Ͽ� wait_index �� ����
//
int dfs(int index, int prev_result, int wait_index) {
	char op = expr[index];

	// (��������) index �� ������ �Դٸ� prev_result �� ������ ����� ������ �ڿ� ����
	if (index == N) {
		// ó������ �Ѳ����� �� ����� ��,
		if (wait_index == 0) {
			return calc_rec(wait_index, N - 1);
		}
		// �ƴ� ��,
		else if (wait_index == N + 1) {
			return prev_result;
		}
		else {
			return calc(expr[wait_index - 1], prev_result, calc_rec(wait_index, N - 1));
		}
	}
	// (��ͱ���)
	else {
		// �������̸� ���� �ε����� �Ѿ��
		if (op == '+' || op == '-' || op == '*') {
			return dfs(index + 1, prev_result, wait_index);
		}
		// �����̸� ����ϰų� �Ѿ��
		else {
			// case1. ���� �� �ٷ� ����ϰ� �Ѿ�� ���
			// case2. �ڷ� �̷�� ��� (������ �ϳ��� ���� �� ����)
			// �� ���Ͽ� �ִ� ���ϴ� ���� ����

			// case1
			int result = dfs(index + 1, wait_index == 0 ? calc_rec(wait_index, index) : calc(expr[wait_index - 1], prev_result, calc_rec(wait_index, index)), index + 2);
			
			// case2 
			if (wait_index == index)
				result = MAX(result, dfs(index + 1, prev_result, wait_index));
			
			return result;
		}
	}

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> expr;

	int result = dfs(0, 0, 0);

	cout << result;

	return 0;
}