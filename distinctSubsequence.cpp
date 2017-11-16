int numDistinct(string s, string t) {
	if(s.length() < t.length()) {
		return 0;
	}

	const int n = t.length();
	vector<int> f(n+1);
	f[0] = 1;
	for(int i = 0; i < s.size(); i++) {
		for(int j = n-1; j >= 0; j--) {
			f[j+1] = s[i] == t[j]? f[j]:0;
		}
	}
	return f[n];
}
