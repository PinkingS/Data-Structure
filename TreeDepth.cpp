#include <cstdio>

int TreeDepth(BinaryTreeNode* root) {
	if(root == NULL)
		return 0;
	int nLeft = TreeDepth(root->m_pLeft);
	int nRight = TreeDepth(root->m_pRight);
	return (nLeft > nright) ? (nLeft+1) : (nRight+1);
}
