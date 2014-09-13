#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib>
#include <queue>
#include <cmath>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// build tree from string ...
vector<string> split(string s) {
	vector<string> ret;
	int last = 0;
	int index = s.find_first_of(',', last);
	while(index != -1) {
		ret.push_back(s.substr(last, index-last));
		last = index+1;
		index = s.find_first_of(',', last);
	}
	
	ret.push_back(s.substr(last));
	
	return ret;
}

TreeNode* constructNode(string s) {
	if(s == "#")
		return NULL;
	else
		return new TreeNode(atoi(s.c_str()));
}

TreeNode* createTree(string s) {
	vector<string> tree = split(s);
	queue<TreeNode *> q;
	TreeNode *root = constructNode(tree[0]);
	int idx = 1;
	q.push(root);
	while(!q.empty()) {
		TreeNode *node = q.front();q.pop();
		if(node == NULL)
			continue;
		
		if(idx == tree.size())
			break;

		TreeNode* leftNode = constructNode(tree[idx]);
		node->left = leftNode;
		q.push(leftNode);
		idx++;
		if(idx == tree.size())
			break;

		TreeNode* rightNode = constructNode(tree[idx]);
		node->right = rightNode;
		q.push(rightNode);
		idx++;
	}
	return root;
}


// delete tree...
void deleteTree(TreeNode *root) {
	if(!root)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}


// show tree in level order ...
void showTree(TreeNode *root) {
	queue<TreeNode*> q;
	if(!root)
		return;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		TreeNode *node = q.front();q.pop();
		if(node == NULL) {
			cout << endl;
			if(q.empty())
				return;
			q.push(NULL);
		}
		else {
			cout << node->val << " ";
			if(node->left)
				q.push(node->left);
			if(node->right)
				q.push(node->right);		
		}
	}
}

bool isBalancedRe(TreeNode *root, int &height) {
	if(!root)
		return true;

	int leftHeight = 0, rightHeight = 0;
	if(!isBalancedRe(root->left, leftHeight)) return false;
	if(!isBalancedRe(root->right, rightHeight)) return false;
	if(abs(leftHeight-rightHeight) > 1) return false;

	height = 1 + max(leftHeight, rightHeight);
	return true;
}

bool isBalanced(TreeNode *root) {
	int height = 0;
	return isBalancedRe(root, height);
}

int main() {
	string s1 = "1,2,3,#,#,4,5,6,#,#,#";
	string s2 = "1,2,3,#,#,4,#";
	TreeNode *tree1 = createTree(s1);
	TreeNode *tree2 = createTree(s2);
	cout << boolalpha << isBalanced(tree1) << endl;
	cout << boolalpha << isBalanced(tree2) << endl;
	return 0;
}
