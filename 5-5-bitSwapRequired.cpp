#include <iostream>

using namespace std;

int bitSwapRequired(int a, int b) {
	int c = a^b;
	int cnt = 0;
	for(int i = 0; i < 32; ++i) {
		cnt += c&1;
		c >>= 1;
	}
	return cnt;
}

int main() {
	int a = 0xF2;
	int b = 0x97;
	cout << bitSwapRequired(a, b) << endl;
	return 0;
}
