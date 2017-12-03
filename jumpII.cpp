int jump(vector<int> &nums) {
	if(nums.empty() || nums.size() == 1) return 0;

	const int n = nums.size();
	if(nums[0] >= n-1) return 1;

	int most = nums[0], cur = most;
	int steps = 1;
	for(int i = 1; i < n; i++) {
		if(i > most) {
			steps++;
			most = cur;
		}
		if(i+nums[i] >= n-1) return steps+1;
		cur = max(cur, nums[i]+i);
	}
	return steps;
}
