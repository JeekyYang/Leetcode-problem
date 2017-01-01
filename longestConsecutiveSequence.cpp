int longestConsecutiveSequence(vector<int> &A) {
	const int n = A.size();
	if (n < 2) return n;
	ordered_map<int, bool> used;
	for(int i = 0; i < n; i++) {
		used[nums[i]] = false;
	}

	int result = 1;
	for(int i = 0; i < n; i++) {
		if (used[nums[i]]) continue;

		int ans = 1;
		used[nums[i]] = true;
		
		int data = nums[i] + 1;
		while(used.find(data) && !used[data]) {
			used[data] = true;
			data++;
			ans++;
		}

		data = nums[i] - 1;
		while(used.find(data) != used.end() && !used[data]) {
			used[data] = true;
			data--;
			ans++
		}

		result = ans > result? ans:result;
	}
	return result;
}	
