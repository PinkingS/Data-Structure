struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
	if(!root) return;
	TreeLinkNode *parent = root;
	while(parent->left || parent->right || parent->next) {
		if(!parent->left && !parent->right) {
			parent = parent->next;
			continue;
		}
		TreeLinkNode *head = parent, *tail;
		if(head->left) {
			parent = parent->left;
			tail = head->left;
			if(head->right) {
				tail->next = head->right;
				tail = tail->next;
			}
		} else if(head->right) {
			parent = parent->right;
			tail = head->right;
		}
		while(head = head->next) {
			if(head->left) {
				tail->next = head->left;
				tail = tail->next;
			}
			if(head->right) {
				tail->next = head->right;
				tail = tail->next;
			}
		}
	}
}
