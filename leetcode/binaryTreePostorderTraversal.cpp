#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib>
#include <queue>
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

void postorderTraversalRe(TreeNode *root, vector<int> &res) {
	if(!root)
		return;
	postorderTraversalRe(root->left, res);
	postorderTraversalRe(root->right, res);
	res.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root) {
	vector<int> res;
	postorderTraversalRe(root, res);
	return res;
}

vector<int> postorderTraversal_2(TreeNode *root) {
	vector<int> res;
	stack<TreeNode*> st1, st2;
	st1.push(root);
	while(!st1.empty()) {
		TreeNode *cur = st1.top(); st1.pop();
		st2.push(cur);
		if(cur->left)
			st1.push(cur->left);
		if(cur->right)
			st1.push(cur->right);
	}

	while(!st2.empty()) {
		TreeNode *cur = st2.top();st2.pop();
		res.push_back(cur->val);
	}
	return res;
}


void reverse(TreeNode *from, TreeNode *to) {
	if(from == to) return;
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

void reverseAdd(TreeNode *from, TreeNode *to, vector<int> &res) {
	reverse(from, to);
	TreeNode *cur = to;
	while(true) {
		res.push_back(cur->val);
		if(cur == from)
			break;
		cur = cur->right;
	}
	reverse(to, from);
}

vector<int> postorderTraversal_3(TreeNode *root) {
	vector<int> res;
	TreeNode dump(0);
	dump.left = root;
	TreeNode *cur = &dump, *pre = NULL;
	while(cur) {
		if(cur->left == NULL)
			cur = cur->right;	
		else {
			pre = cur->left;
			while(pre->right && pre->right != cur)
				pre = pre->right;

			if(pre->right == NULL) {
				pre->right = cur;
				cur = cur->left;
			} else {
				reverseAdd(cur->left, pre, res);
				pre->right = NULL;
				cur = cur->right;
			}
		}
	}
	return res;
}


int main() {
	string s = "1,#,2,3";
	TreeNode *root = createTree(s);
	showTree(root);
	vector<int> seq = postorderTraversal(root);
	for(int i = 0; i < seq.size(); ++i)
		cout << seq[i] << " ";
	cout << endl;

	seq = postorderTraversal_2(root);
	for(int i = 0; i < seq.size(); ++i)
		cout << seq[i] << " ";
	cout << endl;

	seq = postorderTraversal_3(root);
	for(int i = 0; i < seq.size(); ++i)
		cout << seq[i] << " ";
	cout << endl;

	deleteTree(root);

	return 0;
}
