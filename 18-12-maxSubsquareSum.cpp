#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_N = 20;
int p[MAX_N][MAX_N], A[MAX_N][MAX_N];

void preCompute(int n) {
	for(int i = 0; i <= n; ++i)
		p[0][i] = p[i][0] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + A[i][j];
}

int maxSum(int n) {
	int maxSum = 1 << 31;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			int cur_sum = 0;
			for(int k = 1; k <= n; ++k) {
				int val = p[j][k]-p[j][k-1] - p[i-1][k] + p[i-1][k-1];
				if(cur_sum <= 0) 
					cur_sum = val;
				else
					cur_sum += val;

				if(cur_sum > maxSum)
					maxSum = cur_sum;
			}
		}
	return maxSum;
}

int main() {
	freopen("18.12.in", "r", stdin);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> A[i][j];
	preCompute(n);
	cout << maxSum(n) << endl;
	fclose(stdin);
	return 0;
}
