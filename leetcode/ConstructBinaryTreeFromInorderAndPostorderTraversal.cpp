#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void showTree(TreeNode *root) {
	if(!root) return;
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	TreeNode *node;
	while(!q.empty()) {
		node = q.front();q.pop();
		if(node) {
			cout << node->val << " ";
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
		} else {
			cout << endl;
			if(q.empty())
				break;
			q.push(NULL);
		}
	}
}

TreeNode *buildTreeRe(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd) {
	if(postStart > postEnd || inStart > inEnd) 
		return NULL;
	TreeNode *root = new TreeNode(postorder[postEnd]);

	int k = 0;
	while(inorder[inStart+k] != postorder[postEnd]) {
		++k;
	}
	root->left = buildTreeRe(postorder, postStart, postStart+k-1, inorder, inStart, inStart+k-1);
	root->right = buildTreeRe(postorder, postStart+k, postEnd-1, inorder, inStart+k+1, inEnd);
	return root;
}

TreeNode *buildTree(vector<int> &postorder, vector<int> &inorder) {
	int n = postorder.size();
	buildTreeRe(postorder, 0, n-1, inorder, 0, n-1);
}

int main() {
	int a[] = {2, 6, 4, 5, 3, 1};
	int b[] = {2, 1, 6, 4, 3, 5};
	vector<int> postorder(a, a+6);
	vector<int> inorder(b, b+6);
	TreeNode *root = buildTree(postorder, inorder);
	showTree(root);
	return 0;
}
