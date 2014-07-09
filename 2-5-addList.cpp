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
		p = node;
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

ListNode* addList(ListNode *l1, ListNode *l2) {
	ListNode dummy(0), *cur = &dummy;
	int carry = 0;
	while(l1 || l2) {
		int num1 = 0, num2 = 0;
		if(l1) {
			num1 = l1->val;
			l1 = l1->next;
		}
		if(l2) {
			num2 = l2->val;
			l2 = l2->next;
		}
		int sum = num1 + num2 + carry;
		ListNode *node = new ListNode(sum % 10);
		cur->next = node;
		cur = node;
		carry = sum / 10;
	}
	if(carry) {
		ListNode *node = new ListNode(carry);
		cur->next = node;
	}
	return dummy.next;
}

int main() {
	int a[] = {7, 3, 2};
	ListNode *l1 = createList(a, 3);
	showList(l1);

	int b[] = {5, 1, 9, 1, 1};
	ListNode *l2 = createList(b, 5);
	
	ListNode *res = addList(NULL, l2);
	showList(res);

	return 0;
}
