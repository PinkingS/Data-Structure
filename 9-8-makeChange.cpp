#include <iostream>

using namespace std;

int sumN(int sum, int c, int n) {
	int ways = 0;
	if(sum <= n) {
		if(sum == n) return 1;
		if(c >= 25)
			ways += sumN(sum+25, 25, n);
		if(c >= 10)
			ways += sumN(sum+10, 10, n);
		if(c >= 5)
			ways += sumN(sum+5, 5, n);
		if(c >= 1)
			ways += sumN(sum+1, 1, n);
	}
	return ways;
}

int makeChange(int n, int coin) {
	int nextCoin = 0;
	switch(coin) {
		case 25 :
			nextCoin = 10;
			break;
		case 10 :
			nextCoin = 5;
			break;
		case 5 :
			nextCoin = 1;
			break;
		case 1 : 
			return 1;
	}
	int ways = 0;
	for(int i = 0; i*coin <= n; ++i)
		ways += makeChange(n-i*coin, nextCoin);
	return ways;
}

int main() {
	int n = 10;
	cout << sumN(0, 25, n) << endl;
	cout << makeChange(n, 25) << endl;
	return 0;
}
