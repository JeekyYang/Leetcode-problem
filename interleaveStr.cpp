bool isInterleave(string s1, string s2, string s3) {
	const int len1 = s1.length();
	const int len2 = s2.length();
	const int len3 = s3.length();

	if(len1 + len2 != len3) {
		return false;
	}

	vector<vector<bool>> dp(len1+1, vector<bool>(len2+1, false));
	dp[0][0] = true;
	for(int i = 1; i < len1+1; i++) {
		if(s1[i-1] == s3[i-1] && dp[i-1][0]) {
			dp[i][0] = true;
		}
	}
	for(int i = 1; i < len2+1; i++) {
		if(s2[i-1] == s3[i-1] && dp[i-1][0]) {
			dp[0][i] = true;
		}
	}

	for(int i = 1; i < len1+1; i++) {
		for(int j = 1; j < len2+1; j++) {
			if(s1[i-1] == s3[i+j-1] && dp[i-1][j]) {
				dp[i][j] = true;
			}
			if(s2[j-1] == s3[i+j-1] && dp[i][j-1]) {
				dp[i][j] = true;
			}
		}
	}
	return dp[len1][len2];
}
