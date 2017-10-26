const string mp[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> letterCombination(string digits) {
	//corner case
	if(digits.empty()) {
		return vector<string>();
	}

	const int n = digits.size();

	vector<string> ans;
	string tmp;
	dfs(ans, tmp, digits, 0);
	return ans;
}

void dfs(vector<string> &ans, string tmp,string digits, int start) {
	//return
	if (start == digits.size()) {
		ans.push_back(tmp);
		return;
	}

	int index = digits[start]-'0';
	for(int i = 0; i < mp[index].size(); i++) {
		tmp.push_back(mp[index][i]);
		dfs(ans, tmp, digits, start+1);
		tmp.pop_back();
	}
}
