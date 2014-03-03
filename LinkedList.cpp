#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
};

void AddToTail(ListNode** pHead, int value) {
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;

	if(*pHead == NULL) {
		*pHead = pNew;
	}
	else {
		ListNode* pNode = *pHead;
		while(pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;
		pNode->m_pNext = pNew;
	}
}

void RemoveNode(ListNode** pHead, int value) {
	if(*pHead == NULL || pHead == NULL)
		return;
	ListNode* pToBeDeleted = NULL;
	if((*pHead)->m_nValue == value) {
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;	
	}
	else {
		ListNode* pNode = *pHead;
		while(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value) {
			pNode = pNode->m_pNext;
		}
		if(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value) {
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}
	if(pToBeDeleted != NULL) {
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}

void PrintListRecur_ite(ListNode* pHead) {
	if(pHead == NULL)
		return;
	
	stack<ListNode*> nodes;
	
	ListNode* pNode;
	pNode = pHead;
	
	while(pNode != NULL) {
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	while(!nodes.empty()) {
		pNode = nodes.top();
		printf("%d\t", pNode->m_nValue);
		nodes.pop();
	}
}

void PrintListRecur_rec(ListNode* pHead) {
	if(pHead == NULL)
		return;
	if(pHead->m_pNext != NULL) {
		PrintListRecur_rec(pHead->m_pNext);
	}
	printf("%d\t", pHead->m_nValue);
}

int main() {
	ListNode* list = NULL;
	AddToTail(&list, 1);
	AddToTail(&list, 2);
	AddToTail(&list, 3);
	PrintListRecur_ite(list);
	PrintListRecur_rec(list);
	return 0;
}
