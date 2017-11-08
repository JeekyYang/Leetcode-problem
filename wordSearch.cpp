bool wordSearch(vector<vector<char>> &board, string word) {
	if(board.empty()) {
		return false;
	}

	vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
	return solve(board, visited, word, 0);
}

bool solve(vector<vector<char>> &board, vector<vector<bool>> &visited, string word, int start) {
	for(int i = 0; i < board.size(); i++) {
		for(int j = 0; j < board[0].size(); j++) {
			if(board[i][j] == word[start] && dfs(board, visited, word, i, j, start)) {
				return true;
			}
		}
	}
	return false;
}

void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, string word, int x, int y, int start) {
	if(start == word.size()) {
		return true;
	}
	if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
		return false;
	}

	if(visited[x][y] || board[x][y] != word[start]) {
		return false;
	}

	visited[x][y] = true;

	if(dfs(board, visited, word, x-1, y, start+1)) {
		return true;
	}
	if(dfs(board, visited, word, x+1, y, start+1)) {
		return true;
	}
	if(dfs(board, visited, word, x, y-1, start+1)) {
		return true;
	}
	if(dfs(board, visited, word, x, y+1, start+1)) {
		return true;
	}
	visited[x][y] = false;
	return false;
}
