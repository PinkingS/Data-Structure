#include <cstdio>

int InversePairsCore(int* data, int* copy, int start, int end);

int InversePairs(int* data, int length) {
	if(data == NULL || length <= 0)
		return 0;
	int* copy = new int[length];
	for(int i = 0; i < length; ++i)
		copy[i] = data[i];

	int count = InversePairsCore(data, copy, 0, length-1);
		
	delete[] copy;
	return count;
}

int InversePairsCore(int* data, int* copy, int start, int end) {
	if(start == end){
		copy[start] = data[start];
		return 0;
	}

	int length = (end - start) / 2;

	int leftCnt = InversePairsCore(data, copy, start, start+length);
	int rightCnt = InversePairsCore(data, copy, start+length+1, end);

	int i = start+length;
	int j = end;
	int m = end;
	int count = 0;

	while(i >= start && j >= start+length+1) {
		if(copy[i] > copy[j]) {
			copy[m--] = data[i--];
			count += j - start - length;
		}
		else {
			copy[m--] = data[j--];
		}
	}

	while(i>=start)
		copy[m--] = data[i--];
	while(j>=start+length+1)
		copy[m--] = data[j--];

//printf("from %d to %d : ", start, end);
//for(int k = start; k <= end; ++k )
//	printf("%d\t",copy[k]);
//printf("\n");


	return leftCnt + rightCnt + count;
}	

int main(){
	int a[] = {1, 2, 3, 7, 13, 8, 5, 10, 6, 9, 4};
	int length = 11;
	int cnt = InversePairs(a, length);
	printf("%d\n",cnt);
	for(int i = 0; i < length; ++i)
		printf("%d\t",a[i]);
	printf("\n");
	return 0;
}
