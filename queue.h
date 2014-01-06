#ifndef _Queue_H

struct QueueRecord;
typedef struct QueueRecord *Queue;

Queue CreateQueue(int MaxElements);
int IsEmpty(Queue Q);
int IsFull(Queue Q);
void DisposeQueue(Queue Q);
void Enqueue(int X, Queue Q);
int Dequeue(Queue Q);
void printQueue(Queue Q);

#endif