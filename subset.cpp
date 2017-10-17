vector<vector<int>> subset(vector<int> &nums) {
	vector<vector<int>> ans;
	const int n = nums.size();
	if(0 == n) return ans;
	dfs(ans, nums, tmp, 0);
	return ans;
}

void dfs(vector<vector<int>> &ans, vector<int> &nums,  vector<int> &tmp, int start) {
	if(start == nums.size()) {
		ans.push_back(tmp);
		return;
	}

	tmp.push_back(nums[start]);
	dfs(ans, nums, tmp, start+1);
	tmp.pop_back();
	dfs(ans, nums, tmp, start+1);
}
