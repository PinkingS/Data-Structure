#include <cstdio>

bool FindNumbersWithSum(int* numbers, int length, int sum, int* num1, int* num2) {
	bool found = false;
	if(numbers == NULL || num1 == NULL || num2 == NULL)
		return found;

	int start = 0;
	int end = length - 1;
	while(start < end) {
		long long curSum = numbers[start] + numbers[end];
//printf("%d+%d=%d\n",numbers[start], numbers[end], curSum);
		if(curSum == sum){
			*num1 = numbers[start];
			*num2 = numbers[end];
			found = true;
			break;
		}
		else if(curSum > sum) {
			end--;
		}
		else
			start++;
	}
	return found;
}

int main() {
	int a[] = {1, 3, 4, 5, 7, 9, 10};
	int sum = 15;
	int num1, num2;
	if(FindNumbersWithSum(a, 7, sum, &num1, &num2))
		printf("%d + %d = %d\n", num1, num2, sum);
	else
		printf("Not Found ! \n");
	return 0;
}
