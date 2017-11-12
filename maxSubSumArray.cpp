int maxSumOfSubArray(vector<int> &nums) {
	int thisSum = nums[0];
	int maxSum = nums[0];
	
	for(int i = 1; i < nums.size(); i++) {
		if(thisSum < 0) {
			thisSum = nums[i];
		} else {
			thisSum += nums[i];
		}
		maxSum = max(maxSum, thisSum);
	}
	return maxSum;
}
