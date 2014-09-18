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

ListNode *reorderList(ListNode *head) {
	if(!head || !head->next) return head;
	ListNode *slow = head, *fast = head;
	while(fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	while(fast->next)
		fast = fast->next;

	ListNode *mid = slow, *tail = fast;
	ListNode *prev = mid, *cur = mid->next, *last = cur->next;
	mid->next = NULL;
	while(cur) {
		cur->next = prev;
		prev = cur;
		cur = last;
		if(last)
			last = last->next;
	}
	cur = head;
	while(tail != mid) {
		ListNode *node = tail;
		tail = tail->next;
		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}
	return head;
}

int main() {
	int a[] = {1,2,3,4,5};
	ListNode *l1 = constructList(a, 5);
	ListNode *l = reorderList(l1);
	showList(l);
	deleteList(l);
	return 0;
}
