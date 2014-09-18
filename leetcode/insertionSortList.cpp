#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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

ListNode *insertionSortList(ListNode *head) {
	if(!head) return head;
	ListNode dummy(INT_MIN), *start = &dummy;
	dummy.next = head;
	ListNode *cur = head;
	while(cur->next) {
		ListNode *p = start;
		while(p->next->val < cur->next->val)
			p = p->next;
		if(p == cur) {
			cur = cur->next;
			continue;
		}
		ListNode *move = cur->next;
		cur->next = move->next;
		move->next = p->next;
		p->next = move;
	}
	return dummy.next;
}


int main() {
	int a[] = {3,1,5,2,4};
	ListNode *l1 = constructList(a, 5);
	ListNode *l = insertionSortList(l1);
	showList(l);
	deleteList(l);
	return 0;
}
