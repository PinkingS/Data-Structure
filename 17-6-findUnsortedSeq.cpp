#include <iostream>
#include <algorithm>

using namespace std;

void findUnsortedSeq(int a[], int n) {
	int b[n];
	for(int i = 0; i < n; ++i)
		b[i] = a[i];
	sort(b, b+n);

	int start = 0;
	while(b[start] == a[start] && start < n)
		++start;
	int end = n-1;
	while(b[end] == a[end] && end >= 0)
		--end;
	
	cout << start << " to " << end << endl;
}

int findEndOfLeftSubseq(int a[], int n) {
	for(int i = 1; i < n; ++i)
		if(a[i] < a[i-1])
			return i-1;
	return n-1;
}

int findStartOfRightSubseq(int a[], int n) {
	for(int i = n-2; i >= 0; --i)
		if(a[i] > a[i+1])
			return i+1;
	return 0;
}

int shrinkLeft(int a[], int minIdx, int leftEnd) {
	int min = a[minIdx];
	for(int i = leftEnd; i >= 0; --i)
		if(a[i] < min) return i+1;
	return 0;
}

int shrinkRight(int a[], int maxIdx, int rightStart, int n) {
	int max = a[maxIdx];
	for(int i = rightStart; i < n; ++i)
		if(a[i] >= max) return i-1;
	return n-1;
}

void findUnsortedSeq_2(int a[], int n) {
	int leftEnd = findEndOfLeftSubseq(a, n);
	int rightStart = findStartOfRightSubseq(a, n);

	int minIdx = leftEnd+1;
	if(minIdx >= n) return;
	
	int maxIdx = rightStart-1;
	for(int i = leftEnd+1; i < rightStart; ++i) {
		if(a[i] < a[minIdx]) minIdx = i;
		if(a[i] > a[maxIdx]) maxIdx = i;
	}

	int leftIdx = shrinkLeft(a, minIdx, leftEnd);
	int rightIdx = shrinkRight(a, maxIdx, rightStart, n);
	
	cout << leftIdx << " to " << rightIdx << endl;
}


int main() {
	int n = 13;
	int a[] = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 17, 19};
	findUnsortedSeq_2(a, n);
	return 0;
}
