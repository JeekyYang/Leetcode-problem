bool validBST(TreeNode *root) {
	if(nullptr == root) return true;
	stack<TreeNode *> st;
	unordered_set<TreeNode *> s;
	st.push(root);
	s.insert(root);
	while(!st.empty()) {
		TreeNode *cur = st.top();
		if(cur->left && s.find(cur->left) == s.end()) {
			st.push(cur->left);
			s.insert(cur->left);
		} else {
			st.pop();
			if(pre && pre->val > cur->val) return false;
			pre = cur;
			if(cur->right) {
				st.push(cur->right);
				s.insert(cur->right);
			}
		}
	}
	return true;
}
