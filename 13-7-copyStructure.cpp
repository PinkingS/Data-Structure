typedef map<Node*, Node*> NodeMap;

Node* copyRe(Node *cur, NodeMap &nodemap) {
	if(!cur)
		return NULL;
	NodeMap::iterator i = nodemap.find(cur);
	if(i != nodemap.end()) {
		return i->second;
	}
	Node *node = new Node;
	nodemap[cur] = node;
	node->ptr1 = copyRe(cur->ptr1, nodemap);
	node->ptr2 = copyRe(cur->ptr2, nodemap);
	return node;
}


Node* copyStructure(Node* root) {
	NodeMap nodemap;
	return copyRe(root, nodemap);
}
