#include <iostream>
#include <cmath>

using namespace std;

int magicSlow(int a[], int n) {
	for(int i = 0; i < n; ++i)
		if(a[i] == i)
			return i;
	return -1;
}

int magicFast(int a[], int start, int end) {
	if(end < start) return -1;
	int mid = (start + end) / 2;
	if(a[mid] == mid) return mid;
	if(a[mid] < mid)
		return magicFast(a, mid+1, end);
	else
		return magicFast(a, start, mid-1);
}


// for arrays which have duplicate numbers...
int magicDup(int a[], int start, int end) {
	if(start > end) return -1;
	int midIndex = (start + end) / 2;
	int midValue = a[midIndex];
	if(midIndex == midValue)
		return midIndex;

	int leftIndex = min(midIndex-1, midValue);
	int left = magicDup(a, start, leftIndex);
	if(left >= 0)
		return left;

	int rightIndex = max(midIndex+1, midValue);
	int right = magicDup(a, rightIndex, end);

	return right;
}

int main() {
	int a[] = {-10, -5, -2, 3, 4, 8, 13, 34};
	cout << magicFast(a, 0, 7) << endl;
	int b[] = {-10, -5, -2, 4, 8, 9, 10, 11};
	cout << magicFast(b, 0, 7) << endl;

	int c[] = {-10, -5, 2, 2, 2, 3, 4, 7, 9, 12, 13};
	cout << magicDup(c, 0, 10) << endl;

	return 0;
}
