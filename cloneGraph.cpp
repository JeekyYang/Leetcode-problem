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
