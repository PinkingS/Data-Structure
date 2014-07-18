#include <iostream>
#include <cstring>

using namespace std;

int countWays(int n) {
	if(n == 1)	return 1;
	if(n == 2) 	return 2;
	if(n == 3)	return 4;
	else return countWays(n-1) + countWays(n-2) + countWays(n-3);
}

int countWaysDP(int n) {
	int dp[n+1];
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i = 4; i <= n; ++i) {
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	return dp[n];
}

int main() {
	int n = 20;
	cout << countWays(n) << endl;
	cout << countWaysDP(n) << endl;
	return 0;
}
