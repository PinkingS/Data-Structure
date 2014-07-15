#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
	TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

void showTree(TreeNode *root) {
	queue<TreeNode *> q;
	if(!root) return;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		TreeNode *node = q.front(); q.pop();
		if(node == NULL) {
			cout << endl;
			if(q.empty())
				return;
			else
				q.push(NULL);
		} else {
			cout << node->val << " ";
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
		}
	}
}

void deleteTree(TreeNode *root) {
	if(!root) return;
	if(root->left) deleteTree(root->left);
	if(root->right) deleteTree(root->right);
	delete root;
}

TreeNode* createMinimalBSTRe(int a[], int start, int end) {
	if(start > end)
		return NULL;
	int mid = (start + end) / 2;
	TreeNode *node = new TreeNode(a[mid]);
	node->left = createMinimalBSTRe(a, start, mid-1);
	if(node->left)
		node->left->parent = node;
	node->right = createMinimalBSTRe(a, mid+1, end);
	if(node->right)
		node->right->parent = node;
	return node;
}

TreeNode* createMinimalBST(int a[], int n) {
	return createMinimalBSTRe(a, 0, n-1);
}

// solution 1 : can use map to store visited nodes and have parent pointer
TreeNode* commonAncestor(TreeNode *n1, TreeNode *n2) {
	if(!n1 || !n2) return NULL;
	map<TreeNode*, bool> m;
	while(n1) {
		m[n1] = true;
		n1 = n1->parent;
	}
	while(n2 && m[n2] == false)
		n2 = n2->parent;

	return n2;
}

// solution 2 : don't use map
bool father(TreeNode *n1, TreeNode *n2) {
	if(!n1) return false;
	else if(n1 == n2) return true;
	else return father(n1->left, n2) || father(n1->right, n2);
}

TreeNode* commonAncestor_2(TreeNode *n1, TreeNode *n2) {
	if(!n1 || !n2) return NULL;
	while(n1) {
		if(father(n1, n2)) return n1;
		n1 = n1->parent;
	}
	return NULL;
}


// solution 3 : don't have parent pointer, search from root dowm
void commonAncestor_3(TreeNode *root, TreeNode *n1, TreeNode *n2, TreeNode* &ans) {
	if(!root || !n1 || !n2) return;
	if(root && father(root, n1) && father(root, n2)) {
		ans = root;
		commonAncestor_3(root->left, n1, n2, ans);
		commonAncestor_3(root->right, n1, n2, ans);
	}
}


// solution 4 : improve solution 3, every node only search once
TreeNode* commonAncestor_4(TreeNode *root, TreeNode *p, TreeNode *q) {
	if(!root) return NULL;
	if(root == p && root == q)
		return root;

	TreeNode *x = commonAncestor_4(root->left, p, q);
	if(x != NULL && x != p && x != q)
		return x;

	TreeNode *y = commonAncestor_4(root->right, p, q);
	if(y != NULL && y != p && y != q)
		return y;

	if(x != NULL && y != NULL)
		return root;
	else if(root == p || root == q)
		return root;
	else
		return x == NULL ? y : x;
}

int main() {
	int a[] = {1, 2, 3, 5, 8, 11, 23, 25};
	TreeNode *root = createMinimalBST(a, 8);
	showTree(root);

	TreeNode *node = commonAncestor_4(root, root->left->left, root->right->right->right);
	cout << node->val << endl;

	deleteTree(root);
	return 0;
}
