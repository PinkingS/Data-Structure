#include "Tree.h"
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;


struct TreeNode {
	int Element;
	SearchTree Left;
	SearchTree Right;
};

SearchTree CreateTree() {
	SearchTree T;
	T = (SearchTree)malloc(sizeof(struct TreeNode));
	if(T == NULL) {
		printf("out of space !\n");
		return NULL;
	}
	else {
		T->Left = T->Right = NULL;
		MakeEmpty(T);
		return T;
	}
}

SearchTree MakeEmpty(SearchTree T) {
	if(T != NULL) {
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(int X, SearchTree T) {
	if(T == NULL)
		return NULL;
	if(X > T->Element)
		return Find(X, T->Right);
	else
		if(X < T->Element)
			return Find(X, T->Left);
		else
			return T;
}

Position FindMin(SearchTree T) {
	if(T == NULL)
		return NULL;
	if(T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}

Position FindMax(SearchTree T) {
	if(T != NULL) {
		while(T->Right != NULL)
			T = T->Right;
	}
	return T;
}

SearchTree Insert(int X, SearchTree T) {
	if(T == NULL) {
		T = (SearchTree)malloc(sizeof(struct TreeNode));
		if(T == NULL) {
			printf("out of space !\n");
			return NULL;
		}
		else {
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else {
		if(X < T->Element)
			T->Left = Insert(X, T->Left);
		else if(X > T->Element)
			T->Right = Insert(X, T->Right);
	}

	return T;
}

SearchTree Delete(int X, SearchTree T) {
	Position TmpCell;

	if(T == NULL)
		printf("Not Found !\n");
	else if(X < T->Element) {
		T->Left = Delete(X, T->Left);
	}
	else if(X > T->Element) {
		T->Right = Delete(X, T->Right);
	}
	//find the element to be deleted
	else if(T->Left && T->Right) {
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else {
		TmpCell = T;
		if(T->Left == NULL)
			T = T->Left;
		if(T->Right == NULL)
			T = T->Right;
		free(TmpCell);
	}

	return T;
}

void displayTree(SearchTree T) {
	if(T == NULL) 
		return ;
	queue<SearchTree> nodeQueue;
	nodeQueue.push(T);
	nodeQueue.push(NULL);
	while(nodeQueue.size()) {
		TreeNode * pNode = nodeQueue.front();
		nodeQueue.pop();
		if(pNode) {
			if(pNode->Left)
				nodeQueue.push(pNode->Left);
			if(pNode->Right)
				nodeQueue.push(pNode->Right);
			cout << pNode->Element << '\t';
		}
		else if(nodeQueue.size()) {
			nodeQueue.push(NULL);
			cout << endl;
		}
	}
}