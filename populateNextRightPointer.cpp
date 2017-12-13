class TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int v):val(v),left(nullptr), right(nullptr),next(nullptr){}
};

void connect(TreeLinkNode *root) {
	if(nullptr == root) return nullptr;
	queue<TreeLinkNode *> qe;
	qe.push(root);
	qe.push(nullptr);
	TreeLinkNode *p = nullptr;
	while(!qe.empty()) {
		TreeLinkNode *cur = qe.front();
		if(cur) {
			if(p) p->next = cur;
			p = cur;
			if(cur->left) qe.push(cur->left);
			if(cur->right) qe.push(cur->right);
		} else {
			if(!qe.empty()) {
				qe.push(nullptr);
				p = nullptr;
			}
		}
	}
}
