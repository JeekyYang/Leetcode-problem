vector<string> generate(int n) {
	if(0 == n) {
		return vector<string>();
	}

	vector<string> ans;
	string tmp = "";
	dfs(ans, tmp, n, n);
	return ans;
}

void dfs(vector<string> &ans, string tmp, int left, int right) {
	if(right == 0) {
		ans.push_back(tmp);
		return;
	}

	if(left == 0) {
		dfs(ans, tmp+")", left, right-1);
		return;
	}

	if(left < right) {
		dfs(ans, tmp+ ")", left, right-1);
	}
	dfs(ans, tmp+"(", left-1, right);
}
