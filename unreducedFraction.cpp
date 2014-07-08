#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if(a < b) {
		int tmp = a;
		a = b;
		b = a;
	}
	int r;
	while(b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void unreducedFraction(int m, int n, int p) {
	for(int below = m; below <= n; ++below) {
		cout << "1/" << below << endl;
		for(int up = 2; up <= p; ++up) {
			if(gcd(below, up) == 1)
				cout << up << "/" << below << endl;
		}
	}
}

int main() {
	int m = 5, n = 10, p = 4;
	unreducedFraction(m, n, p);
	return 0;
}
