int minimumTotal(vector<vector<int>> &triangle) {
	const int m = triangle.size();
	const int n = triangle[m-1].size();
	for(int i = 1; i < triangle[i].size(); i++) {
		vector<int> tmp(triangle[i-1].begin(), triangle[i-1].end());
		for(int j = 0; j < triangle[i].size(); j++) {
			int adj0 = j-1 < 0? 0:j-1;
			int adj1 = j == triangle[i].size()-1? j-1:j;
			triangle[i][j] = min(tmp[adj0], tmp[adj1]) + triangle[i][j];
		}
	}

	int ans = triangle[m-1][0];
	for(int i = 1; i < n; i++) {
		if(triangle[m-1][i] < ans) {
			ans = triangle[m-1][i]
		}
	}
	return ans;
}
