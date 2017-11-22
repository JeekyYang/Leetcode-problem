vector<int> generate(int rowIndex) {
	vector<int> ans;
	if(rowIndex < 0) {
		return ans;
	}
	ans.push_back(1);
	for(int i = 1; i <= rowIndex; i++) {
		vector<int> tmp(1,1);
		for(int j = 0; j < ans.size()-1; j++) {
			tmp.push_back(ans[j] + ans[j+1]);
		}
		tmp.push_back(1);
		ans = tmp;
	}
	return ans;
}
