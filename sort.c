#include <stdio.h>
#include <stdlib.h>

#define LeftChild(i) (2*i+1)
#define cutoff (3)

void InsertionSort(int A[], int N){
	int i,j,tmp;
	for(i=1; i<N; i++){
		tmp = A[i];
		for(j = i; j > 0 && A[j-1] > tmp; j--)
			A[j] = A[j-1];
		A[j] = tmp;
	}
}

void ShellSort(int A[], int N){
	int inc,i,j,tmp;
	for(inc = N/2; inc > 0; inc /= 2){
		for(i = inc; i < N; i++){
			tmp = A[i];
			for(j = i; j >= inc; j -= inc){
				if(A[j-inc] > tmp)
					A[j] = A[j-inc];
				else
					break;
			}
			A[j] = tmp;
		}
	}
}

void PercDown(int A[], int i, int N){
	int tmp,Child;
	for(tmp = A[i]; LeftChild(i) < N; i = Child){
		Child = LeftChild(i);
		if(Child != N-1 && A[Child] < A[Child+1])
			Child++;
		if(tmp < A[Child])
			A[i] = A[Child];
		else
			break;
	}
	A[i] = tmp;
}

void HeapSort(int A[], int N){
	int i,tmp;
	int j;

	for(i = N/2; i >= 0; i--) { //build heap
		PercDown(A, i, N);
	}
	for(i = 0; i < N; i++)
			printf("%d ",A[i]);
	printf("\n");
	for(i = N-1; i > 0; i--){
		tmp = A[0];
		A[0] = A[i];
		A[i] = tmp;
		PercDown(A, 0, i);
		for(j = 0; j < N; j++)
				printf("%d  ",A[j]);
		printf("\n");
	}

}

void Merge(int A[], int TmpArray[], int LPos, int RPos, int REnd){
	int LEnd,TmpPos,NewElements;
	int i;

	LEnd = RPos - 1;
	TmpPos = LPos;
	NewElements = REnd - LPos + 1;
	
	while(LPos <= LEnd && RPos <= REnd){
		if(A[LPos] < A[RPos])
			TmpArray[TmpPos++] = A[LPos++];
		else
			TmpArray[TmpPos++] = A[RPos++];
	}
	while(LPos <= LEnd)
		TmpArray[TmpPos++] = A[LPos++];
	while(RPos <= REnd)
		TmpArray[TmpPos++] = A[RPos++];

	for(i = 0; i < NewElements; i++, REnd--)
		A[REnd] = TmpArray[REnd];
}

void MSort(int A[], int TmpArray[], int left, int right){
	int center;
	if(left < right){
		center = (left + right) / 2;
		MSort(A, TmpArray, left, center);
		MSort(A, TmpArray, center+1, right);
		Merge(A, TmpArray, left, center+1, right);
	}
}

void MergeSort(int A[], int N){
	int i;
	int *TmpArray;
	
	TmpArray = malloc(sizeof(int) * N);
	if(TmpArray != NULL){
		MSort(A, TmpArray, 0, N-1);
		free(TmpArray);		
	}
	else
		printf("out of space! \n");
}

void Swap(int *a, int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int Median3(int A[], int left, int right){
	int center = (left + right) / 2;
	if(A[left] > A[center])
		Swap(&A[left], &A[center]);
	if(A[left] > A[right])
		Swap(&A[left], &A[right]);
	if(A[center] > A[right])
		Swap(&A[center], &A[right]);
	Swap(&A[center], &A[right-1]);
	return A[right-1];
}

void QSort(int A[], int left, int right){
	int i,j;
	int Pivot;
	if(right - left >= cutoff){
		Pivot = Median3(A, left, right);
		i = left;
		j = right - 1;
		for(;;){
			while(A[++i] < Pivot){}
			while(A[--j] > Pivot){}
			if(i < j)
				Swap(&A[i], &A[j]);
			else
				break;
		}
		Swap(&A[i], &A[right-1]);
		QSort(A, left, i-1);
		QSort(A, i+1, right);
	}
	else
		InsertionSort(A+left, right-left+1);
}

void QuickSort(int A[], int N){
	QSort(A, 0, N-1);		
}

int main(){
	int A[8] = {8, 7, 6, 5, 4, 3, 2, 1};
	Swap(&A[0], &A[7]);
	printf("%d\t%d\n", A[0], A[7]);
	int i;
	QuickSort(A, 8);
	for(i = 0; i < 8; i++)
		printf("%d\t",A[i]);
	printf("\n");
	return 0;
}
