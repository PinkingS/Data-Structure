#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* morris traversal
 * 空间复杂度为O(1)
 * 时间复杂度为O(n)
*/ 

// 1.如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点
// 2.如果当前节点的做孩子不为空，在当前节点的左子树中找到中序遍历中当前节点的前驱节点
//     a)如果前驱节点的右孩子为空，则前驱节点右孩子链到当前节点，当前节点转到当前节点的左节点
//     b)如果前驱节点的右孩子为当前节点，则前驱节点的右孩子恢复为空，输出当前节点，并将当前节点转移至右孩子
// 3.重复以上步骤直到当前节点为空
void inorderTraversal(TreeNode *root) {
	TreeNode *pre = NULL, *cur = root;;
	while(cur != NULL) {
		if(cur->left == NULL) {  // 1.
			cout << cur->val << endl;
			cur = cur->right;
		}
		else {
			pre = cur->left;
			while(pre->right && pre->right != cur)
				pre = pre->right;
			if(pre->right == NULL) {  // 2.a)
				pre->right = cur;
				cur = cur->left;
			} else if(pre->right == cur) {  // 2.b)
				pre->right = NULL;
				cout << cur->val << endl;
				cur = cur->right;
			}
		}
	}
}

// 只在2.a与inorder不同，在这里要输出当前节点。在2.b不输出节点
void preorderTraversal(TreeNode *root) {
	TreeNode *cur = root, *pre = NULL;
	while(cur != NULL) {
		if(cur->left == NULL) {
			cout << cur->val << endl;
			cur = cur->right;
		}
		else {
			pre = cur->left;
			while(pre->right && pre->right != cur)
				pre = pre->right;

			if(pre->right == NULL) { 
				pre->right = cur;
				cout << cur->val << endl; // the only difference with inorder
				cur = cur->left;
			} else {
				pre->right = NULL;
				cur = cur->right;
			}
		}
	}
}



// 后序遍历
// 需要建立一个临时节点dump，令其左孩子是root，并且还需要一个子过程，就是倒序输出一条右边路径上的节点
// 当前节点设置为dump
// 不同的是2.b) 倒序输出从当前节点的左孩子到前驱节点路径上的所有节点，只有在这里有输出节点.
void reverse(TreeNode *from, TreeNode *to) {
	if(from == to)
		return;
	TreeNode *x = from, *y = x->right, *z;
	while(true) {
		z = y->right;
		y->right = x;
		x = y;
		y = z;
		if(x == to)
			break;
	}
}

void printReverse(TreeNode *from, TreeNode *to) {
	reverse(from, to);

	TreeNode *p = to;
	while(true) {
		cout << p->val << endl;
		if(p == from)
			break;
		p = p->right;
	}
	reverse(to, from);
}

void postorderTraversal(TreeNode *root) {
	TreeNode dump(0);
	dump.left = root;
	TreeNode *cur = root, *pre = NULL;
	while(cur) {
		if(cur->left == NULL) {
			cur = cur->right;
		}
		else {
			pre = cur->left;
			while(pre->right && pre->right != cur) {
				pre = pre->right;
			}

			if(pre->right == NULL) {
				pre->right = cur;
				cur = cur->left;
			} else {
				printReverse(cur->left, pre);
				pre->right = NULL;
				cur = cur->right;
			}
		}
	}
}
