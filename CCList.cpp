#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef struct ListNode {
	ListNode *next;
	int val;
}ListNode;



ListNode* createList(int a[], int n) {
	ListNode *head, *p;
	for(int i = 0; i < n; ++i) {
		ListNode *nd = new ListNode();
		nd->val = a[i];
		if(i == 0) {
			head = p = nd;
			continue;
		}
		p->next = nd;
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

void removeDuplicate(ListNode *head) {
	bool hash[100];
	memset(hash, false, sizeof(hash));
	if(head == NULL) return;
	ListNode *p = head, *q = head->next;
	hash[head->val] = true;
	while(q) {
		if(hash[q->val]) {
			ListNode *tmp = q;
			p->next = q->next;
			q = p->next;
			delete tmp;
		}
		else {
			hash[q->val] = true;
			p = p->next;
			q = q->next;
		}
	}
}

void removeDuplicate2(ListNode *head) {
	if(head == NULL) return;
	ListNode *p, *q, *c = head;
	while(c) {
		p = c;
		q = c->next;
		int value = c->val;
		while(q) {
			if(q->val == value) {
				ListNode *tmp = q;
				p->next = q->next;
				q = p->next;
				delete tmp;
			} else {
				p = p->next;
				q = q->next;
			}
		}
		c = c->next;
	}
}


void findNthToLast1Re(ListNode *head, int &k, int &res) {
	if(head == NULL) {
		return;
	}
	findNthToLast1Re(head->next, k, res);
	--k;
	if(k == 0)
		res = head->val;
}

int findNthToLast1(ListNode *head, int k) {
	int res = 0;
	if(head == NULL) return -1;
	findNthToLast1Re(head, k, res);
	return res;	
}

int findNthToLast2(ListNode *head, int k) {
	if(head == NULL || k <= 0) return -1;
	ListNode *fast = head, *slow = head;
	while(k-- && fast) {
		fast = fast->next;
	}
	if(k > 0) return -1;
	while(fast) {
		fast = fast->next;
		slow = slow->next;
	}
	return slow->val;
}

bool deleteNode(ListNode *p) {
	if(p == NULL || p->next == NULL) return false;
	ListNode *tmp = p->next;
	p->next = tmp->next;
	p->val = tmp->val;
	delete tmp;
	return true;
}

int main() {
	int a[] = {1, 2, 3, 4, 5};
	ListNode *l1 = createList(a, 5);
	showList(l1);

	//removeDuplicate2(l1);
	//showList(l1);

	//cout << findNthToLast2(l1, 2) << endl;
	
	cout << deleteNode(l1->next->next) << endl;
	showList(l1);

	return 0;
}
