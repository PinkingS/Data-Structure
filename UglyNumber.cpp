#include <cstdio>

int Min(int a, int b, int c) {
	int min = (a < b) ? a : b;
	min = (min < c) ? min : c;
	return min;
}

int UglyNumber(int index) {
	if(index <= 0)
		return 0;
	int *uglyNum = new int[index];
	uglyNum[0] = 1;
	int nextIndex = 1;

	int *ugly2 = uglyNum;
	int *ugly3 = uglyNum;
	int *ugly5 = uglyNum;

	while(nextIndex < index){
		int min = Min(*ugly2*2, *ugly3*3, *ugly5*5);
		uglyNum[nextIndex] = min;

		while(*ugly2*2 <= uglyNum[nextIndex])
			ugly2++;
		while(*ugly3*3 <= uglyNum[nextIndex])
			ugly3++;
		while(*ugly5*5 <= uglyNum[nextIndex])
			ugly5++;

		++nextIndex;
	}
	return uglyNum[nextIndex-1];
}

int main(){
	int index = 1500;
	printf("%d\n",UglyNumber(index));
	return 0;
}
