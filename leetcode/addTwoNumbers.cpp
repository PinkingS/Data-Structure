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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode dummy(0), *cur = &dummy;
	int carry = 0;
	while(l1 || l2 || carry) {
		int sum = carry;
		if(l1) {
			sum += l1->val;
			l1 = l1->next;
		}
		if(l2) {
			sum += l2->val;
			l2 = l2->next;
		}
		ListNode *node = new ListNode(sum%10);
		carry = sum/10;
		cur->next = node;
		cur = node;
	}
	return dummy.next;
}

int main() {
	int a[] = {2,4,3};
	int b[] = {5,6,4};
	ListNode *l1 = constructList(a, 3);
	ListNode *l2 = constructList(b, 3);
	ListNode *l = addTwoNumbers(l1, l2);
	showList(l);
	return 0;
}
