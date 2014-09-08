struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode *root) {
	return isValidBST(root, INT_MIN, INT_MAX);
}

bool isValidBST(TreeNode *root, int lowerBound, int upperBound) {
	if(!root) return true;
	if(root->val <= lowerBound || root->val >= upperBound)
		return false;
	return isValidBST(root->left, lowerBound, root->val) && isValidBST(root->right, root->val, upperBound);
}
