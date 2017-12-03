int longestSubstring(string s) {
	const int n = s.size();
	if(n <= 1) return n;

	vector<int> f(128, 0);
	int start = 0, end = 0;
	while(end < n) {
		char c = s[end];
		f[c]++;
		if(f[c] > 1) {
			ans = max(ans, end-start);
		} else if(end == n-1) {
			ans = max(ans, end-start+1);
		}
		while(f[c] > 1) {
			f[s[start]]--;
			start++;
		}
	}
	return ans;
}
