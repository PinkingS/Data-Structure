#include <iostream>

using namespace std;

struct node{
	int val;
	node *left;
	node *right;
	int left_size;
	node(int d) : val(d), left(NULL), right(NULL), left_size(0) {}
};

void insert(node *root, int d) {
	if(d <= root->val) {
		if(root->left) insert(root->left, d);
		else  root->left = new node(d);
		root->left_size++;
	} else {
		if(root->right) insert(root->right, d);
		else
			root->right = new node(d);
	}
}

int getRank(node *root, int d) {
	if(root->val == d)
		return root->left_size;
	if(root->val > d) {
		if(!root->left) return -1;
		else return getRank(root->left, d);
	}
	if(root->val < d) {
		if(!root->right) return -1;
		return root->left_size + 1 + getRank(root->right, d);
	}
}

void deleteTree(node *root) {
	if(!root) return;
	if(root->left) deleteTree(root->left);
	if(root->right) deleteTree(root->right);
	delete root;
}
 
int main() {
	int a[] = {15, 10, 5, 13, 25, 23, 24};
	node *root = new node(20);
	for(int i = 0; i < 7; ++i)
		insert(root, a[i]);
	cout << getRank(root, 24) << endl;
	deleteTree(root);
	return 0;
}
