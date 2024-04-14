#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct test {
	int a;
	int b;
	int c;

	test(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
};

struct test_compare {
	bool operator()(const test& left, const test& right) {
		if (left.a != right.a)
			return left.a < right.a;
		if (left.b != right.b)
			return left.b > right.b;
		return left.c < right.c;
	}
};

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<test> v;
	test t1(0, 0, 0);
	v.push_back(t1);
	test t2(0, 1, 1);
	v.push_back(t2);
	test t3(0, 2, 2);
	v.push_back(t3);
	test t4(1, 1, 1);
	v.push_back(t4);

	sort(v.begin(), v.end(), test_compare());

	for (auto iter = v.begin(); iter != v.end(); iter++) {
		cout << iter->a << " " << iter->b << " " << iter->c << "\n";
	}
	

	return 0;
}