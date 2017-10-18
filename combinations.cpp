vector<vector<int>> combinations(int n, int k) {
	//corner case
	if(n == 0) {
		return vector<vector<int>>();
	}

	vector<int> tmp;
	vector<vector<int>> ans;
	dfs(ans, tmp, n, k);
	return ans;
}

void dfs(vector<vector<int>> &ans, vector<int> &tmp, int n, int k) {
	//return condition
	if(tmp.size() == k) {
		ans.push_back(tmp);
		return;
	}

	int start = 0;
	if(!tmp.empty()) {
		start = tmp[tmp.size()-1];
	}
	for(int i = start+1; i <= n; i++) {
		tmp.push_back(i);
		dfs(ans, tmp, n, k);
		tmp.pop_back();
	}
}
