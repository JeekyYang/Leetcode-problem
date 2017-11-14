bool isScramble(string s1, string s2) {
	if(s1 == s2) {
		return true;
	}

	if(s1.length() != s2.length()) {
		return false;
	}

	int len = s1.length();
	vector<int> a(26, 0)
	for(int i = 0; i < len; i++) {
		a[s1[i]-'a']++;
		a[s2[i]-'a']--;
	}
	for(int i = 0; i < 26; i++) {
		if(a[i] != 0) {
			return false;
		}
	}

	for(int i = 1; i < len; i++) {
		if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
			return true;
		}
	
		if(isScramble(s1.substr(0, i), s2.substr(l-i)) && isScramble(s1.substr(i), s2.substr(0, i))) {
			return true;
		}
	}
	return false;
}
