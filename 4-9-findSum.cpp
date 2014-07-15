#include <iostream>
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


// solution 1 : for trees which have parent pointer of each node
//              don't need extra space for path, search along parent to print the path
void print(TreeNode *node, int level) {
	vector<int> v;
	for(int i = 0; i < level; ++i) {
		v.push_back(node->val);
		node = node->parent;
	}
	while(!v.empty()) {
		cout << v.back() << " ";
		v.pop_back();
	}
	cout << endl;
}

void findSum(TreeNode *root, int sum) {
	if(!root) return;
	TreeNode *node = root;
	int tmp = 0;
	for(int i = 1; node != NULL; ++i) {
		tmp += node->val;
		if(tmp == sum)
			print(root, i);
		node = node->parent;
	}
	findSum(root->left, sum);
	findSum(root->right, sum);
}


// solution 2 : for trees don't have parent pointer, use an array to store current path
int path[10];

void print_2(int path[], int start, int end) {
	for(int i = start; i <= end; ++i)
		cout << path[i] << " ";
	cout << endl;
}

void findSum_2Re(TreeNode *node, int sum, int path[], int level) {
	if(!node) return;
	
	path[level] = node->val;
	
	int t = 0;
	for(int i = level; i >= 0; --i) {
		t += path[i];
		if(t == sum)
			print_2(path, i, level);
	}

	findSum_2Re(node->left, sum, path, level+1);
	findSum_2Re(node->right, sum, path, level+1);
}

void findSum_2(TreeNode *root, int sum) {
	findSum_2Re(root, sum, path, 0);
} 


int main() {
	int a[] = {4, 3, 8, 5, 2, 1, 6};
	TreeNode *root = createMinimalBST(a, 7);
	showTree(root);

	findSum_2(root, 8);
	deleteTree(root);
	return 0;
}
