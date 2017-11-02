vector<vector<string>> solveNSolutions(int n) {
	if(n <= 0) {
		return vector<vector<string>>();
	}

	vector<vector<int>> ans;
	vector<int> tmp;
	dfs(ans, tmp, n, 0);

	vector<vector<string>> result;
	for(auto item:ans) {
		vector<string> solution
		for(auto s:item) {
			string str(n, '.');
			str[s] = 'Q';
			solution.push_back(str);
		}
		result.push_back(solution);
	}
	return result;
}

void dfs(vector<int> &ans, vector<int> &tmp, int n, int start) {
	if(start == n) {
		ans.push_back(tmp);
		return;
	}

	for(int i = 0; i < n; i++) {
		if(isAvailable(tmp, start, i)) {
			tmp.push_back(i);
			dfs(ans, tmp, n, start+1);
			tmp.pop_back();
		}
	}
}

bool isAvailable(vector<int> &f, int row, int candidate) {
	for(int i = 0; i < f.size(); i++) {
		if(f[i] == candidate || abs(row-i) == abs(candidate-f[i])) {
			return false;
		}
	}
	return true;
}
