#include <cstdio>
#include <queue>

void PrintFromTopToBottom(BinaryTreeNode* pRoot) {
	if(pRoot == NULL)
		return ;
	std::queue<BinaryTreeNode*> treeQueue;

	treeQueue.push(pRoot);
	binaryTreeNode* pNode;
	while(!treeQueue.empty()) {
		pNode = treeQueue.front();
		printf("%d\t",pNode->m_nvalue);
		treeQueue.pop();

		if(pNode->m_pLeft)
			treeQueue.push(pNode->m_pLeft);
		if(pNode->m_pRight)
			treeQueue.push(pNode->m_pRight);
	}
}

int main() {

}
