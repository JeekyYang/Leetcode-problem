int twoSum(vector<int> &nums, int target) {
	const int n = nums.size();
	vector<int> result(2, -1);

	unordered_map<int, int> used;
	unordered_map<int, int> dup;

	for(int i = 0; i < n; i++) {
		if (used.find(nums[i]) == used.end()) {
			used[nums[i]] = i;
		} else {
			dup[nums[i]] = i;
		}
	}

	for(int i = 0; i < n; i++) {
		if (used.find(nums[i]) == used.end()) {
			continue;
		}

		int other = target - nums[i];
		used.erase(nums[i]);

		if (dup.find(other) != dup.end()) {
			result[0] = i;
			result[1] = dup[other];
			break;
		}

		if (used.find(other) != used.end()) {
			result[0] = i;
			result[1] = used[other];
			break;
		}
	}
	
	return result;
}
