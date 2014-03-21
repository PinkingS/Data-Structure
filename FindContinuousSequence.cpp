#include <cstdio>

void printSequence(int start, int end) {
	for(int i = start; i <= end; i++) {
		printf("%d ", i);
	}
	printf("\n");
}

void FindContinuousSequence(int sum) {
	if(sum < 3)
		return;

	int small = 1;
	int big = 2;
	int middle = (1+sum) / 2;
	int curSum = small + big;
	while(small < middle) {
		if(curSum == sum)
			printSequence(small, big);
		while(curSum > sum && small < middle) {
			curSum -= small;
			small++;

			if(curSum == sum)
				printSequence(small, big);
		}
		big++;
		curSum += big;
	}
}

int main() {
	int sum = 15;
	FindContinuousSequence(sum);
	return 0;
}
