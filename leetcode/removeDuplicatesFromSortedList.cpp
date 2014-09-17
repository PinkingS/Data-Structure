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
	if(!head || !head->next) return head;
	ListNode *cur = head;
	while(cur->next) {
		if(cur->next->val == cur->val) {
			ListNode *del = cur->next;
			cur->next = del->next;
			delete del;
		} else {
			cur = cur->next;
		}
	}
	return head;
}

int main() {
	int a[] = {1,1,2,3,3};
	ListNode *l1 = constructList(a, 5);
	ListNode *l = deleteDuplicates(l1);
	showList(l);
	deleteList(l);
	return 0;
}
