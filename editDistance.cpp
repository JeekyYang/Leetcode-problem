int editDistance(string word1, string word2) {
	const int m = word1.length();
	const int n = word2.length();

	vector<vector<int>> f(m+1, vector<int>(n+1, 0));
	for(int i = 0; i <= m; i++) {
		f[i][0] = i;
	}
	for(int j = 0; j <= n; j++) {
		f[0][j] = j;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(word1[i-1] == word2[j-1]) {
				f[i][j] = f[i-1][j-1];
			} else {
				int mn = min(f[i-1][j],f[i][j-1]);
				f[i][j] = 1 + min(f[i-1][j-1], mn);
			}
		}
	}
	return f[m][n];
}
