#include <iostream>
#include <map>

/*
숫자 카드
https://www.acmicpc.net/problem/10815
*/

int main_10816(void) {
	int N, M;
	std::map<int, int> cards;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		std::cin >> num;
		cards.insert(std::pair<int, int>(num, 1));
	}

	std::cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		std::cin >> num;
		
		// 못 찾았다면,
		if (cards.find(num) == cards.end()) {
			std::cout << 0 << " ";
		}
		else {
			std::cout << 1 << " ";
		}
	}

	return 0;
	
}