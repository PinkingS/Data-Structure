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

ListNode *reverseBetween(ListNode *head, int m, int n) {
	ListNode dummy(0);
	dummy.next = head;
	ListNode *ins = &dummy;
	for(int i = 0; i < m-1; ++i)
		ins = ins->next;
	ListNode *cur = ins->next;
	for(int i = 0; i < n-m; ++i) {
		ListNode *move = cur->next;
		cur->next = move->next;
		move->next = ins->next;
		ins->next = move;
	}
	return dummy.next;
}

int main() {
	int a[] = {1,2,3,4,5};
	ListNode *l1 = constructList(a, 5);
	ListNode *l = reverseBetween(l1, 2, 4);
	showList(l);
	deleteList(l);
	return 0;
}
