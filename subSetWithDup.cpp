//the input with duplication
vector<vector<int>> subsetsWtihDup(vetor<int> &nums) {
	vector<vector<int>> ans;
	const int n = nums.size();
	//corner case
	if(0 == n) return ans;

	//sort the input
	sort(nums.begin(), nums.end());

	vector<bool> used(nums.size(), false);
	dfs(ans, nums, tmp, used, 0);
	return ans;
}

void dfs(vector<vector<int>> &ans, vector<int> &nums, vector<int> &tmp, vector<bool> used, int start) {
	//end
	if(start == nums.size()) {
		ans.push_back(tmp);
		return;
	}

	if(start > 0 && nums[start] == nums[start-1] && !used[start]) {
		dfs(ans, nums, tmp, used, start+1);
	} else {
		tmp.push_back(nums[start]);
		dfs(ans, nums, tmp, used, start+1);
		tmp.pop_back();
		dfs(ans, nums, tmp, used, start+1);
	}
}
