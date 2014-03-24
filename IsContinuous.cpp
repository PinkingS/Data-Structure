#include <cstdio>
#include <cstdlib> //using qsort

/***
用 法： void qsort(void *base,int nelem,int width,int (*fcmp)(const void *,const void *));
参数： 
1 待排序数组首地址
2 数组中待排序元素数量
3 各元素的占用空间大小
4 指向函数的指针，用于确定排序的顺序

其中comp函数应写为：

int comp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

上面是由小到大排序，return *(int *)b-*(int *)a; 为由大到小排序。
**/

int compare(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

bool IsContinuous(int* numbers, int length) {
	if(numbers == NULL || length < 1) 
		return false;
	
	qsort(numbers, length, sizeof(int), compare);

	int numberOfZero = 0;
	int numberOfGap = 0;

	for(int i = 0; i < length; ++i) {
		if(numbers[i] == 0) {
			numberOfZero++;
		}
	}

	int small = numberOfZero;
	int big = small+1;

	while(big < length) {
		if(numbers[small] == numbers[big])
			return false;
		numberOfGap += numbers[big] - numbers[small] - 1;
		small = big;
		big++;
	}
	
	return numberOfGap > numberOfZero ? false : true;
}

int main() {
	int a[] = {7, 8, 3, 0, 0};
	printf("%d\n",IsContinuous(a, 5));
	return 0;
}
