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

int main() {
	int a[] = {1, 2, 3, 5, 8, 11, 23, 25};
	TreeNode *root = createMinimalBST(a, 8);
	showTree(root);
	deleteTree(root);
	return 0;
}
