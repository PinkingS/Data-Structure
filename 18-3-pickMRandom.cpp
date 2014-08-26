#include <iostream>
#include <cstdlib>

using namespace std;

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

void pickMRandom(int a[], int n, int m) {
	for(int i = 0; i < m; ++i) {
		int k = rand() % (n-i) + i;
		swap(a[i], a[k]);
	}
}

int main() {
	int n = 9, m = 5;
	srand((unsigned)time(0));
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	pickMRandom(a, n, m);
	for(int i = 0; i < m; ++i)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
