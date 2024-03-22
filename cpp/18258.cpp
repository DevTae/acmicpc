/*
ť 2
https://www.acmicpc.net/problem/18258
*/

#include <iostream>
#include <queue>

int main_18258(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::queue<int> q;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::string cmd;
		std::cin >> cmd;
		int num;

		if (cmd == "push") {
			std::cin >> num;
			q.push(num);
		}
		else if (cmd == "pop") {
			if (q.empty()) {
				std::cout << -1 << "\n";
			}
			else {
				num = q.front();
				q.pop();
				std::cout << num << "\n";
			}
		}
		else  if (cmd == "size") {
			std::cout << q.size() << "\n";
		}
		else if (cmd == "empty") {
			if (q.empty()) {
				std::cout << 1 << "\n";
			}
			else {
				std::cout << 0 << "\n";
			}
		}
		else if (cmd == "front") {
			if (q.empty()) {
				std::cout << -1 << "\n";
			}
			else {
				std::cout << q.front() << "\n";
			}
		}
		else if (cmd == "back") {
			if (q.empty()) {
				std::cout << -1 << "\n";
			}
			else {
				std::cout << q.back() << "\n";
			}
		}
	}

	return 0;
}