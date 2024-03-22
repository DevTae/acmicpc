/*
* https://www.acmicpc.net/problem/27433
* ÆÑÅä¸®¾ó 2
* 
*/

#include <iostream>

using namespace std;

int memo[21];

long long factorial(long long n) {
	if (n == 1 || n == 0) {
		return 1;
	}
	else {
		if (memo[n - 1]) {
			return n * memo[n - 1];
		} else {
			return n * factorial(n - 1);
		}
	}
}

int main_27433(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	cout << factorial(N);

	return 0;

	
}