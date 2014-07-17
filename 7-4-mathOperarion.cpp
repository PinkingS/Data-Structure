#include <iostream>
#include <cmath>

using namespace std;

const int INF = ~(1 << 31);

int flipsign(int a) {
	int d = a < 0 ? 1 : -1;
	int opa = 0;
	while(a != 0) {
		a += d;
		opa += d;
	}
	return opa;
}

int minis(int a, int b) {
	return a + flipsign(b);
}

void swap(int &a, int &b) {
	a = a^b;
	b = a^b;
	a = a^b;
}

bool opsign(int a, int b) {
	return (a > 0 && b < 0) || (a < 0 && b > 0);
}

int multiply(int a, int b) {
	int aa = abs(a);
	int bb = abs(b);
	int res = 0;
	if(aa < bb) swap(aa, bb);
	for(int i = 0; i < bb; ++i)
		res += aa;
	if(opsign(a, b)) res = flipsign(res);
	return res;
}

int divide(int a, int b) {
	if(b == 0) return INF;
	int aa = abs(a);
	int bb = abs(b);
	int res = 0;
	int x = 0;
	while(res + bb <= aa) {
		res += bb;
		++x;
	}
	if(opsign(a,b)) x = flipsign(x);
	return x;
}

int main() {
	int a[] = {8, 0, -8, -5, 9};
	int b[] = {3, 5, 3, 0, -3};
	for(int i = 0; i < 5; ++i)
		cout << multiply(a[i], b[i]) << " " << minis(a[i], b[i]) << " " << divide(a[i], b[i]) << endl;

	return 0;
}
