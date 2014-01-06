#include "list.h"
#include <stdio.h>
#include <stdlib.h>


int IsEmpty(List L) {
	return L->Next == NULL;
}

int IsLast(Position P, List L) {
	return P->Next == NULL;
}

Position Header(List L) {
	if(L->Next != NULL)
		return L->Next;
	else
		return NULL;
}

Position Find(int X, List L) {
	Position P;
	P = L->Next;
	while(P != NULL && P->Element != X) {
		P = P->Next;
	}
	return P;
}

List CreateList() {
	List L;
	L = (List)malloc(sizeof(struct Node));
	if(L == NULL) {
		printf("Error : Out of space !!\n");
	}
	L->Next = NULL;
	MakeEmpty(L);
	return L;
}

void MakeEmpty(List L) {
	if(L == NULL) {
		printf("Error : Must use CreateList First\n");
	}	
	else {
		Position Tmp;
		while( !IsEmpty(L) ) {
			Tmp = L;
			L = L->Next;
			free(Tmp);
		}
	}
}

void Delete(int X, List L) {
	Position P, Tmp;
	P = FindPrevious(X, L);
	if(!IsLast(P, L)) {
		Tmp = P->Next;
		P->Next = P->Next->Next;
		free(Tmp);
	}
}

Position FindPrevious(int X, List L) {
	Position P;
	P = L->Next;
	while( P->Next != NULL && P->Next->Element != X ) {
		P = P->Next;
	}
	return P;
}

void Insert(int X, Position P, List L) {
	Position TmpCell;
	TmpCell = (Position)malloc(sizeof(struct Node));
	if(TmpCell == NULL) {
		printf("Error : Out of space !! \n");
	}
	else {
		TmpCell->Element = X;
		TmpCell->Next = P->Next;
		P->Next = TmpCell;
	}
}

void DeleteList(List L) {
	Position P, Tmp;
	P = L->Next;
	L->Next = NULL;
	while(P != NULL) {
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}

void Traverse(List L) {
	Position P;
	P = L->Next;
	while(P != NULL) {
		printf("%d\t",P->Element);
		P = P->Next;
	}
	printf("\n");
}

    List mergeTwoLists(List l1, List l2) {
		l1 = l1->Next;
		l2 = l2->Next;
		if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;

        List tmp;
        if(l2->Element < l1->Element) { //make the list with smaller start the l1 list
            tmp = l1;
            l1 = l2;
            l2 = tmp;
        }
        List resList = l1;
        
        Node *insertNode;
        while(l1->Next != NULL || l2->Next != NULL) {
            if(l2->Element <= l1->Element) {
                insertNode = l2;
                insertNode->Next = l1->Next;
                l1->Next = insertNode;
                l1 = l1->Next;
                if(l2->Next != NULL)
                    l2 = l2->Next;
                else
                    return resList;
            }
            else {
                if(l1->Next != NULL)
                    l1 = l1->Next;
                else {
                    l1->Next = l2;
                    return resList;
                }
            }
        }
            
        return resList;
        
    }