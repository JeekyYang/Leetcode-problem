int cuts(string s) {
	if(s.empty()) {
		return 0;
	}
	const int n = s.size();
	vector<int> f(n+1, n-1);
	f[0] = -1;
	f[1] = 0;
	for(int i = 2; i <= n; i++) {
		f[i] = f[i-1] + 1;
		for(int j = i-1; i >= 0; j--) {
			string str = s.substr(s, j, i-j+1);
			if(isPalindrome(str) && f[j] + 1 < f[i]) {
			 	f[i] = f[j] + 1;
			}
		}
	}
	return f[n];
}

bool isPalindrome(string s) {
	if(s.empty()) {
		return true;
	}
	int first = 0, last = s.size()-1;
	while(first < last) {
		if(s[first] != s[last]) {
			return false;
		}
		first++;
		last--;
	}
	return true;
}
