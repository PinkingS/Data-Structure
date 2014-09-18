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

int getLength(ListNode *head) {
	int len = 0;
	while(head) {
		++len;
		head = head->next;
	}
	return len;
}

ListNode *mergeList(ListNode *l1, ListNode *l2) {
	ListNode dummy(0), *cur = &dummy;
	while(l1 && l2) {
		ListNode **minNode = l1->val < l2->val ? &l1 : &l2;
		cur->next = *minNode;
		*minNode = (*minNode)->next;
		cur = cur->next;
	}
	if(l1) cur->next = l1;
	if(l2) cur->next = l2;
	return dummy.next;
}


ListNode *sortListRe(ListNode *&head, int len) {
	if(len == 0) return NULL;
	if(len == 1) {
		ListNode *node = head;
		head = head->next;
		node->next = NULL;
		return node;
	}
	int mid = len/2;
	ListNode *left = sortListRe(head, mid);
	ListNode *right = sortListRe(head, len-mid);
	return mergeList(left, right);
}

ListNode *sortList(ListNode *head) {
	return sortListRe(head, getLength(head));
}

int main() {
	int a[] = {1,4,3,2,5};
	ListNode *l1 = constructList(a, 5);
	ListNode *l = sortList(l1);
	showList(l);
	deleteList(l);
	return 0;
}
