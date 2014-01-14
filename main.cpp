#include <stdio.h>
//#include "list.h"
//#include "stack.h"
//#include "queue.h"
//#include "Tree.h"
#include <windows.h>    
#include <stdlib.h>
#include <iostream>

void InsertionSort(int A[], int N) {
	int i,j,tmp;
	for(i = 1; i < N; i++) {
		tmp = A[i];
		for(j = i; j > 0 && A[j-1] > tmp; j--)
				A[j] = A[j-1];
		A[j] = tmp;
	}
}

int main() {
/**testing search tree
 *
	SearchTree T;
	T = NULL;
	T = Insert(7, T);
	T = Insert(12, T);
	T = Insert(5, T);
	T = Insert(3, T);
	T = Insert(9, T);
	T = Insert(4, T);
	T = Insert(6, T);
	displayTree(T);
*/

/**testing Queue
 *
	Queue Q;
	Q = CreateQueue(3);
	printQueue(Q);
	Enqueue(5, Q);
	Enqueue(3, Q);
	Enqueue(1, Q);
	printQueue(Q);
	Enqueue(23, Q);
	printQueue(Q);
	printf("Dequeuing %d ...\n",Dequeue(Q));
	printf("Dequeuing %d ...\n",Dequeue(Q));
	printQueue(Q);
	Enqueue(23, Q);
	printQueue(Q);
	Enqueue(56, Q);
	printQueue(Q);
	printf("Dequeuing %d ...\n",Dequeue(Q));
	printQueue(Q);
*/

/* testing a problem in LeetCode about List
 *
 	List L1;
	Position p;
	L1 = CreateList();
	Insert(-7, L1, L1);
	List L2;
	L2 = CreateList();
	Insert(-10, L2, L2);

	Traverse(L1);
	Traverse(L2);
	L1 = mergeTwoLists(L1, L2);
	Traverse(L1);
*/

/*testing Stack
 *
	Stack S;
	S = CreateStack(4);
	TraverseStack(S);
	Push(11, S);
	TraverseStack(S);
	Push(22, S);
	TraverseStack(S);
	Push(33, S);
	TraverseStack(S);
	Push(44, S);
	TraverseStack(S);
	Push(55, S);
	TraverseStack(S);
	Pop(S);
	TraverseStack(S);
	DisposeStack(S);
*/
	int A[5] = {5, 4, 3, 2, 1};

	
	LARGE_INTEGER BegainTime ;    
    LARGE_INTEGER EndTime ;    
    LARGE_INTEGER Frequency ;    
    QueryPerformanceFrequency(&Frequency);    
    QueryPerformanceCounter(&BegainTime) ; 

	InsertionSort(A, 5);

	QueryPerformanceCounter(&EndTime);     
	std::cout << "运行时间（单位：s）：" <<(double)( EndTime.QuadPart - BegainTime.QuadPart )/ Frequency.QuadPart <<std::endl;    


	for(int i = 0; i < 5; i++)
		printf("%d\t",A[i]);
	printf("\n");
	system("pause");
	return 0;

}



