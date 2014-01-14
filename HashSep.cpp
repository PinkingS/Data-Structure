#include "HashSep.h"
#include <cstdio>
#include <cstdlib>

#define MinTableSize (1)

struct ListNode {
	int Element;
	Position Next;
};

typedef Position List;

struct HashTbl {
	int TableSize;
	List *TheLists;
};

HashTable InitializeTable(int TableSize) {
	HashTable H;

	if(TableSize < MinTableSize) {
		printf("Table Size is too small !\n");
		return NULL;
	}

	H = (HashTable)malloc(sizeof(struct HashTbl));
	if(H == NULL) {
		printf("Out of Space ! \n");
		return NULL;
	}

	H->TableSize = TableSize;

	H->TheLists = (List *)malloc(sizeof(List) * TableSize);
	if(H->TheLists == NULL) {
		printf("out of space ! \n");
		return NULL;
	}

	for(int i = 0; i < TableSize; i++) {
		H->TheLists[i] = (List)malloc(sizeof(struct ListNode));
		if(H->TheLists[i] == NULL) {
			printf("out of space ! \n");
			return NULL;
		}
		else
			H->TheLists[i]->Next = NULL;
	}

	return H;
}

void DestroyTable(HashTable H) {
	if(H == NULL)
		return ;
	for(int i = 0; i < H->TableSize; i++) {
		free(H->TheLists[i]);
	}
	free(H->TheLists);
	free(H);
}

static int Hash( int key, int TableSize) {
	return key % TableSize;
}

Position Find(int Key, HashTable H) {
	Position P;
	List L;
	
	L = H->TheLists[Hash(Key, H->TableSize)];
	P = L->Next;
	while(P != NULL && P->Element != Key)
		P = P->Next;
	return P;
}

void Insert(int Key, HashTable H) {
	Position P;
	Position NewCell;
	List L;

	P = Find(Key, H);
	
	//Key not found, need to be inserted
	if(P == NULL) {
		NewCell = (ListNode *)malloc(sizeof(struct ListNode));
		if(NewCell == NULL) {
			printf("out of space ! Insertion failed !\n");
			return ;
		}
		NewCell->Element = Key;
		L = H->TheLists[Hash(Key, H->TableSize)];
		NewCell->Next = L->Next;
		L->Next = NewCell;
	}
}