vector<vetor<int>> combinationSum(vector<int> &candidates, int target) {
	if(candidates.empty()) {
		return vector<vector<int>>();
	}

	vector<int> tmp;
	vector<vector<int>> ans;
	dfs(ans, tmp, candidates, target, 0);
	return ans;
}

void dfs(vector<vector<int>> &ans, vector<int> &tmp, vector<int> &candidates, int target, int start) {
	if(target == 0) {
		ans.push_back(tmp);
		return;
	}

	if(target < 0) {
		return;
	}

	for(int i = start; i < candidates.size(); i++) {
		tmp.push_back(candidates[i]);
		dfs(ans, tmp, candidates, target-candidates[i], i);
		tmp.pop_back();
	}
}
