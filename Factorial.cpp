#include <cstdio>

int factorial_Iterative(int N) {
	int res = 0;
	for(int i = 1; i <= N; ++i)
		res += i;
	return res;
}

int factorial_Recursive(int N) {
	return N <= 0 ? 0 : N + factorial_Recursive(N-1);
}

int main() {
	printf("iterative 1+2+..+5000 : %d\n",factorial_Iterative(5000));
	printf("recursive 1+2+..+5000 : %d\n",factorial_Recursive(5000));
	return 0;
}
