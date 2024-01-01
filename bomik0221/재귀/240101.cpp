#include <iostream>
using namespace std;

long combination(int m, int n) {
	if (m == n || n == 0) return 1;
	else
		return combination(m - 1, n - 1) + combination(m - 1, n);
}

int main() {
	int t; //test case
	int n, m;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		cout << combination(m,n) << endl;
	}

	return 0;
}