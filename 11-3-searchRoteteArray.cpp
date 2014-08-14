#include <iostream>

using namespace std;

int search(int a[], int low, int high, int x) {
	while(low <= high) {	
		int mid = low + (high - low)/2;
		if(a[mid] == x)
			return mid;
		if(a[mid] >= a[low]) {
			if(x < a[mid] && x >= a[low])
				high = mid-1;
			else
				low = mid+1;  
		}
		else {
			if(x > a[mid] && x <= a[high])
				low = mid+1;
			else
				high = mid-1;
		}
	}
	return -1;
}

int main() {
	int a[] = {7, 8, 9, 11, 12, 15, 16, 1, 2, 3, 4, 5};
	int index = search(a, 0, 11, 5);
	cout << index << endl;
	return 0;
}
