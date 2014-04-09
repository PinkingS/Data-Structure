#include <cstdio>

long long Count1InInt(long long n){
	long long count = 0;
	while(n) {
		count += (n % 10 == 1) ? 1 : 0;
		n /= 10;
	}
	return count;
}

long long Count1From1ToN( long long n) {
	long long count = 0;
	for(long long i = 1; i <= n; ++i)
		count += Count1InInt(i);
	return count;
}

long long Count1From1ToN2(long long n) {
	long long count = 0;
	long long factor = 1;
	long long lowerNum = 0;
	long long curNum = 0;
	long long higherNum = 0;
	while(n / factor) {
		lowerNum = n % factor;
		curNum = (n / factor) % 10;
		higherNum = n / (factor * 10);
		switch(curNum) {
			case 0:
				count += higherNum * factor;
				break;
			case 1:
				count += higherNum * factor + lowerNum + 1;
				break;
			default:
				count += (higherNum + 1) * factor;
				break;
		}
		factor *= 10;
	}
	return count;
}

int main() {
	long long num = 23345482;
	printf("number of 1s : %lld\n",Count1From1ToN(num));
	printf("number of 1s : %lld\n",Count1From1ToN2(num));
	return 0;
}
