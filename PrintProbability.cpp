#include <cstdio>
#include <math.h>

int g_bMaxValue = 6;

void Probability(int original, int current, int sum, int* pProb) {
	if(current == 1)
		pProb[sum-original]++;
	else {
		for(int i = 1; i <= g_bMaxValue; ++i) {
			Probability(original, current-1, sum+i, pProb);
		}
	}
}


void PrintProbability(int number) {
	if(number < 1)
		return;

	int maxSum = number * g_bMaxValue;
	int* pProb = new int[maxSum - number + 1];
	for(int i = number; i <= maxSum; ++i)
		pProb[i - number] = 0;

	for(int j = 1; j <= g_bMaxValue; ++j)
		Probability(number, number, j, pProb);

	int total = pow((double)g_bMaxValue, number);
	for(int i = number; i <= maxSum; ++i) {
		double ratio = (double)pProb[i-number] / total;
		printf("%d : %e\n",i, ratio);
	}

	delete[] pProb;
}

int main() {
	int number = 3;
	PrintProbability(number);
	return 0;
}
