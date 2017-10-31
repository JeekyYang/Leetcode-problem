vector<vector<string>> palindrome(string s) {
	if(s.empty()) {
		return vector<vector<string>>();
	}

	vector<vector<string>> ans;
	vector<string> tmp;
	dfs(ans, tmp, s, 0);
	return ans;
}

void dfs(vector<vector<string>> &ans, vector<string> &tmp, string s, int start) {
	if(start == s.size()) {
		ans.push_back(tmp);
		return;
	}

	for(int i = start; i < s.size(); i++) {
		string str = s.substr(start, i-start+1);
		if(isPalindrome(str)) {
			tmp.push_back(str);
			dfs(ans, tmp, s, i+1);
			tmp.pop_back();
		}
	}
}

bool isPalindrome(string &s) {
	if(s.empty()) {
		return true;
	}
	int first = 0, last = s.size();
	while(first < last) {
		if(s[first] != s[last]) {
			return false;
		}
		first++;
		last--;
	}
	return true;
}
