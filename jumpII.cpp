int jump(vector<int> &nums) {
	if(nums.empty()) {
		return -1;
	}
	if(nums.size()==1) {
		return 0;
	}
	int target = nums.size()-1;
	int most = nums[0];
	int curMost = most;
	int step = 1;
	for(int i = 1; i < nums.size(); i++) {
		if(i > most) {
			step++;
			most = curMost;
		}

		if(i+nums[i] >= target) {
			return step+1;
		}

		if(i+nums[i] > curMost) {
			curMost = i+nums[i];
		}
	}
	return -1;
}
