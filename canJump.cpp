bool canJump(vector<int> &nums) {
	if(nums.empty()) {
		return false;
	}
	int des = nums[0];
	for(int i = 1; i < nums.size(); i++) {
		if(i > des) {
			return false;
		}
		des = nums[i]+i > des? nums[i]+i:des;
	}
	return true;
}
