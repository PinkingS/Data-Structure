#include "stack.h"
#include <cstdlib>
#include <cstdio>

#define EmptyTOS (-1)
#define MinStackSize (1)
struct StackRecord {
	int Capacity;
	int TopOfStack;
	int *Array;
};

Stack CreateStack(int MaxElements) {
	Stack S;
	if(MaxElements < MinStackSize) {
		printf("Error : Stack size is too small\n");
		return NULL;
	}
	S = (Stack)malloc(sizeof(struct StackRecord) );
	if(S == NULL) {
		printf("Error : Out of space !\n");
	}
	else {
		S->Array = (int *)malloc(sizeof(int) * MaxElements);
		if(S->Array == NULL)
			printf("Error : out of space\n");
		else {
			S->Capacity = MaxElements;
			S->TopOfStack = EmptyTOS;
		}
	}
	return S;
}

void DisposeStack(Stack S) {
	if(S != NULL) {
		free(S->Array);
		free(S);
	}
}

/*void MakeEmpty(Stack S) {
	if(S == NULL) {
		printf("Error : Must use CreateStack first ! \n");
	}
	else {
		while(!IsEmpty(S)) 
			Pop(S);
	}
}*/

int IsEmpty(Stack S) {
	return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S) {
	return S->TopOfStack == S->Capacity-1;
}

int Top(Stack S) {
	if(!IsEmpty(S))
		return S->Array[S->TopOfStack];
	printf("Notice : Empty Stack\n");
	return 0;
}

void Push(int X, Stack S) {
	if(IsFull(S)) {
		printf("Error : The Stack is Full\n");
	}
	else {
		S->Array[++S->TopOfStack] = X;
	}
}

void Pop(Stack S) {
	if(IsEmpty(S))
		printf("Error : Empty Stack\n");
	else {
		S->TopOfStack--;
	}
}

void TraverseStack(Stack S) {
	for(int i = 0; i <= S->TopOfStack; ++i) {
		printf("%d\t",S->Array[i]);
	}
	printf("\n");
}

int TopAndPop(Stack S) {
	if(!IsEmpty(S)) {
		return S->Array[S->TopOfStack--];
	}
	else {
		printf("Notice : Empty Stack\n");
		return 0;
	}
}
