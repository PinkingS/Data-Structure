#include <cstdio>

struct ListNode {
	int m_nKey;
	ListNode* m_pNext;
};

unsigned int length(ListNode* pHead) {
	ListNode* pNode = pHead;
	unsigned int length = 0;
	while(pNode != NULL) {
		length++;
		pNode = pNode->m_pNext;
	}
	return length;
}


ListNode* FindFirstComminNode(ListNode* pHead1, ListNode* pHead2) {
	if(pHead1 == NULL || pHead2 == NULL)
		return NULL;

	unsigned int length1 = length(pHead1);
	unsigned int length2 = length(pHead2);
	
	int lengthDif;
	ListNode *pLong, *pShort;

	if(length2 >= length1) {
		lengthDif = length2 - length1;
		pLong = pHead2;
		pShort = pHead1;
	} else {
		lengthDif = length1 - length2;
		pLong = pHead1;
		pShort = pHead2;
	}

	for(int i = 0; i < lengthDif; ++i) {
		pLong = pLong->m_pNext;
	}

	while(pLong != NULL && pShort != NULL) {
		if(pLong == pShort)
			return pLong;
		else {
			pLong = pLong->m_pNext;
			pShort = pShort->m_pNext;
		}
	}
}
