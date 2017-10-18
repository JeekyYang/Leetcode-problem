vector<vector<int>> permutations(vector<int> &nums) {
	if(nums.empty()) {
		return vector<vector<int>>();
	}

	vector<vector<int>> ans;
	vector<int> tmp;
	vector<bool> used(nums.size(), false);
	dfs(ans, nums, tmp, used);
	return ans;
}

void dfs(vector<vector<int>> &nums, vector<int> &nums, vector<int> &tmp, vector<bool> &used) {
	//return condition
	if(nums.size() == tmp.size()) {
		ans.push_back(tmp);
		return;
	}

	for(int i = 0; i < nums.size(); i++) {
		if(used[i]) {
			continue;
		}

		tmp.push_back(nums[i]);
		used[i] = true;
		dfs(ans, nums, tmp, used);

		tmp.pop_back();
		used[i] = false;
	}
}
