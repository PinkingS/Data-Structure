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

int getLength(ListNode *l) {
	int len = 0;
	while(l) {
		++len;
		l = l->next;
	}
	return len;
}

ListNode *reverseKGroup(ListNode *head, int k) {
	int len = getLength(head);
	if(!head || len < 1 || k <= 1) return head;
	int times = len / k;
	ListNode dummy(0), *cur = head;
	dummy.next = head;
	ListNode *start = &dummy, *move;
	while(times--) {
		for(int i = 0; i < k-1; ++i) {
			move = cur->next;
			cur->next = move->next;
			move->next = start->next;
			start->next = move;
		}
		start = cur;
		cur = cur->next;
	}
	return dummy.next;
}


int main() {
	int a[] = {1,2,3,4,5};
	ListNode *l1 = constructList(a, 5);
	ListNode *l = reverseKGroup(l1, 5);
	showList(l);
	deleteList(l);
	return 0;
}
