//dfs
UndirectedGraphNode * cloneGraph(UndirectedGraphNode *node) {
	if(nullptr == node) {
		return nullptr;
	}

	unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> records;
	return clone(node, records);
}

UndirectedGraphNode *clone(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &records) {
	if(records.find(node) != records.end()) {
		return records[node];
	}

	UndirectedGraphNode * myNode = new UndirectedGraphNode(node->label);
	records[node] = myNode;
	for(auto nbr:node->neighbors) {
		myNode->neighbors.push_bach(clone(nbr, records));
	}
	return myNode;
}

//bfs

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if(nullptr == node) {
		return nullptr;
	}

	unordered_map<UndirectedGraphNode *,UndirectedGraphNode *> cloned;
	cloned[node] = new UndirectedGraphNode(node->label);
	queue<UndirectedGraphNode *> qe;
	qe.push(node);
	while(!qe.empty()) {
		UndirectedGraphNode *cur = qe.front();
		qe.pop();
		for(auto nbr:cur->neighbors) {
			if(cloned.find(nbr) != cloned.end()) {
				cloned[cur]->neighbors.push_back(cloned[nbr]);
			} else {
				UndirectedGraphNode *myNeighbor = new UndirectedGraphNode(nbr->label);
				cloned[nbr] = myNeighbor;
				cloned[cur]->neighbors.push_back(myNeighbor);
				qe.push(nbr);
			}
		}

	}
	return cloned[node];
}
