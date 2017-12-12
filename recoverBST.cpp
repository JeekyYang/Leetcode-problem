void recovery(TreeNode *root) {
	if(nullptr == root) return root;

	TreeNode *pre = nullptr, *p1 = nullptr, *p2 = nullptr;
	stack<TreeNode *> st;
	unordered_set<TreeNode *> traversed;
	st.push(root);
	traversed.insert(root);
	while(!st.empty()) {
		TreeNode *cur = st.top();
		if(cur->left && traversed.find(cur->left) == traversed.end()) {
			st.push(cur->left);
			traversed.insert(cur->left);
		} else {
			st.pop();
			if(pre && pre->val > cur->val) {
				if(!p1) p1 = pre;
				p2 = cur;
			}
			pre = cur;
			if(cur->right) {
				st.push(cur->right);
				traversed.insert(cur->right);
			}
		}
	}
	if(p1 && p2) swap(p1->val, p2->val);
}
