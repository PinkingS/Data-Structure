#include <cstdio>

void swap(int &a, int &b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

bool isEven(int n) {
	return (n & 1) == 0;
}

bool isPositiveNum(int n) {
	return (n >= 0);
}

bool devideBy3(int n) {
	return (n % 3) == 0;
}

void Reorder(int A[], int N, bool (*func)(int)) {
	if(N <= 1)
		return;
	int i = 0, j = N-1;
	while(i < j) {
		while(i < j && func(A[j])) --j;
		if(i < j)
			swap(A[i], A[j]);
		while(i < j && !func(A[i])) ++i;
		if(i < j)
			swap(A[i], A[j]);
	}
}

void ReorderOddEven(int A[], int N) {
	Reorder(A, N, devideBy3);
}

int main() {
	int length = 5;
	int a[] = {4, 6, 2, 9, -7};
	ReorderOddEven(a, length);
	for(int i = 0; i < length; ++i)
		printf("%d\t",a[i]);
	printf("\n");
	return 0;
}
