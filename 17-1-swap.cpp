#include <iostream>

using namespace std;

void swap(int &a, int &b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int main() {
	int a = 5, b = 3;
	swap(a, b);
	cout << a << " " << b << endl;
	return 0;
}
