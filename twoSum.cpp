vector<int> twoSum(vector<int> &nums, int target) {
	const int n = nums.size();
	vector<int> ans(2, -1);
	
	if (n < 2) return ans;

	unordered_map<int, bool> used;
	unordered_map<int, bool> dup;

	for(int i = 0; i < n; i++) {
		if (used.find(nums[i]) == used.end()) {
			used[nums[i]] = i;
		} else {
			dup[nums[i]] = i;
		}
	}

	for(int i = 0; i < n; i++) {
		if (used[nums[i]]) continue;

		used.erase(nums[i]);
		int other = target - nums[i];

		if (dup.find(other) != dup.end()) {
			ans[0] = i;
			ans[1] = dup[other];
			break;
		}

		if (used.find(other) != used.end()) {
			ans[0] = i;
			ans[1] = dup[other];
			break;
		}
	}

	return ans;
}
