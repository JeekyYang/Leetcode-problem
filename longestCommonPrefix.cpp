string longestCommonPrefix(vector<string> &strs) {
	if(strs.empty()) return "";
	string ans = strs[0];
	if(ans.empty()) return "";

	int len = 0;
	bool finished = false;
	for(int i = 0; i < ans.size(); i++) {
		for(int j = 1; j < strs.size(); j++) {
			if(i < strs[j].size() && ans[i] == strs[j][i]) continue;
			else {
				finished = true;
				break;
			}
		}
		if(finished) break;
		else len++;
	}
	return ans.substr(0, len);
}
