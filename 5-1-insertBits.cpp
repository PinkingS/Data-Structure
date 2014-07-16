#include <iostream>
#include <vector>

using namespace std;

int insertBits(int m, int n, int i, int j) {
	int left = ~((1 << (j+1))-1);
	int right = (1 << i) - 1;
	int mask = left | right;
	return (n << i) | (mask & m);
}

void printBinary(int n) {
	vector<int> v;
	int len = 8 * sizeof(int);
	int mask = 1;
	while(len--) {
		if(n & mask) v.push_back(1);
		else v.push_back(0);
		mask <<= 1;
	}
	while(!v.empty()) {
		cout << v.back();
		v.pop_back();
	}
	cout << endl;
}

int main() {
	int m = 1 << 10, n = 19;
	int i = 2, j = 6;

	int ans = insertBits(m, n, i, j);
	printBinary(n);
	printBinary(m);
	printBinary(ans);

	return 0;
}
