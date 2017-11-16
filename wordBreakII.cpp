vector<string> worBreak(string s, vector<string> wordDict) {
	if(s.empty()) {
		return vector<string>();
	}

	unordered_set<string> dict(wordDict.begin(), wordDict.end());
	vector<string> ans;
	vector<string> tmp;
	dfs(ans, tmp, s, dict, 0);
	return ans;
}

void dfs(vector<string> &ans, vector<string> &tmp, string s, unordered_set<string> &dict, int start) {
	if(start == s.length()) {
		if(!tmp.empty()) {
			string res = tmp[0];
			for(int i = 1; i < tmp.size(); i++) {
				res += " ";
				res += tmp[i];
			}
			ans.push_back(res);
		}
		return;
	}

	int len = s.length()-start;
	for(int i = 1; i <= len; i++) {
		string sub = s.substr(start, i);
		if(dict.find(sub) != dict.end()) {
			tmp.push_back(sub);
			dfs(ans, tmp, s, dict, start+i);
			tmp.pop_back();
		}
	}
}
