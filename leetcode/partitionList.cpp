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

ListNode *partition(ListNode *head, int x) {
	ListNode dummy(0), *ins = &dummy;
	ListNode *cur = ins;
	dummy.next = head;
	while(cur->next && cur->next->val < x)
		cur = cur->next;
	ins = cur;
	while(cur->next) {
		if(cur->next->val >= x) {
			cur = cur->next;
			continue;
		}
		ListNode *move = cur->next;
		cur->next = move->next;
		move->next = ins->next;
		ins->next = move;
		ins = ins->next;
	}
	return dummy.next;
}


int main() {
	int a[] = {1,4,3,2,5,2};
	ListNode *l1 = constructList(a, 6);
	ListNode *l = partition(l1, 3);
	showList(l);
	deleteList(l);
	return 0;
}
