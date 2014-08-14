#include <iostream>
#include <cmath>

using namespace std;

void merge(int a[], int b[], int m, int n) {
	int k = m+n-1;
	int i = m-1, j = n-1;
	while(i >= 0 && j >= 0) {
		if(a[i] > b[j]) 
			a[k--] = a[i--];
		else
			a[k--] = b[j--];
	}
	while(j >= 0) a[k--] = b[j--];
}

int main() {
	int a[15] = {1, 3, 5, 7, 9};
	int b[] = {2, 4, 5, 11, 12};
	merge(a, b, 5, 5);
	for(int i = 0; i < 10; ++i)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
