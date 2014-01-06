#ifndef _Stack_H
struct StackRecord;
typedef struct StackRecord *Stack;

Stack CreateStack(int MaxElements);
int IsEmpty(Stack S);
int IsFull(Stack S);
void MakeEmpty(Stack S);
void Push(int X, Stack S);
int Top(Stack S);
void Pop(Stack S);
void TraverseStack(Stack S);
int TopAndPop(Stack S);
void DisposeStack(Stack S);

#endif