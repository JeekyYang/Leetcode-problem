int maximalRectangel(vector<vector<char>>& matrix) {
	if(matrix.empty()) {
		return 0;
	}

	const int m = matrix.size();
	const int m = matrix[0].size();
	vector<vector<int>> d(m, vector<int>(n, 0));
	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(j == 0) {
				d[i][j] = matrix[i][0] == '1'? 1:0;
			} else {
				d[i][j] = matrix[i][j] == '1'? 1+d[i][j-1]:0;
			}
		}
	}

	int maxArea = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(d[i][j] == 0) {
				continue;
			}
			int width = d[i][j];
			int area = 0;
			for(int k = i; k >= 0; k--) {
				if(d[k][j] == 0) {
					break;
				}
				width = min(width, d[k][j]);
				area = max(area, width*(i-k+1));
			}
			maxArea = max(maxArea, area);
		}
	}
	return maxArea;
} 
