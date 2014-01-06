#ifndef _List_H

struct Node {
	int Element;
	Node* Next;
};

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List CreateList();
void MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(int X, List L);
void Delete(int X, List L);
Position FindPrevious(int X, List L);
void Insert(int X, Position P, List L);
void DeleteList(List L);
Position Header(List L);
//Position First(List L);
//Position Advance(Position P);
void Traverse(List L);
List mergeTwoLists(List l1, List l2);

#endif