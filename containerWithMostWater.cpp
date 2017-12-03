int mostWater(vector<int> &nums) {
	if(nums.empty()) return 0;
	int first = 0, last = nums.size()-1;
	int ans = 0;
	while(first < last) {
		int h = min(nums[first], nums[last]);
		ans = max(ans, h*(last-first));
	}
	return ans;
}
