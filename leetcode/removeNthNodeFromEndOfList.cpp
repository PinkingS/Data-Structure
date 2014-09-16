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


ListNode *removeNthFromEnd(ListNode *head, int n) {
	if(!head) return NULL;
	ListNode dummy(0);
	dummy.next = head;
	ListNode *slow = &dummy, *fast = &dummy;
	while(n--)
		fast = fast->next;
	while(fast->next) {
		slow = slow->next;
		fast = fast->next;
	}
	ListNode *delNode = slow->next;
	slow->next = delNode->next;
	delete delNode;
	return dummy.next;
}


int main() {
	int a[] = {1, 2, 3, 4, 5};
	ListNode *l = constructList(a, 5);
	l = removeNthFromEnd(l, 2);
	showList(l);
	return 0;
}
