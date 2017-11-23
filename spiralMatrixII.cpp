vector<vector<int>> generateMatrix(int n) {
	if(n <= 0) {
		return vector<vector<int>>();
	}

	vector<vector<int>> ans(n, vector<int>(n, 0));
	int t = 0, b = n-1, l = 0, r = n-1;
	int count = 1;
	while(t <= b && l <= r) {
		for(int i = l; i <= r; i++) {
			ans[t][i] = count++;
		}
		if(++t > b) break;

		for(int i = t; i <= b; i++) {
			ans[i][r] = count++;
		}
		if(--r < l) break;

		for(int i = r; i >= l; i--) {
			ans[b][i] = count++;
		}
		b--;

		for(int i = b; i >= t; i--) {
			ans[i][l] = count++;
		}
		l++;
	}
	return ans;
}
