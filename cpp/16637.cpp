/*
https://www.acmicpc.net/problem/16637

16637번: 괄호 추가하기

문제
길이가 N인 수식이 있다. 수식은 0보다 크거나 같고, 9보다 작거나 같은 정수와 연산자(+, -, ×)로 이루어져 있다. 
연산자 우선순위는 모두 동일하기 때문에, 수식을 계산할 때는 왼쪽에서부터 순서대로 계산해야 한다. 
예를 들어, 3+8×7-9×2의 결과는 136이다.

수식에 괄호를 추가하면, 괄호 안에 들어있는 식은 먼저 계산해야 한다. 단, 괄호 안에는 연산자가 하나만 들어 있어야 한다. 
예를 들어, 3+8×7-9×2에 괄호를 3+(8×7)-(9×2)와 같이 추가했으면, 식의 결과는 41이 된다. 
하지만, 중첩된 괄호는 사용할 수 없다. 즉, 3+((8×7)-9)×2, 3+((8×7)-(9×2))은 모두 괄호 안에 괄호가 있기 때문에, 올바른 식이 아니다.

수식이 주어졌을 때, 괄호를 적절히 추가해 만들 수 있는 식의 결과의 최댓값을 구하는 프로그램을 작성하시오. 
추가하는 괄호 개수의 제한은 없으며, 추가하지 않아도 된다.

입력
첫째 줄에 수식의 길이 N(1 ≤ N ≤ 19)가 주어진다. 둘째 줄에는 수식이 주어진다. 
수식에 포함된 정수는 모두 0보다 크거나 같고, 9보다 작거나 같다. 문자열은 정수로 시작하고, 
연산자와 정수가 번갈아가면서 나온다. 연산자는 +, -, * 중 하나이다. 여기서 *는 곱하기 연산을 나타내는 × 연산이다. 
항상 올바른 수식만 주어지기 때문에, N은 홀수이다.

출력
첫째 줄에 괄호를 적절히 추가해서 얻을 수 있는 결과의 최댓값을 출력한다. 
정답은 231보다 작고, -231보다 크다.

*/

#include <iostream>
#define MAX(a,b) ((a > b) ? a : b)

using namespace std;

int N;
char expr[20];

// +, -, * 에 대하여 순서 상관 없이 연산 진행
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

// from 부터 to 까지의 계산을 진행 (from 과 to 에 해당되는 자리에는 숫자가 들어감)
int calc_rec(int from, int to) {
	if (from >= to) {
		return expr[to] - 48;
	}
	else {
		return calc(expr[from + 1], expr[from] - 48, calc_rec(from + 2, to));
	}
}

// 계산하기 시작할 수 있는 숫자에 대하여 wait_index 로 설정
//
int dfs(int index, int prev_result, int wait_index) {
	char op = expr[index];

	// (전제조건) index 가 끝까지 왔다면 prev_result 와 나머지 계산을 진행한 뒤에 끝냄
	if (index == N) {
		// 처음부터 한꺼번에 쭉 계산일 때,
		if (wait_index == 0) {
			return calc_rec(wait_index, N - 1);
		}
		// 아닐 때,
		else if (wait_index == N + 1) {
			return prev_result;
		}
		else {
			return calc(expr[wait_index - 1], prev_result, calc_rec(wait_index, N - 1));
		}
	}
	// (재귀구현)
	else {
		// 연산자이면 다음 인덱스로 넘어가기
		if (op == '+' || op == '-' || op == '*') {
			return dfs(index + 1, prev_result, wait_index);
		}
		// 숫자이면 계산하거나 넘어가기
		else {
			// case1. 쌓인 거 바로 계산하고 넘어가는 경우
			// case2. 뒤로 미루는 경우 (연산자 하나만 넣을 수 있음)
			// 에 대하여 최댓값 구하는 로직 진행

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