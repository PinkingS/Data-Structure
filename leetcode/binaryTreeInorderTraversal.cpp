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

void deleteTree(TreeNode *root) {
	if(!root)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

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


void inorderTraversalRe(TreeNode *root, vector<int> &res) {
	if(!root) return;
	inorderTraversalRe(root->left, res);
	res.push_back(root->val);
	inorderTraversalRe(root->right, res);
}

vector<int> inorderTraversal(TreeNode *root) {
	vector<int> res;
	inorderTraversalRe(root, res);
	return res;
}


vector<int> inorderTraversal_2(TreeNode *root) {
	vector<int> res;
	TreeNode *cur = root, *pre = NULL;
	while(cur) {
		if(cur->left == NULL) {
			res.push_back(cur->val);
			cur = cur->right;
		}
		else {
			pre = cur->left;
			while(pre->right && pre->right != cur)
				pre = pre->right;

			if(pre->right == NULL) {
				pre->right = cur;
				cur = cur->left;
			} else {
				pre->right = NULL;
				res.push_back(cur->val);
				cur = cur->right;
			}
		}
	}
	return res;
}

vector<int> inorderTraversal_3(TreeNode *root) {
	vector<int> res;
	stack<TreeNode *> st;
	while(root || !st.empty()) {
		if(root) {
			st.push(root);
			root = root->left;
		} else {
			root = st.top();st.pop();
			res.push_back(root->val);
			root = root->right;
		}
	}
	return res;
}

int main() {
	string s = "1,#,2,3";
	TreeNode *root = createTree(s);
	showTree(root);
	vector<int> seq = inorderTraversal(root);
	for(int i = 0; i < seq.size(); ++i)
		cout << seq[i] << " ";
	cout << endl;

	seq = inorderTraversal_2(root);
	for(int i = 0; i < seq.size(); ++i)
		cout << seq[i] << " ";
	cout << endl;

	seq = inorderTraversal_3(root);
	for(int i = 0; i < seq.size(); ++i)
		cout << seq[i] << " ";
	cout << endl;

	return 0;
}
