string longestPalindromicSubstring(string s) {
	const int n = s.length();
	if(0 == n || 1 == n) return s;

	vector<vector<bool>> f(n, vector<bool>(n, false));

	for(int i = 0; i < n; i++) {
		f[i][i] = true;
	}

	int start = 0;
	int maxLen = 1;

	for(int i = 0; i < n; i++) {
		for(int j = i-1; j >= 0; j--) {
			if(s[i]==[j] && (i-j == 1 || f[j+1][i-1])) {
				f[j][i] = true;
				if(i-j+1 > maxLen) {
					start = i;
					maxLen = i-j+1;
				}
			}
		}
	}
	return s.substr(start, maxLen);
}
