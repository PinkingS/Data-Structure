#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(int a[], int n) {
	ListNode *head, *p;
	for(int i = 0; i < n; ++i) {
		ListNode *node = new ListNode(a[i]);
		if(i == 0) {
			head = p = node;
			continue;
		}
		p->next = node;
		p = p->next;
	}
	return head;
}

void showList(ListNode *head) {
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

ListNode* partitionList(ListNode *head, int pivot) {
	if(!head) return head;
	ListNode dummy(0), *cur = &dummy;
	dummy.next = head;

	// move insertion point to the furthest < point
	while(cur->next && cur->next->val < pivot)
		cur = cur->next;	

	if(!cur->next) return dummy.next;

	// insert nodes less than pivot after cur	
	ListNode *p = cur->next;
	while(p->next) {
		if(p->next->val < pivot) {
			ListNode *move = p->next;
			p->next = move->next;
			move->next = cur->next;
			cur->next = move;
			cur = move;
		} else {
			p = p->next;
		}
	}
	return dummy.next;
}

int main() {
	int a[] = {5, 3, 2, 1, 4};
	ListNode *l1 = createList(a, 5);
	showList(l1);

	l1 = partitionList(l1, 3);
	showList(l1);

	int b[] = {1};
	ListNode *l2 = createList(b, 1);
	l2 = partitionList(l2, 5);
	showList(l2);


	int c[] = {1, 2, 4, 7, 8, 3};
	ListNode *l3 = createList(c, 6);
	l3 = partitionList(l3, 5);
	showList(l3);

	return 0;
}
