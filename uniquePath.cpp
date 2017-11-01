//time limit exceeded
int uniquePathCount(int m, int n) {
	if(m == 1 || m == 1) {
		return 1;
	}

	return uniquePath(m-1, n) + uniquePath(m, n-1);
}

//add cache
int uniquePaths(int m, int n) {
	vector<vector<int>> f(m+1, vector<int>(n+1, 0));
	return dfs(m, n, f);
}

int dfs(int m, int n, vector<vector<int>> &f) {
	if(m == 1 || n == 1) {
		return 1;
	}

	if(f[m][n] > 0) {
		return f[m][n];
	} else {
		f[m][n] = dfs(m-1, n, f) + dfs(m, n-1, f);
		return f[m][n];
	}

}

//dynamic programming
int uniquePath(int m, int n) {
	if(m == 0 || n == 0) {
		return 0;
	}
	if(m == 1 || n == 1) {
		return 1;
	}

	vector<vector<int>> f(m, vector<int>(n, 0));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(i == 0 || j ==0) {
				f[i][j] = 1;
			} else {
				f[i][j] = f[i-1][j] + f[i][j-1];
			}
		}
	}
	return f[m-1][n-1];
}
