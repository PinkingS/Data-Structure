#include <iostream>
#include <limits.h>

using namespace std;

// caution : if n < 0, this is not working !!!!!!!
int count1s(int n) {
	int cnt = 0;
	while(n > 0) {
		cnt += (n&1);
		n >>= 1; 
	}
	return cnt;
}

int countOnes(int n) {
	int cnt = 0;
	for(int i = 0; i < 32; ++i) {
		cnt += n&1;
		n >>= 1;
	}
	return cnt;
}

// solution 1 : exhaustively search
int getNext(int num) {
	int i = num+1;
	int cnt = countOnes(num);
	while(i <= INT_MAX) {
		if(countOnes(i) == cnt)
			return i;
		++i;
	}
}

int getPrev(int num) {
	int cnt = countOnes(num);
	int i = num-1;
	while(i >= INT_MIN) {
		if(countOnes(i) == cnt)
			return i;
		--i;
	}
}

// solution 2 : use bit operation
int getNext_2(int num) {
	int n = num;
	int c0 = 0, c1 = 0;
	while(((n&1) == 0) && (n != 0)) {
		++c0;
		n >>= 1;
	}
	while(((n&1) == 1) && (n != 0)) {
		++c1;
		n >>= 1;
	}
	
	if(c0 + c1 == 31)
		return -1;
	
	int p = c1 + c0;
	num |= (1 << p);
	num &= ~((1 << p) - 1);
	num |= (1 << (c1-1)) - 1;
	return num;
}

int getPrev_2(int num) {
	int n = num;
	int c0 = 0, c1 = 0;
	while((n&1) == 1 && n != 0) {
		++c1;
		n >>= 1;
	}
	while((n&1) == 0 && n != 0) {
		++c0;
		n >>= 1;
	}

	if(c1 + c0 == 32)
		return -1;
	
	int p = c1 + c0;
	num &= ((~0) << (p+1));
	int mask = (1<<(c1+1) - 1);
	num |= mask << (c0-1);
	return num;
}


int main() {
	int num = 13948;
	cout << getPrev(num) << " " << getNext(num) << endl;
	cout << getPrev_2(num) << " " << getNext_2(num) << endl;
	
	return 0;
}
