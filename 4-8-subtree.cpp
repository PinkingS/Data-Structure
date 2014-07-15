#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void showTree(TreeNode *root) {
	queue<TreeNode *> q;
	if(!root) return;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		TreeNode *node = q.front(); q.pop();
		if(node == NULL) {
			cout << endl;
			if(q.empty())
				return;
			else
				q.push(NULL);
		} else {
			cout << node->val << " ";
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
		}
	}
}

void deleteTree(TreeNode *root) {
	if(!root) return;
	if(root->left) deleteTree(root->left);
	if(root->right) deleteTree(root->right);
	delete root;
}

TreeNode* createMinimalBSTRe(int a[], int start, int end) {
	if(start > end)
		return NULL;
	int mid = (start + end) / 2;
	TreeNode *node = new TreeNode(a[mid]);
	node->left = createMinimalBSTRe(a, start, mid-1);
	node->right = createMinimalBSTRe(a, mid+1, end);
	return node;
}

TreeNode* createMinimalBST(int a[], int n) {
	return createMinimalBSTRe(a, 0, n-1);
}

bool match(TreeNode *t1, TreeNode *t2) {
	if(!t1 && !t2) return true;
	if(!t1 || !t2) return false;
	if(t1->val != t2->val) return false;
	return match(t1->left, t2->left) && match(t1->right, t2->right);
}

bool subtree(TreeNode *t1, TreeNode *t2) {
	if(!t1) return false;
	if(t1->val == t2->val)
		if(match(t1, t2)) return true;
	return subtree(t1->left, t2) || subtree(t1->right, t2);
}

bool containsTree(TreeNode *t1, TreeNode *t2) {
	if(!t2) return true;
	else return subtree(t1, t2);
}

int main() {
	int a[] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 15, 23, 25};
	TreeNode *root = createMinimalBST(a, 13);
	showTree(root);

	int b[] = {15, 22, 25};
	TreeNode *t2 = createMinimalBST(b, 3);
	showTree(t2);

	cout << containsTree(root, t2) << endl;

	deleteTree(root);
	deleteTree(t2);
	return 0;
}
