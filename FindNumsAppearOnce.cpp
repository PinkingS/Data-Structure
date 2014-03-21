#include <cstdio>

unsigned int FindFirstBitIs1(int num) {
	int index = 0;
	while(((num & 1) == 0) && (index < 8 * sizeof(int))) {
		index++;
		num = num >> 1;
	}
	return index;
}

bool IsBit1(int num, unsigned int index) {
	num = num >> index;
	return num & 1;
}

void FindNumsAppearOnce(int* numbers, int length, int* num1, int* num2) {
	if(numbers == NULL || length <= 1) {
		return;
	}

	int exOR = 0;
	for(int i = 0; i < length; i++) {
		exOR ^= numbers[i];
	}
printf("exOR : %d\n", exOR);
	unsigned int indexOf1 = FindFirstBitIs1(exOR);
printf("index of 1 : %d\n", indexOf1);
	*num1 = 0;
	*num2 = 0;
	for(int j = 0; j < length; j++) {
		if(IsBit1(numbers[j], indexOf1))
			*num1 ^= numbers[j];
		else
			*num2 ^= numbers[j];
	}
}

int main(){
	int a[] = {1, 5, 7, 7, 1, 4, 5, 6};
	int num1, num2;
	FindNumsAppearOnce(a, 8, &num1, &num2);
	printf("%d %d\n", num1, num2);
	return 0;
}
