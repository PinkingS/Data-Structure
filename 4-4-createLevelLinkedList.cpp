#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <stdlib.h>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createTree() {
	string v;
	cin >> v;
	if(v == "#")
		return NULL;
	else {
		TreeNode *node = new TreeNode(atoi(v.c_str()));
		node->left = createTree();
		node->right = createTree();
		return node;
	}
}

void deleteTree(TreeNode *root) {
	if(!root) return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

vector<list<TreeNode*> > createLevelLinkedList(TreeNode *root) {
	vector<list<TreeNode*> > res;
	int level = 0;
	list<TreeNode*> li;
	li.push_back(root);
	res.push_back(li);
	while(!res[level].empty()) {
		list<TreeNode*> l;
		for(list<TreeNode*>::iterator it = res[level].begin(); it != res[level].end(); ++it) {
			TreeNode *node = *it;
			if(node->left) l.push_back(node->left);
			if(node->right) l.push_back(node->right);
		}
		res.push_back(l);
		++level;
	}
	return res;
}

int main() {
	TreeNode *root = createTree();
	vector<list<TreeNode*> > res;
	res = createLevelLinkedList(root); 
	
	vector<list<TreeNode*> >::iterator it;
	for(it = res.begin(); it != res.end(); ++it) {
		list<TreeNode*> li = *it;
		list<TreeNode*>::iterator iit;
		for(iit = li.begin(); iit != li.end(); ++iit) {
			TreeNode *n = *iit;
			cout << n->val << " ";
		}
		cout << endl;
	}

	return 0;
}
