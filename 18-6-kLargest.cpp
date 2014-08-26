#include <iostream>

using namespace std;

void swap(int &a, int &b) {
	a = a^b;
	b = a^b;
	a = a^b;
}

int partition(int a[], int low, int high) {
	int pivot = a[low];
	int i = low, j = high;
	while(i < j) {
		while(i < j && a[j] > pivot) --j;
		if(i < j) swap(a[i], a[j]);
		while(i < j && a[i] <= pivot) ++i;
		if(i < j) swap(a[i], a[j]);
	}
	return i;
}

int findKLargest(int a[], int low, int high, int k) {
	int leftEnd = partition(a, low, high);
	int leftSize = leftEnd - low + 1;
	if(leftSize == k)
		return leftEnd;
	else if(leftSize < k)
		return findKLargest(a, leftEnd+1, high, k-leftSize);
	else
		return findKLargest(a, low, leftEnd-1, k);
}

int main() {
	int n = 10;
	int k = 5;
	int a[] = {5, 9, 2, 14, 3, 8, 21, 35, 12, 1};
	int index = findKLargest(a, 0, n-1, k);
	for(int i = 0; i <= index; ++i)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
