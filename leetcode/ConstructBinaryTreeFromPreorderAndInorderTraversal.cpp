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

TreeNode *buildTreeRe(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd) {
	if(preStart > preEnd) return NULL;
	TreeNode *root = new TreeNode(preorder[preStart]);
	if(preStart == preEnd)
		return root;

	int index = inStart;
	while(index <= inEnd) {
		if(inorder[index] == preorder[preStart])
			break;
		++index;
	}
	int leftSize = index - inStart;
	root->left = buildTreeRe(preorder, preStart+1, preStart+leftSize, inorder, inStart, index-1);
	root->right = buildTreeRe(preorder, preStart+leftSize+1, preEnd, inorder, index+1, inEnd);
	return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	int n = preorder.size();
	buildTreeRe(preorder, 0, n-1, inorder, 0, n-1);
}

int main() {
	int a[] = {1, 2, 3, 4, 6, 5};
	int b[] = {2, 1, 6, 4, 3, 5};
	vector<int> preorder(a, a+6);
	vector<int> inorder(b, b+6);
	TreeNode *root = buildTree(preorder, inorder);
	showTree(root);
	return 0;
}
