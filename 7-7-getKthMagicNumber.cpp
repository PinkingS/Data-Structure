#include <iostream>

using namespace std;

bool isMagicNumber(int x) {
	while(x % 3 == 0)
		x /= 3;
	while(x % 5 == 0)
		x /= 5;
	while(x % 7 == 0)
		x /= 7;
	return x == 1;
}

int findKthMagicNumber(int k) {
	if(k <= 0)  return 0;

	int found = 0;
	int num = 0;
	while(found < k) {
		++num;
		if(isMagicNumber(num))
			++found;
	}
	return num;
}

int Min(int a, int b, int c) {
	int min = a < b ? a : b;
	min = min < c ? min : c;
	return min;
}

int findKthMagicNumber_2(int k) {
	if(k <= 0) return 0;

	int *magicNumbers = new int[k];
	magicNumbers[0] = 1;
	int nextMagicNumber = 1;

	int *p3 = magicNumbers;
	int *p5 = magicNumbers;
	int *p7 = magicNumbers;

	while(nextMagicNumber < k) {
		int min = Min(*p3 * 3, *p5 * 5, *p7 * 7);
		magicNumbers[nextMagicNumber] = min;
		
		while(*p3 * 3 <= magicNumbers[nextMagicNumber])
			++p3;
		while(*p5 * 5 <= magicNumbers[nextMagicNumber])
			++p5;
		while(*p7 * 7 <= magicNumbers[nextMagicNumber])
			++p7;
		
		++nextMagicNumber;
	}
	
	int magic = magicNumbers[nextMagicNumber-1];
	delete[] magicNumbers;

	return magic;
}


int main() {
	int k = 500;
	//cout << findKthMagicNumber(k) << endl;
	cout << findKthMagicNumber_2(k) << endl;
	return 0;
}
