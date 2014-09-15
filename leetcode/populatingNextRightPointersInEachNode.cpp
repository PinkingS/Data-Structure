struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {} 
}

void connect(TreeLinkNode *root) {
	if(!root) return;
	TreeLinkNode *head = root;
	while(head->left) {
		TreeLinkNode *node = head;
		while(node) {
			node->left->next = node->right;
			if(node->next)
				node->right->next = node->next->left;
			node = node->next;
		}
		head = head->left;
	}
}
