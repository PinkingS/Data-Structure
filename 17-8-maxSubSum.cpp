#include <iostream>

using namespace std;

int maxSubSum(int a[], int n) {
	int maxSum = 0;
	int sum = 0;
	for(int i = 0; i < n; ++i) {
		sum += a[i];
		if(sum < 0)
			sum = 0;
		if(sum > maxSum)
			maxSum = sum;
	}
	return maxSum;
}

int main() {
	int a[] = {2, 3, -8, -1, 2, 4, -2, 3};
	cout << maxSubSum(a, 8) << endl;
	int b[] = {-2, -5, -8};
	cout << maxSubSum(b, 3) << endl;
	return 0;
}
