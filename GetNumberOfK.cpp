#include <cstdio>

int FindFirstOfK(int* data, int length, int k, int start, int end) {
	if(start > end)
		return -1;
	int middle = (start + end) / 2;
	int middleData = data[middle];

	if(middleData == k) {
		if((middle > 0 && data[middle-1] != k) || middle == 0)
			return middle;
		else
			end = middle - 1;
	} 
	else if(middleData > k) 
		end = middle - 1;
	else
		start = middle + 1;
	
	return FindFirstOfK(data, length, k, start, end);
}

int FindLastOfK(int* data, int length, int k, int start, int end) {
	if(start > end)
		return -1;
	int middle = (start + end) / 2;
	int middleData = data[middle];

	if(middleData == k) {
		if((middleData < length-1 && data[middle+1] != k) || middle == length-1)
			return middle;
		else
			start = middle + 1;
	}
	else if(middleData > k)
		end = middle -1;
	else
		start = middle + 1;

	return FindLastOfK(data, length, k, start, end);
}


int GetNumberOfK(int* data, int length, int k) {
	int number = 0;
	if(data != NULL && length > 0) {
		int firstK = FindFirstOfK(data, length, k, 0, length-1);
		int lastK = FindLastOfK(data, length, k, 0, length-1);
printf("%d\n",firstK);
printf("%d\n",lastK);
		if(firstK > -1 && lastK > -1)
			number = lastK - firstK + 1;
	}
	return number;
}

int main(){
	int a[] = {1, 2, 3, 3, 3, 3, 4, 5};
	int count = GetNumberOfK(a, 8, 3);
	printf("%d\n",count);
	return 0;
}
