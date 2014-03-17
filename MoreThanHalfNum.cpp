#include <cstdio>
#include <iostream>
using namespace std;

bool g_bInputValid = false;

void swap(int &a, int &b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int Partition(int* numbers, int low, int high) {
	int pivot = numbers[low];
	int i = low, j = high;
	while( i < j ) {
		while(i < j && numbers[j] > pivot) --j;
		if(i < j)
			swap(numbers[i], numbers[j]);
		while(i < j && numbers[i] <= pivot) ++i;
		if(i < j)
			swap(numbers[i], numbers[j]);
	}
	return i;
}

bool CheckMoreThanHalf(int* numbers, int length, int num) {
	int times = 0;
	for(int i = 0; i < length; ++i) {
		if(numbers[i] == num)
			++times;
	}
	
	bool isMoreThanHalf = true;
	if(times * 2 <= length) {
		isMoreThanHalf = false;
		g_bInputValid = true;
	}
	return isMoreThanHalf;
}

int MoreThanHalfNum(int* numbers, int length) {
	if(numbers == NULL || length <= 0 ) {
		g_bInputValid = true;
		return 0;
	}

	int start = 0;
	int end = length-1;
	int middle = length >> 1;
	int index = Partition(numbers, start, end);
	while(index != middle) {
//cout << index << endl;
		if(index > middle) {
			end = index-1;
			index = Partition(numbers, start, end);
		} else {
			start = index + 1;
			index = Partition(numbers, start, end);
		}
	}
	int result = numbers[middle];
	if(!CheckMoreThanHalf(numbers, length, result))
		return 0;

	return result;
}

int MoreThanHalfNum2(int* numbers, int length) {
	if(numbers == NULL || length <= 0 ) {
		g_bInputValid = true;
		return 0;
	}
	
	int result = numbers[0];
	int time = 1;
	for(int i = 1; i < length; ++i) {
		if(time == 0) {
			result = numbers[i];
			time = 1;
		}
		else if(result = numbers[i]) {
			time++;
		} else {
			time--;
		}
	}

	if(!CheckMoreThanHalf(numbers, length, result))
		return 0;

 	return result;
}

int main() {
	int a[] = {2, 4, 8, 5, 4, 3, 3, 3, 3, 3, 3};
	printf("%d\n", MoreThanHalfNum2(a, 11));
	int b[] = {2};
	printf("%d\n",MoreThanHalfNum2(b, 1));
	return 0;
}
