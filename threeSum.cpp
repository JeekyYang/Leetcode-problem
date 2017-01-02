vector<vector<int>> threeSum(vector<int> &nums, int target) {
	const int n = nums.size();
	vector<vector<int> > ans;

	if (n < 3) return ans;
	
	sort(nums.begin(), nums.end());

	for(int i = 0; i < n-2; i++) {
		if (i > 0 && nums[i] == nums[i-1]) continue;

		int left = i+1;
		int right = n-1;
		while(left < right) {
			if (left > i+1 && nums[left] == nums[left-1]) continue;
			if (right < n-1 && nums[right] == nums[right+1]) continue;

			int sum = nums[i] + nums[left] + nums[right];
			if (sum < 0) {
				left++;
			} else if (sum > 0) {
				right--;
			} else {
				ans.push_back({i, left, right});
			}
		}
	}

	return ans;
}
