#include <iostream>

using namespace std;

int paper[100][100] = { {0, } };

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; // 색종이 수

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				paper[x + j][y + k] = 1;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (paper[i][j]) sum += 1;
		}
	}

	cout << sum;

	return 0;
}