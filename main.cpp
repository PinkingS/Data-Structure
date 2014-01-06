#include <stdio.h>
//#include "list.h"
//#include "stack.h"
#include "queue.h"
#include <stdlib.h>

struct Tmp{
	int e;
	int a;
};

int main() {
	//List L1;
	//Tmp nn;
//	Node nn;

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


	/*	Position p;
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

/*	Stack S;
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
	system("pause");
	return 0;

}

