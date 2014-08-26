#include <iostream>
#include <cstdlib>

using namespace std;

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

void randomShuffle(int a[], int n) {
	for(int i=0; i < n; ++i) {
		int k = rand() % (n-i) + i;
		swap(a[i], a[k]);
	}
}

int main() {
	srand((unsigned)time(0));
	int n = 9;
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	randomShuffle(a, n);
	for(int i=0; i<n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
