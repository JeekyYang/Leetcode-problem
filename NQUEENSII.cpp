int NQUEENSII(int n) {
	if(n <= 0) {
		return 0;
	}

	vector<int> tmp;
	int ans = 0;
	dfs(ans, tmp, n, 0);
	return ans;
}

void dfs(int &ans, vector<int> &tmp, int n, int start) {
	if(start == n) {
		ans++;
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

bool isAvailable(vector<int> &tmp, int row, int candidate) {
	for(int i = 0; i < tmp.size(); i++) {
		if(candidate == tmp[i] || abs(i-row) == abs(candidate-tmp[i])) {
			return false;
		}
	}
	return true;
}
