#include <cstdio>

bool g_bInvalidInput = false;

int FindGreatestSumOfSubArray(int* A, int length) {
	if(A == NULL || length <= 0){
		g_bInvalidInput = true;
		return 0;
	}

	int greatestSum = 0x80000000;
	int curSum = 0;
	
	for(int i = 0; i < length; ++i) {
		if(curSum <= 0)
			curSum = A[i];
		else
			curSum += A[i];
		if(curSum > greatestSum)
			greatestSum = curSum;
	}

	return greatestSum;
	
}

int main(){
	int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
	int result = FindGreatestSumOfSubArray(a, 8);
	int b[] = {-3, -2, -1};
	printf("%d\n",result);
	printf("%d\n",FindGreatestSumOfSubArray(b, 3));
	return 0;
}
