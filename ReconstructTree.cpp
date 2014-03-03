#include <exception>
#include <cstdio>
#include <cstdlib>
#include <queue>

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};



BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder) {
	int rootValue = *startPreorder;
	printf("root value : %d\n", rootValue);
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
	printf("%d\n",*rootInorder);
	while(rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;
printf("%d\n",*rootInorder);
	if(rootInorder == endInorder && *rootInorder != rootValue) {
		printf("Invalid input\n");
		return NULL;
	}
	
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	printf("left length : %d\n",leftLength);
	if(leftLength > 0) {
	printf("left subtree int preorder is from %d to %d\n", *(startPreorder+1), *leftPreorderEnd);
	printf("left subtree int inorder is from %d to %d\n", *(startInorder), *(rootInorder-1));
		//构建左子树
		root->m_pLeft = ConstructCore(startPreorder+1, leftPreorderEnd, startInorder, rootInorder -1);
	}
	printf("start preorder : %d end preorder : %d\n",*startPreorder, *endPreorder);
	if(leftLength < endPreorder - startPreorder) {
	printf("right subtree int preorder is from %d to %d\n", *(leftPreorderEnd+1), *endPreorder);
	printf("right subtree int inorder is from %d to %d\n", *(rootInorder+1), *(endInorder));
		//构建右子树
		root->m_pRight = ConstructCore(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
	}

	return root;
}

BinaryTreeNode* ReconstructTree(int* preorder, int* inorder, int length) {
	if(preorder == NULL || inorder == NULL || length <= 0)
		return NULL;
	return ConstructCore(preorder, preorder + length -1, inorder, inorder + length -1);
}

void displayTree(BinaryTreeNode* root) {
	if(root == NULL)
		return;
	std::queue<BinaryTreeNode*> nodes;
	nodes.push(root);
	nodes.push(NULL);
	while(nodes.size()) {
		BinaryTreeNode* pNode = nodes.front();
		nodes.pop();
		if(pNode) {
			if(pNode->m_pLeft)
				nodes.push(pNode->m_pLeft);
			if(pNode->m_pRight)
				nodes.push(pNode->m_pRight);
			printf("%d\t", pNode->m_nValue);
		}
		else if(nodes.size()) {
			nodes.push(NULL);
			printf("\n");
		}
	}
}

int main() {
	const int length = 7;
	//int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
	//int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};
	int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
	int inorder[length] = {4, 2, 8, 1, 6, 3, 7};
	BinaryTreeNode* root = ReconstructTree(preorder, inorder, length);
	displayTree(root);
	return 0;
}
