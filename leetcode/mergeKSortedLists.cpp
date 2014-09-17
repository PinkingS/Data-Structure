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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	ListNode dummy(0), *cur = &dummy;
	while(l1 && l2) {
		ListNode **minNode = l1->val < l2->val ? &l1 : &l2;
		cur->next = *minNode;
		cur = cur->next;
		*minNode = (*minNode)->next;
	}
	if(l1) cur->next = l1;
	if(l2) cur->next = l2;
	return dummy.next;
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
	if(lists.size() <= 0) return NULL;
	vector<ListNode *> results = lists;
	vector<ListNode *> temp;
	while(results.size() > 1) {
		temp.clear();
		int n = results.size() / 2;
		for(int i = 0; i < n; ++i)
			temp.push_back(mergeTwoLists(results[2*i], results[2*i+1]));
		if(results.size() % 2 == 1)
			temp.push_back(results[2*n]);
		results = temp;
	}
	return results[0];
}

struct cmp {
	bool operator() (ListNode *a, ListNode *b){
		return a->val > b->val;
	}
};

ListNode *mergeKLists_2(vector<ListNode *> &lists) {
	priority_queue<ListNode *, vector<ListNode *>, cmp> q;
	for(int i = 0; i < lists.size(); ++i)
		if(lists[i])
			q.push(lists[i]);
	ListNode dummy(0), *cur = &dummy;
	while(!q.empty()) {
		ListNode *node = q.top();q.pop();
		cur->next = node;
		cur = cur->next;
		node = node->next;
		if(node)
			q.push(node);
	}
	return dummy.next;
}


int main() {
	int a[] = {2,3,4};
	int b[] = {1,5,7};
	int c[] = {6, 9, 10};
	int d[] = {};
	ListNode *l1 = constructList(a, 3);
	ListNode *l2 = constructList(b, 3);
	ListNode *l3 = constructList(c, 3);
	ListNode *l4 = constructList(d, 0);
	vector<ListNode *> lists;
	lists.push_back(l1);
	lists.push_back(l4);
	lists.push_back(l2);
	lists.push_back(l3);
	ListNode *l = mergeKLists_2(lists);
	showList(l);
	deleteList(l);
	return 0;
}
