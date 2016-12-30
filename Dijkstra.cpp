void Dijkstra(vector<vector<int>> &graph, int start) {
	const int n = graph.size();
	if (0 == n) {
		return;
	}

	vector<int> dist(n, INT_MAX);
	vector<int> p(n, -1);
	vector<int> s(n, false);

	dist[start] = 0;
	s[start] = true;

	for(int i = 0; i < n; i++) {
		if (!s[i] && graph[start][i]) {
			dist[i] = graph[start][i];
			p[i] = start;
		}
	}

	for(int i = 1; i < n; i++) {
		int mindist = INT_MAX;
		int x = start;

		for(int j = 0; j < n; j++) {
			if (!s[j] && dist[j] < mindist) {
				mindist = dist[j];
				x = j;
			}
		}
		s[x] = true;

		for(int j = 0; j < n; j++) {
			if(!s[j] && dist[j] > graph[x][j] + dist[x]) {
				dist[j] = graph[x][j] + dist[x];
				p[j] = x;
			}
		}
	}
}
