vector<vector<int>> generate(int numRows) {
	vector<vector<int>> ans;
	if(numRows <= 0) {
		return ans;
	}

	ans.push_back(vector<int>(1,1));
	for(int i = 2; i <= numRows; i++) {
		vector<int> res(1,1);
		for(int j = 0; j < ans[i-2].size()-1; i++) {
			res.push_back(ans[i-2][j]+ans[i-2][j+1]);
		}
		res.push_back(1);
		ans.push_back(res);
	}
	return ans;
}
