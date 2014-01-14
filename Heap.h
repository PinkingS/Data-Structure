#ifndef _Heap_H

struct HeapStruct;
typedef struct HeapStruct *Heap;

Heap InitializeHeap(int MaxElements);
void DestroyHeap(Heap H);
void Insert(int X, Heap H);
int FindMin(Heap H);
int DeleteMin(Heap H);
int IsFull(Heap H);

#endif