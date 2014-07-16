#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

// solution 1 : can fetch(a, i, j)
int fetch(int a[], int i, int j) {
	return (a[i] >> j) & 1;
}

int get(int a[], int i) {
	int ret = 0;
	for(int j = 31; j >= 0; --j)
		ret = (ret << 1) | fetch(a, i, j);
	return ret;
}



// solution 2 : only can fetch(a, j)
int fetch_2(int a[], int i) {
	return (a[i/32] >> (i % 32)) & 1;
}

int get_2(int a[], int i) {
	int ret = 0;
	int base = 32 * i;
	for(int j = base+31; j >= base; --j)
		ret = (ret << 1) | fetch_2(a, j);
	return ret;
}

int findMissing(int a[], int n) {
	bool *b = new bool[n+1];
	memset(b, false, sizeof(b));
	for(int i = 0; i < n; ++i)
		b[get_2(a, i)] = true;
	for(int i = 0; i <= n; ++i)
		if(!b[i]) return i;
	delete[] b;
}

// solution 3 : O(2N) solution
int fetch_3(int x, int i) {
	return (x >> i) & 1;
}

int findMissing_3(vector<int> num, int column) {
	if(column >= 32)
		return 0;
	vector<int> onebits, zerobits;

	for(int i = 0; i < num.size(); ++i) {
		if(fetch_3(num[i], column) == 0)
			zerobits.push_back(num[i]);
		else
			onebits.push_back(num[i]);
	}

	if(zerobits.size() <= onebits.size()) {
		int v = findMissing_3(zerobits, column+1);
		return (v << 1) | 0;
	} else {
		int v = findMissing_3(onebits, column+1);
		return (v << 1) | 1;
	}
}

int findMissing_3(vector<int> num) {
	return findMissing_3(num, 0);
}

int main() {
	int a[] = {0, 1, 2, 3, 4, 5, 6, 8, 9};
	cout << findMissing(a, 9) << endl;

	vector<int> num(a, a+9);
	cout << findMissing_3(num) << endl;

	return 0;
}
