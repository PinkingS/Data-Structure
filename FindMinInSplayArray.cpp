#include <cstdio>
#include <cstdlib>

int MinInOrder(int A[], int low, int high) {
	int res = A[low];
	for(int i = low+1; i <= high; ++i) {
		if(A[i] < res)
			res = A[i];
	}
	return res;
}

int Min(int A[], int N) {
	if(A == NULL || N <= 0) {
		printf("Invalid parameter");
		exit(-1);
	}
	
	if(A[0] < A[N-1])
		return A[0];

	int i = 0, j = N-1;
	while(i < j && i != (j-1)) {
		int mid = (i + j)/2;
		
		if(A[i] == A[mid] && A[mid] == A[j])
			return MinInOrder(A, i, j);
	
		if(A[mid] < A[i])
			j = mid;
		else if(A[mid] > A[j])
			i = mid;
	}
	return A[j];
}



int main() {
	int a[5] = {4, 5, 1, 2, 3};
	int b[5] = {1, 2, 3, 4, 5};
	int c[5] = {1, 0, 1, 1, 1};
	int d[5] = {3, 4, 1, 2, 3};
	int res = Min(d, 5);
	printf("desired result : 1  actual result : %d\n", res);
	return 0;
}
