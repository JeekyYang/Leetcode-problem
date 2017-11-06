vector<vector<int>> combinationSumII(vector<int> &candidates, int target) {
	if(candidates.empty()) {
		return vector<vector<int>>();
	}

	vector<int> tmp;
	vector<vector<int>> ans;
	vector<bool> used(candidates.size(), false);
	sort(candidates.begin(), candidates.end());
	dfs(ans, tmp, candidates, used, target, 0);
	return ans;
}

void dfs(vector<vector<int>>&ans, vector<int>&tmp, vector<int> &candidates, vector<bool>&used, int target, int start) {
	if(target == 0) {
		ans.push_back(tmp);
		return;
	}

	for(int i = start; i < candidates.size(); i++) {
		if(candidates[i] > target) {
			return;
		}

		if(i > 0 && candidates[i] == candidates[i-1] && !used[i]) {
			continue;
		}

		tmp.push_back(tmp[i]);
		used[i] = true;
		dfs(ans, tmp, candidates, used, target-candidates[i], i+1);
		used[i] = false;
		tmp.pop_back();
	}
}
