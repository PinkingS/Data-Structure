#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createTree() {
	string v;
	cin >> v;
	if(v == "#") return NULL;
	else {
		TreeNode *node = new TreeNode(atoi(v.c_str()));
		node->left = createTree();
		node->right = createTree();
		return node;
	}
}

void deleteTree(TreeNode *root) {
	if(!root) return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}


// solution 1 : copy tree node val to array in inorder traversal, then check if the array is ascending order
//              only validate when the tree values have no duplicates
int nodes[30];
int index = 0;

void copyBST(TreeNode *root) {
	if(!root) return;
	copyBST(root->left);
	nodes[index] = root->val;
	++index;
	copyBST(root->right);
}

bool checkBST_1(TreeNode *root) {
	copyBST(root);
	for(int i = 1; i < index; ++i)
		if(nodes[i] <= nodes[i-1]) return false;
	return true;
}

// solution 2 : improve solution 1. just remember the last number
bool checkBST_2Re(TreeNode *root, int &last) {
	if(!root) return true;
	
	if(!checkBST_2Re(root->left, last)) return false;

	if(root->val <= last) return false;
	last = root->val;

	if(!checkBST_2Re(root->right, last)) return false;

	return true;
}

bool checkBST_2(TreeNode *root) {
	int last = INT_MIN;
	return checkBST_2Re(root, last);
}


// solution 3 : refine every node's possible value range, and check
bool checkBST_3Re(TreeNode *root, int min, int max) {
	if(!root) return true;

	if(root->val <= min || root->val > max)
		return false;

	if(!checkBST_3Re(root->left, min, root->val) || !checkBST_3Re(root->right, root->val, max))
		return false;

	return true;
}

bool checkBST_3(TreeNode *root) {
	return checkBST_3Re(root, INT_MIN, INT_MAX);
}


int main() {
	TreeNode *root = createTree();
	cout << checkBST_3(root) << endl;

	deleteTree(root);

	return 0;
}
