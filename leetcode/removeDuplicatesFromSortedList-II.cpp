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

ListNode *deleteDuplicates(ListNode *head) {
	ListNode dummy(0), *cur = &dummy;
	dummy.next = head;
	while(cur->next) {
		ListNode *node = cur->next;
		int val = node->val;
		if(!node->next || node->next->val != val) {
			cur = cur->next;
			continue;
		}
		while(node && node->val == val) {
			ListNode *del = node;
			node = node->next;
			delete del;
		}
		cur->next = node;
	}
	return dummy.next;
}

int main() {
	int a[] = {1,1,2,3,3};
	ListNode *l1 = constructList(a, 5);
	ListNode *l = deleteDuplicates(l1);
	showList(l);
	deleteList(l);
	return 0;
}
