#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *constructList(int a[], int n) {
	ListNode dummy(0), *cur = &dummy;
	for(int i = 0; i < n; ++i) {
		ListNode *node = new ListNode(a[i]);
		cur->next = node;
		cur = node;
	}
	return dummy.next;
}

void showList(ListNode *l) {
	while(l) {
		cout << l->val << " ";
		l = l->next;
	}
	cout << endl;
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	ListNode dummy(0), *cur = &dummy;
	while(l1 && l2) {
		ListNode **minNode = l1->val < l2->val ? &l1 : &l2;
		cur->next = *minNode;
		cur = cur->next;
		*minNode = (*minNode)->next;
	}
	if(l1) cur->next = l1;
	if(l2) cur->next = l2;
	return dummy.next;
}


int main() {
	int a[] = {2,3,4};
	int b[] = {1,5,7};
	ListNode *l1 = constructList(a, 3);
	ListNode *l2 = constructList(b, 3);
	ListNode *l = mergeTwoLists(l1, l2);
	showList(l);
	return 0;
}
