#include <cstring>
#include <cstdio>

bool Increment(char *number) {
	bool isOverFlow = false;
	int length = strlen(number);
	int takeOver = 0;

	for(int i = (length-1); i >= 0; --i) {
		int digit = number[i] - '0' + takeOver;
		if(i == (length-1))
			++digit;
		if(digit >= 10) {
			if(i == 0)
				isOverFlow = true;
			else {
				number[i] = '0';
				takeOver = 1;
			} 
		}
		else {
			++number[i]; 
			break;
		}		
	}
	return isOverFlow;
}

void PrintNumber(char *number) {
	int length = strlen(number);
	bool isBeginning0 = true;
	for(int i = 0; i < length; ++i) {
		if(isBeginning0 && number[i] != '0')
			isBeginning0 = false;
		if(!isBeginning0)
			printf("%c",number[i]);
	}
	printf("\t");
}

void PrintToMaxOfNDigit(int N) {
	if(N <= 0)
		return;
	char *number = new char[N+1];
	memset(number, '0', N);
	number[N] = '\0';
	
	while(!Increment(number))
		PrintNumber(number);

	delete []number;
}

void PrintToMaxOfDigitRecursively(char *number, int length, int index) {
	if(index == length -1) {
		PrintNumber(number);
		return;
	}
	for(int i = 0; i < 10; ++i) {
		number[index+1] = '0' + i;
		PrintToMaxOfDigitRecursively(number, length, index+1);
	}
}
 
void PrintToMaxOfNDigit(int N) {
	if(N <= 0)
		return;
	char *number = new char[N+1];
	number[N] = '\0';
	
	for(int i = 0; i < 10; ++i) {
		number[0] = '0' + i;
		PrintToMaxOfDigitRecursively(number, N, 0);
	}

	delete []number;
}

int main() {
	PrintToMaxOfNDigit(-2);
	PrintToMaxOfNDigit(0);
	PrintToMaxOfNDigit2(2);
	return 0;
}
