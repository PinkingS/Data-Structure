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

ListNode *rotateRight(ListNode *head, int k) {
	int len = getLength(head);
	if(!head || k < 1) return head;
	ListNode *slow = head, *fast = head;
	k = k % len;
	while(k--)
		fast = fast->next;
	while(fast->next) {
		slow = slow->next;
		fast = fast->next;
	}
	fast->next = head;
	head = slow->next;
	slow->next = NULL;
	return head;
}

int main() {
	int a[] = {1,2,3,4,5};
	ListNode *l1 = constructList(a, 5);
	ListNode *l = rotateRight(l1, 3);
	showList(l);
	deleteList(l);
	return 0;
}
