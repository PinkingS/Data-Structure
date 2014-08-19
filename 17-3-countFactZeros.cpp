#include <iostream>

using namespace std;

long long fact(int n) {
	long long res = 1;
	for(int i = 1; i <= n; ++i)
		res *= i;
	return res;
}

int countFactZeros(int n) {
	if(n < 0) return -1;
	int num = 0;
	while((n /= 5) > 0) {
		num += n;
	}
	return num;
}

int main() {
	int n = 14;
	cout << fact(n) << endl;
	cout << countFactZeros(n) << endl;
	return 0;
}
