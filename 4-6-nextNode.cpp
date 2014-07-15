#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
	TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
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
	if(node->left) 
		node->left->parent = node;
	node->right = createMinimalBSTRe(a, mid+1, end);
	if(node->right) 
		node->right->parent = node;
	return node;
}

TreeNode* createMinimalBST(int a[], int n) {
	return createMinimalBSTRe(a, 0, n-1);
}

TreeNode* minimal(TreeNode *node) {
	if(!node)
		return NULL;
	while(node->left)
		node = node->left;
	return node;
}

TreeNode* findNextNode(TreeNode *node) {
	if(!node) return NULL;
	if(node->right) 
		return minimal(node->right);
	TreeNode *tmp = node->parent;
	while(tmp && tmp->right == node) {
		node = tmp;
		tmp = tmp->parent;
	}
	return tmp;
}

int main() {
	int a[] = {1, 2, 3, 5, 8, 11, 23, 25};
	TreeNode *root = createMinimalBST(a, 8);
	showTree(root);

	TreeNode *node = findNextNode(root->right->right->right);
	cout << node->val << endl;
	

	deleteTree(root);
	return 0;
}
