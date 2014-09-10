#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void recoverTreeRe(TreeNode *curNode, TreeNode *&preNode, TreeNode *&first, TreeNode *&second) {
	if(!curNode) return;
	recoverTreeRe(curNode->left, preNode, first, second);
	if(preNode && preNode->val > curNode->val) {
		if(!first)
			first = preNode;
		second = curNode;
	}
	preNode = curNode;
	recoverTreeRe(curNode->right, preNode, first, second);
}

void recoverTree(TreeNode *root) {
	TreeNode *preNode = NULL, *first = NULL, *second = NULL;
	recoverTreeRe(root, preNode, first, second);
	swap(first->val, second->val);
}

void inorderTraversal(TreeNode *root, vector<TreeNode*> &inorder) {
	if(!root) return;
	inorderTraversal(root->left, inorder);
	inorder.push_back(root);
	inorderTraversal(root->right, inorder);
}

void recoverTree_2(TreeNode *root) {
	vector<TreeNode*> inorder;
	inorderTraversal(root, inorder);
	TreeNode *first = NULL, *second = NULL;
	for(int i = 1; i < inorder.size(); ++i) {
		if(inorder[i-1]->val < inorder[i]->val)
			continue;
		if(!first)
			first = inorder[i-1];
		second = inorder[i];
	}
	swap(first->val, second->val);
}

void recoverTree_3(TreeNode *root) {
	TreeNode *pre = NULL, *first = NULL, *second = NULL;
	TreeNode *cur = root;
	while(cur) {
		if(cur->left == NULL) {
			if(pre && pre->val > cur->val) {
				if(!first)
					first = pre;
				second = cur;
			}
			pre = cur;
			cur = cur->right;
		}
		else {
			TreeNode *tmp = cur->left;
			while(tmp->right && tmp->right != cur) {
				tmp = tmp->right;
			}
			
			if(tmp->right == NULL) {
				tmp->right = cur;
				cur = cur->left;
			} else if(tmp->right == cur) {
				tmp->right = NULL;
				if(pre && pre->val > cur->val) {
					if(!first)
						first = pre;
					second = cur;
				}
				pre = cur;
				cur = cur->right;
			}
		}
	}
	swap(first->val, second->val);
}
