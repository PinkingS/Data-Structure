#include "queue.h"
#include <cstdlib>
#include <cstdio>

#define MinQueueSize (1)

struct QueueRecord {
	int Capacity;
	int Front;
	int Rear;
	int Size;
	int *Array;
};

Queue CreateQueue(int MaxElements) {
	if(MaxElements < MinQueueSize) {
		printf("Error : Queue Size is too small! \n");
		return NULL;
	}
	Queue Q;
	Q = (Queue)malloc(sizeof(struct QueueRecord));
	if(Q == NULL) {
		printf("Out of space ! \n");
	} 
	else {
		Q->Capacity = MaxElements;
		Q->Array = (int*)malloc(sizeof(int) * MaxElements);
		if(Q->Array == NULL) {
			printf("Out of space ! \n");
		} else {
			Q->Size = 0;
			Q->Front = 1;
			Q->Rear = 0;
		}
	}
	return Q;
}

int IsEmpty(Queue Q) {
	return Q->Size == 0;
}

int IsFull(Queue Q) {
	return Q->Size == Q->Capacity;
}

void DisposeQueue(Queue Q) {
	if(Q != NULL) {
		free(Q->Array);
		free(Q);
	}
}

static int Succ(int Value, Queue Q) {
	if( ++Value == Q->Capacity)
		Value = 0;
	return Value;
}

void Enqueue(int X, Queue Q) {
	if(IsFull(Q)) {
		printf("Queue is Full !\n");
	} else {
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X; 
	}
}

int Dequeue(Queue Q) {
	if(IsEmpty(Q))
		printf("Queue is Empty ! \n");
	else {
		Q->Size --;
		int tmp = Q->Array[Q->Front];
		Q->Front = Succ(Q->Front, Q);
		return tmp;
	}
}

void printQueue(Queue Q) {
	if(IsEmpty(Q)) 
		printf("Queue is Empty ! \n");
	else {
		for(int i = Q->Front; i != Q->Rear; ) {
			printf("%d\t", Q->Array[i]);
			i++;
			if(i == Q->Capacity)
				i = 0;			
		}
		printf("%d\n",Q->Array[Q->Rear]);
	}
}