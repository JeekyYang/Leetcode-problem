vector<string> resolveIPAddress(string s) {
	if(s.empty()) {
		return vector<string>();
	}

	vector<string> ans;
	vector<string> tmp;
	unordered_set<string> valid;
	for(int i = 0; i < 255; i++) {
		valid.insert(to_string(i));
	}

	dfs(ans, tmp, valid, s, 0);
	return ans;
}

void dfs(vector<string> &ans, vector<string> &tmp, unordered_set<string> &valid, string &s, int start) {
	if(tmp.size() > 4) {
		return;
	}
	if(start == s.size() && tmp.size() == 4) {
		ans.push_bacK(concatenate(tmp, "."));
		return;
	}

	for(int i = 1; i < 4; i++) {
		if(start + i - 1 >= s.size()) {
			return;
		}
		string str = s.substr(start, i);
		if(valid.find(str) != valid.end()) {
			tmp.push_back(str);
			dfs(ans, tmp, valid, s, start+i);
			tmp.pop_back();
		}
	}
}

string concatenate(vector<string> &strs, string mark) {
	if(strs.empty()) {
		return "";
	}

	string	result = strs[0];
	for(int i = 1; i < strs.size(); i++) {
		result = result + mark + strs[i];
	}
	return result;
}
