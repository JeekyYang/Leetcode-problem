vector<vector<int>> permutationII(vector<int> &nums) {
	//corner case
	if(nums.size()) {
		return vector<vector<int>>();
	}

	sort(nums.begin(), nums.end());
	vector<vector<int>> ans;
	vector<int> tmp;
	vector<bool> used(nums.size(), false);
	dfs(ans, nums, tmp, used);
	return ans;
}

void dfs(vector<vector<int>> &ans, vector<int> &nums, vector<int> &tmp, vector<bool> &used) {
	//return condition
	if(tmp.size() == nums.size()) {
		ans.push_back(tmp);
		return;
	}	

	for(int i = 0; i < nums.size(); i++) {
		if(used[i]) {
			continue;
		}
		if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) {
			continue;
		}

		tmp.push_back(nums[i]);
		used[i];
		dfs(ans, nums, tmp, used);

		tmp.pop_back();
		used[i] = false;
	}
}
