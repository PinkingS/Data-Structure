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

vector<vector<int> > levelOrder(TreeNode *root) {
	vector<vector<int> > ans;
	if(!root) return ans;
	queue<TreeNode*> q;
	vector<int> level;
	q.push(root);
	q.push(NULL);
	TreeNode *node;
	while(!q.empty()) {
		node = q.front();q.pop();
		if(node == NULL) {
			ans.push_back(level);
			level.clear();
			if(q.empty())
				break;
			q.push(NULL);
		} else {
			level.push_back(node->val);
			if(node->left) 	q.push(node->left);
			if(node->right) q.push(node->right);
		}
	}
	return ans;
}

int main() {
	string s = "3,9,20,#,#,15,7";
	TreeNode *root = createTree(s);
	vector<vector<int> > ans = levelOrder(root);
	for(int i = 0; i < ans.size(); ++i) {
		for(int j = 0; j < ans[i].size(); ++j)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}
