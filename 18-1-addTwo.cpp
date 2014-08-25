#include <iostream>

using namespace std;

int addTwo(int a, int b) {
	if(b == 0) return a;
	int sum = a^b;
	int carry = (a&b) << 1;
	return addTwo(sum, carry);
}

int addTwo_2(int a, int b) {
	char *c = (char*)a;
	return (int)&c[b];
}

int main() {
	int a = 762;
	int b = 345;
	cout << addTwo_2(a, b) << endl;
	return 0;
}
