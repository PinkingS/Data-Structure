#include <exception>
#include <cstdio>
#include <cstdlib>
#include <queue>

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
}

BinaryTreeNode* ReconstructTree(int* preorder, int* inorder, int length) {
	if(preorder == NULL || inorder == NULL || length <= 0)
		return NULL;
	return ConstructCore(preorder, preorder + length -1, inorder, inorder + length -1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder) {
	int rootValue = *startPreorder;
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = NULL;

	if(startPreorder == endPreorder) {
		if(startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else {
			printf("Invalid input\n");
			return NULL;
		}
	}

	//在中序遍历中找到根节点的值
	int* rootInorder = startInorder;
	while(rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;

	if(rootInorder == endInorder && *rootInorder != rootValue) {
		printf("Invalid input\n");
		return NULL;
	}
	
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if(leftLength > 0) {
		//构建左子树
		root->m_pLeft = ConstructCore(startPreorder+1, leftPreorderEnd, startInorder, rootInorder -1);
	}
	if(leftLength < startPreorder - endPreorder) {
		//构建右子树
		root->m_pRight = ConstrctCore(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
	}

	return root;
}

void displayTree(BinaryTreeNode* root) {
	if(root == NULL)
		return;
	queue<BinaryTreeNode*> nodes;
	nodes.push(root);
	nodes.push(NULL);
	while(!nodes.empty()) {
		BinaryTreeNode* pNode = nodes.front();
		nodes.pop();
		if(pNode) {
			if(pNode->m_pLeft)
				nodes.push(pNode->m_pLeft);
			if(pNode->m_pRight)
				nodes.push(pNode->m_pRight);
			printf("%d\t||\t", pNode->m_nValue);
		}
		else if(!nodes.empty()) {
			nodes.push(NULL);
			printf("\n");
		}
	}
}

int main() {
	const int length = 8;
	int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
	int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};
	BinaryTreeNode* root = ReconstructTree(preorder, inorder, length);
	displayTree(root);
	return 0;
}
