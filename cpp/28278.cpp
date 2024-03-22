#include <iostream>
#include <stack>

/*
Ω∫≈√ 2
https://www.acmicpc.net/problem/28278
*/

int main_28278(void) {
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::stack<int> s;

	int N;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int cmd;
		int num;
		bool isEmpty;

		std::cin >> cmd; 

		switch (cmd) {
		case 1: // push
			std::cin >> num;
			s.push(num);
			break;
		case 2: // pop
			isEmpty = s.empty();
			if (isEmpty) {
				std::cout << -1 << "\n";
			}
			else {
				num = s.top();
				s.pop();
				std::cout << num << "\n";
			}
			break;
		case 3: // count
			num = s.size();
			std::cout << num << "\n";
			break;
		case 4: // isEmpty
			isEmpty = s.empty();
			std::cout << (isEmpty ? 1 : 0) << "\n";
			break;
		case 5: // top
			isEmpty = s.empty();
			if (isEmpty) {
				std::cout << -1 << "\n";
			}
			else {
				std::cout << s.top() << "\n";
			}
			break;
		}
	}

	return 0;
}