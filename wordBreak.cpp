bool wordBreak(string s, vector<string> &wordDict) {
	unordered_set<string> dict(wordDict.begin(), wordDict.end());
	const int n = s.length();
	vector<bool> f(n+1, false);
	f[0] = true;
	for(int i = 1; i <= n; i++) {
		for(int j = i-1; j >= 0; j--) {
			if(f[j]) {
				string tmp = s.substr(j, i-j);
				if(dict.find(tmp) != dict.end()) {
					f[i] = true;
					break;
				}
			}
		}
	}
	return f[n];
}
