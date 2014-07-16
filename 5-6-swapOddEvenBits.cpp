#include <iostream>
#include <string>

using namespace std;

void printBinary(int x) {
	string s = "";
	for(int i = 0; i < 32; ++i) {
		if(x&1) s = "1" + s;
		else
			s = "0" + s;
		x >>= 1;
	}
	cout << s << endl;
}

int swapBits(int x) {
	return ((x & 0x55555555) << 1) | ((x & 0xaaaaaaaa) >> 1);
}

int main() {
	int x = 7665543;
	printBinary(x);
	printBinary(swapBits(x));
	return 0;
}
