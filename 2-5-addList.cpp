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

int getLen(ListNode *head) {
	int len = 0;
	while(head) {
		++len;
		head = head->next;
	}
	return len;
}

ListNode* padList(ListNode *head, int padding) {
	ListNode *newHead = head;
	while(padding) {
		ListNode *node = new ListNode(0);
		node->next = newHead;
		newHead = node;
		--padding;
	}
	return newHead;
}

ListNode* addListReverseRe(ListNode *l1, ListNode *l2, int &carry) {
	if(!l1 && !l2)
		return NULL;
	
	ListNode *head = addListReverseRe(l1->next, l2->next, carry);
	int sum = carry + l1->val + l2->val;
	ListNode *node = new ListNode(sum % 10);
	node->next = head;
	carry = sum / 10;
	return node;
}

ListNode* addListReverse(ListNode *l1, ListNode *l2) {
	int len1 = getLen(l1);
	int len2 = getLen(l2);

	if(len1 < len2)
		l1 = padList(l1, len2 - len1);
	else
		l2 = padList(l2, len1 - len2);

	int carry = 0;
	ListNode *sumList = addListReverseRe(l1, l2, carry);
	
	if(carry == 0)
		return sumList;
	else {
		ListNode *res = new ListNode(carry);
		res->next = sumList;
		return res;
	}
		
}

int main() {
	int a[] = {7, 3, 2};
	ListNode *l1 = createList(a, 3);
	showList(l1);

	int b[] = {9, 1, 1};
	ListNode *l2 = createList(b, 3);
	
	ListNode *res = addList(NULL, l2);
	showList(res);

	ListNode *res2 = addListReverse(l1, l2);
	showList(res2);

	return 0;
}
