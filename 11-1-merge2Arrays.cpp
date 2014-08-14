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

void swap(int &a, int &b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void merge_2(int a[], int begin, int mid, int end) {
	for(int i = begin; i <= mid; ++i) {
		if(a[i] > a[mid+1]) {
			swap(a[i], a[mid+1]);
			for(int j = mid+1; j < end; ++j) {
				if(a[j] <= a[j+1]) break;
				swap(a[j], a[j+1]);
			}
		}
	}
}

int main() {
	int a[15] = {1, 3, 5, 7, 9};
	int b[] = {2, 4, 5, 11, 12};
	merge(a, b, 5, 5);
	for(int i = 0; i < 10; ++i)
		cout << a[i] << " ";
	cout << endl;
	
	int c[] = {8, 9, 11, 15, 17, 1, 3, 5, 12 ,18};
	merge_2(c, 0, 4, 9);
	for(int i = 0; i < 10; ++i)
		cout << c[i] << " ";
	cout << endl;	

	return 0;
}
