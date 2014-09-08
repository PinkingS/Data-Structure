struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
}

typedef UndirectedGraphNode GraphNode;
typedef map<GraphNode*, GraphNode *> MAP;

GraphNode *cloneGraphRe(GraphNode *node, MAP &map) {
	if(!node) return NULL;
	if(map.find(node) != map.end()) // has built
		return map[node];
	GraphNode *newNode = new GraphNode(node->label);
	map[node] = newNode;
	for(int i = 0; i < node->neighbors.size(); ++i) {
		newNode->neighbors.push_back(cloneGraphRe(node->neighbors[i], map));
	}
	return newNode;
}

UndirectedGraphNode* cloneGraph(UndirectedGraphNode *node) {
	MAP map;
	return cloneGraphRe(node, map);
}

UndirectedGraphNode* cloneGraph_BFS(UndirectedGraphNode *node) {
	MAP map;
	queue<GraphNode*> q;
	if(!node) return NULL;
	map[node] = new GraphNode(node->label);
	q.push(node);
	while(!q.empty()) {
		GraphNode *originNode = q.front();q.pop();
		GraphNode *newNode = map[originNode];
		for(int i = 0; i < originNode->neighbors.size(); ++i) {
			GraphNode *originNeibor = originNode->neighbors[i];
			if(map.find(originNeibor) != map.end()) {
				newNode->neighbors.push_back(map[originNeibor]);
				continue;
			}
			GraphNode *newNeibor = new GraphNode(originNeibor->label);
			map[originNeibor] = newNeibor;
			q.push(originNeibor);
			newNode->neighbors.push_back(newNeibor);
		}
	}
	return map[node];
}
