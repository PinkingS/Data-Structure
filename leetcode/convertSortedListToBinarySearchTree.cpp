#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getLength(ListNode *l) {
	int len = 0;
	while(l) {
		++len;
		l - l->next;
	}
	return len;
}

TreeNode *sortedListToBSTRe(ListNode *&head, int len) {
	if(len == 0) return NULL;
	int mid = len/2;
	TreeNode *leftTree = sortedListToBSTRe(head, mid);
	TreeNode *root = new TreeNode(head->val);
	head = head->next;
	TreeNode *rightTree = sortedListToBSTRe(head, len-mid-1);
	root->left = leftTree;
	root->right = rightTree;
	return root;
}

TreeNode *sortedListToBST(ListNode *head) {
	return sortedListToBSTRe(head, getLength(head));
}
