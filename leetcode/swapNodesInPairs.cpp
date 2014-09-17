#include <iostream>
#include <vector>
#include <queue>
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

void deleteList(ListNode *l) {
	while(l) {
		ListNode *tmp = l;
		l = l->next;
		delete tmp;
	}
}

void showList(ListNode *l) {
	while(l) {
		cout << l->val << " ";
		l = l->next;
	}
	cout << endl;
}

ListNode *swapPairs(ListNode *head) {
	ListNode dummy(0), *cur = &dummy;
	dummy.next = head;
	ListNode *move;
	while(cur->next && cur->next->next) {
		move = cur->next->next;	
		cur->next->next = move->next;
		move->next = cur->next;
		cur->next = move;
		cur = cur->next->next;
	}
	return dummy.next;
}


int main() {
	int a[] = {1,2,3,4,5};
	ListNode *l1 = constructList(a, 5);
	ListNode *l = swapPairs(l1);
	showList(l);
	deleteList(l);
	return 0;
}
