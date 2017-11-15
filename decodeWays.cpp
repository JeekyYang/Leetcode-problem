int decodeWays(string s) {
	if(s.empty() || s[0] == '0') {
		return 0;
	}

	const int n = s.size();
	vector<int> f(n+1, 1);
	for(int i = 2; i <= n; i++) {
		if(s[i-1] != '0') {
			f[i] += f[i-1];
		}
		int num = (s[i-2]-'0')*10 + s[i-1]-'0';
		if(num >= 10 && num <= 26) {
			f[i] += f[i-2];
		}
	}
	return f[n];
}
