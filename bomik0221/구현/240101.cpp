#include <iostream>
using namespace std;

int main() {
	//1 <= N <= 100
	int N;
	cin >> N;

	int a = 1;

	for (int i = 0; i <= N; i++) {
		if (i > 0) {
			for (int j = 0; j < i; j++) {
				cout << " ";
			}
		}
		for (int k = 0; k < 2 * N - a; k++) {
			cout << "*";
		}
		cout << "\n";
		a += 2;
	}
	return 0;
}