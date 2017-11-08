void solve(vector<vector<char>> &board) {
	dfs(board);
	return;
}

bool dfs(vector<vector<bool>> &board) {
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j< 9; j++) {
			if(board[i][j] != '.') {
				continue;
			}
			for(int k = 0; k < 9; k++) {
				board[i][j] = k+'1';
				if(isValid(board, i, j) && dfs(board)) {
					return true;
				}
				board[i][j] = '.';
			}
			return false;
		}
	}
	return true;// this line is easy to be fogot
}

bool isValid(vector<vector<char>> &board, int row, int col) {
	for(int i = 0; i < 9; i++){
		if(i != row && board[i][col] == board[row][col]) {
			return false;
		}
	}

	for(int j = 0; j < 9; j++) {
		if(j != col && board[row][j] != board[row][col]) {
			return false;
		}
	}

	int r = row/3, c = col/3;
	for(int i = r*3; i < (r+1)*3; i++) {
		for(int j = c*3; j < (c+1)*3; j++) {
			if(i != row && j != col && board[i][j] == board[row][col]) {
				return false;
			}
		}
	}
	return true;
}
