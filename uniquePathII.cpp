int uniquePathII(vector<vector<int>> &graph) {
	if(graph.empty()) {
		return 0;
	}
	const int m = graph.size();
	if(graph[0].empty()) {
		return 0;
	}

	vector<vector<int>> f(m, vector<int>(n, 0));
	f[0][0] = graph[0][0] == 1? 0:1;
	for(int i = 1; i < m; i++) {
		f[i][0] = graph[i][0] == 1? 0:f[i-1][0];
	}
	for(int j = 1; j < n; j++) {
		f[0][j] = graph[0][j] == 1? 0:f[0][j-1];
	}

	for(int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++) {
			f[i][j] = graph[i][j] == 1? 0:f[i-1][j] + f[i][j-1];
		}
	}
	return f[m-1][n-1];
}
