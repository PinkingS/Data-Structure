#include <iostream>
#include <queue>
#include <string>
#include <stdlib.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* createTree() {
	string ch;
	cin >> ch;
	if(ch == "#")
		return NULL;
	else {
		TreeNode *node = new TreeNode(atoi(ch.c_str()));
		node->left = createTree();
		node->right = createTree();
		return node;
	}
}

void showTree(TreeNode *root) {
	queue<TreeNode*> q;
	if(!root) return;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		TreeNode *node = q.front();
		q.pop();
		if(node == NULL) {
			if(q.empty()) {
				cout << endl;
				return;
			}
			cout << endl;
			q.push(NULL);
		} else {
			cout << node->val << " ";
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
		}
	}
}

void deleteTree(TreeNode *root) {
	if(!root)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int abs(int x) {
	return x > 0 ? x : -x;
}

bool isBalancedRe(TreeNode *root, int &height) {
	if(!root)
		return true;
	int leftHeight = 0, rightHeight = 0;
	if(isBalancedRe(root->left, leftHeight) && isBalancedRe(root->right, rightHeight)) {
		height = max(leftHeight, rightHeight) + 1;
		return abs(leftHeight-rightHeight) <= 1;
	} else {
		return false;
	}
	return true;
}

bool isBalanced(TreeNode *root) {
	int height = 0;
	return isBalancedRe(root, height);
}

int main() {
	TreeNode *root = createTree();
	showTree(root);

	cout << isBalanced(root) << endl;

	deleteTree(root);

	return 0;
}
