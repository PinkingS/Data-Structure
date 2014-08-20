#include <iostream>

using namespace std;

int findBigger(int a, int b) {
	int arr[2] = {a, b};
	int c = a-b;
	int k = (c>>31)&0x1;
	return arr[k];
}

int findBigger_2(int a, int b) {
	int c = a-b;
	int k = (c>>31) & 1;
	return a - k * c;
}

int main() {
	int a=3, b=5;
	cout << findBigger_2(a, b) << endl;
	return 0;
}
