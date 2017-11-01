int cuts(string s) {
	if(s.empty()) {
		return 0;
	}

	const int n = s.size();
	vector<vector<bool>> check(n, vector<bool>(n, false));
	
	vector<int> f(n+1);
	for(int i = 0; i < n+1; i++) {
		f[i] = i-1;
	}

	for(int i = 2; i <= n; i++) {
		for(int j = i-1; j >= 0; j--) {
			if(s[j] == s[i-1] && (i-1-j < 2 || check[j+1][i-2])) {
				f[i] = min(f[i], f[j] + 1);
				check[j][i-1] = true;
			}
		}
	}
	return f[n];
}

