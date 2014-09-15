#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <climits>
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

void pathSumRe(TreeNode *root, int sum, vector<int> &path, vector<vector<int> > &res) {
	if(!root) return;
	if(!root->left && !root->right) {
		if(sum == root->val) {
			path.push_back(root->val);
			res.push_back(path);
			path.pop_back();
		}
		return;
	}
	path.push_back(root->val);
	pathSumRe(root->left, sum-root->val, path, res);
	pathSumRe(root->right, sum-root->val, path, res);
	path.pop_back();
}


vector<vector<int> > pathSum(TreeNode *root, int sum) {
	vector<vector<int> > res;
	vector<int> path;
	pathSumRe(root, sum, path, res);
	return res;
}


int main() {
	string s = "5,4,8,11,#,13,4,7,2,#,#,5,1";
	TreeNode *root = createTree(s);
	vector<vector<int> > res = pathSum(root, 22);
	for(int i = 0; i < res.size(); ++i) {
		for(int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
