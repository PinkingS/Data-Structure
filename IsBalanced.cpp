#include <cstdio>

bool IsBalanced(BinaryTreeNode* root) {
	if(root == NULL)
		return true;

	int left = TreeDepth(root->m_pLeft);
	int right = TreeDepth(root->m_pRight);
	int diff = left - right;
	if(diff > 1 || diff < -1)
		return false;

	return IsBalanced(root->m_pLeft) && IsBalanced(root->m_pRight);
}

bool IsBalancedDepth(binaryTreeNode* root, int* depth) {
	if(root == NULL){
		*depth = 0;
		return true;
	}

	int left, right;
	if(IsBalancedDepth(root->m_pLeft, &left) && IsBalancedDepth(root->m_pRight, &right)) {
		int diff = left - right;
		if(diff <= 1 && diff >= -1) {
			*depth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}

bool IsBalanced2(BinaryTreeNode* root) {
	int depth = 0;
	return IsBalancedDepth(root, &depth);
}
