int threeSumClose(vector<int> &nums, int target) {
	const int n = nums.size();
	if (n < 3) return 0;

	int delta = INT_MAX;
	int ans = 0;

	sort(nums.begin(), nums.end());
	for(int i = 0; i < n; i++) {
		if (i > 0 && nums[i] == nums[i-1]) {
			continue;
		}

		int left = i+1;
		int right = n-1;
		while(left < right) {
			if (left > i+1 && nums[left] == nums[left-1]) {
				left++;
				continue;
			}
			if (right < n-1 && nums[right] == nums[right+1]) {
				right--;
				continue;
			}

			int sum = nums[i] + nums[left] + nums[right];
			int absolute = abs(sum-target);
			if (absolute < delta) {
				ans = sum;
				delta = absolute;
			}

			if (sum > target) {
				right--;
			} else if (sum < target) {
				left++;
			} else {
				return target;
			}
		}
	}
	return ans;
}
