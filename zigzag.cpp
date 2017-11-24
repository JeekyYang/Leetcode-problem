string zigzag(string s, int rowNums) {
	if(rowNums <= 1) return s;

	vector<vector<char>> zig;
	const int n = s.length();
	for(int i = 0; i < n/(rowNums-1) + 1; i++) {
		int start = min(i*(rowNums-1), n-1);
		int end = min((i+1)*(rowNums-1), n-1);
		vector<char> tmp;
		if(i & 0x1) {
			for(int j = end; j >= start; j--) {
				tmp.push_back(s[j]);
			}
		} else {
			for(int j = start; j <= end; j++) {
				tmp.push_back(s[j]);
			}
		}
		zig.push_back(tmp);
	}

	string ans;
	for(int i = 0; i < rowNums; i++) {
		for(int j = 0; j < zig.size(); j++) {
			if(i < 0 || i >= zigp[j].size()) {
				continue;
			}

			if(i == 0) {
				if(j == 0 || (j & 0x1)) {
					ans.push_back(zig[j][i]);
				}
			} else if(i == rowNums-1) {
				if(!(j & 0x1)) {
					ans.push_back(zig[j][i]);
				}
			} else {
				ans.push_back(zig[j][i]);
			}
		}
	}
	return ans;
}
