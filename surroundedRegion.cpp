//dfs
void solve(vector<vector<int>> &board) {
	if(board.empty()) return;
	if(board[0].empty()) return;

	const int m = board.size();
	const int n = board[0].size();

	for(int i = 0; i < m; i++) {
		dfs(board, i, 0);
		dfs(board, i, n-1);
	}
	for(int j = 0; j < n; j++) {
		 dfs(board, 0, j);
		 dfs(board, m-1, j)
	}
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j] == 'o') {
				board[i][j] = 'x';
			} else if(board[i][j] = 'z') {
				board[i][j] = 'o';
			}
		}
	}
}
void dfs(vector<vector<char>> &board, int x, int y) {
	if(board[x][y] != 'o') return;
	board[x][y] = 'z';
	if(x-1 >= 0) dfs(board, x-1, y);
	if(x+1 < m) dfs(board, x+1, y);
	if(y-1 >= 0) dfs(board, x, y-1);
	if(y+1 < n) dfs(board, x, y+1);
}

//bfs
class Node {
	public:
		int x;
		int y;
		Node(int x0, int y0):x(x0),y(y0){}
};

void solve(vector<vector<char>> &board) {
	if(board.empty()) {
		return;
	}
	const int m = board.size();
	if(board[0].empty()) {
		return;
	}
	const int n = board[0].size();

	queue<Node> qe;
	vector<vector<char>> visited(vector<vector<bool>>(m, vector<bool>(n, false)));
	for(int i = 0; i < m; i++) {
		if(board[i][0] == 'o') {
			board[i][0] = 'z';
			visited[i][0] = true;
			qe.push(Node(i, 0));
		}
		if(board[i][n-1] == 'o') {
			board[i][n-1] = 'z';
			visited[i][n-1] = true;
			qe.push(Node(i, n-1));
		}
	}
	for(int j = 0; j < n; j++) {
		if(board[0][j] == 'o') {
			board[0][j] = 'z';
			visited[0][j] = true;
			qe.push(Node(0, j));
		}
		if(board[m-1][j] == 'o') {
			board[m-1][j] = 'z';
			visited[m-1][j] = true;
			qe.push(Node(m-1, j));
		}
	}

	while(!qe.empty()) {
		Node cur = qe.front();
		qe.pop();

		int x = cur.x;
		int y = cur.y;
		//up
		if(x-1 >= 0 && !visited[x-1][y] && board[x-1][y] == 'o') {
			board[x-1][y] = 'z';
			visited[x-1][y] = true;
			qe.push(Node(x-1, y));
		}
		//down
		if(x+1 < m && !visited[x+1][y] && board[x+1][y] == 'o') {
			board[x+1][y] = 'z';
			visited[x+1][y] = true;
			qe.push(Node(x+1, y));
		}
		//left

		if(y-1 >= 0 && !visited[x][y-1] && board[x][y-1] == 'o') {
			board[x][y-1] = 'z';
			visited[x][y-1] = true;
			qe.push(Node(x, y-1));
		}
		//right
		if(y+1 < n && !visited[x][y+1] && board[x][y+1] == 'o') {
			board[x][y+1] = 'z';
			visited[x][y+1] = true;
			qe.push(Node(x, y+1));
		}
	}

	for(int i =0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j] == 'o') {
				board[i][j] = 'x';
			} else if(board[i][j] == 'z') {
				board[i][j] = 'o'';
			}
		}
	}
}

