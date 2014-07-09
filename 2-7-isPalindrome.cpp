#include <iostream>
#include <stack>

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
		if(i == 0)
			head = p = node;
		else {
			p->next = node;
			p = node;
		}
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


/* solution 1: reverse the list and compare the two lists from beginning to middle 
 */
bool isPalindrome(ListNode *l) {
	if(!l) return true;
	if(!l->next) return true;

	ListNode dummy(0), *reverseList = &dummy;
	ListNode *cur = l;
	while(cur) {
		ListNode *node = new ListNode(cur->val);
		node->next = reverseList->next;
		reverseList->next = node;
		cur = cur->next;
	}	
	reverseList = reverseList->next;

showList(reverseList);
	
	ListNode *fast = l, *slow = l;
	ListNode *slow_re = reverseList;
	while(fast && fast->next) {
		if(slow->val != slow_re->val)
			return false;
		slow = slow->next;
		slow_re = slow_re->next;
		fast = fast->next->next;
	}
	return true;
}


/* solution 2: put the first half of list into a stack
			   compare the last half and stack top iteratively
 */
bool isPalindrome_2(ListNode *l) {
	if(!l || !l->next) return true;
	
	stack<int> st;

	ListNode *fast = l, *slow = l;

	while(fast && fast->next) {
		st.push(slow->val);
		fast = fast->next->next;
		slow = slow->next;
	}
	
	if(fast)
		slow = slow->next;

	while(slow) {
		int val = st.top(); st.pop();
		if(slow->val != val)
			return false;
		slow = slow->next;
	}

	return true;
}

int getLen(ListNode *head) {
	int len = 0;
	while(head) {
		++len;
		head = head->next;
	}
	return len;
}


/* solution 3: make use of recursion to compare node with its correspinding node
 */
bool isPalindromeRe(ListNode *node, int length, ListNode** nextNode) {
	if(!node || length == 0)
		return true;
	if(length == 1) {
		*nextNode = node->next;
		return true;
	}
	else if(length == 2) {
		*nextNode = node->next->next;
		return node->val == node->next->val;
	}

	bool res = isPalindromeRe(node->next, length-2, nextNode);

	if(res == false)
		return false;
	else {
		res = node->val == (*nextNode)->val;
		*nextNode = (*nextNode)->next;
		return res;
	}

}

bool isPalindrome_3(ListNode *l) {
	int len = getLen(l);
	ListNode *p = l;
	ListNode **nextNode = &p;
	return isPalindromeRe(l, len, nextNode);
}

int main() {
	int a[] = {0, 1, 7, 6, 1, 8};
	ListNode *l1 = createList(a, 6);
	showList(l1);
	cout << isPalindrome_3(l1) << endl;

	int b[] = {0, 1, 2, 3, 2, 1, 0};
	ListNode *l2 = createList(b, 7);
	showList(l2);
	cout << isPalindrome_3(l2) << endl;

	return 0;
}
