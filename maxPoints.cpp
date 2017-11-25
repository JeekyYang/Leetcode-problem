class Point {
	int x;
	int y;
	Point():x(0),y(0){}
	Point(int a, int b):x(a), y(b){}
}

int gcd(int a, int b) {
	return	b == 0? a:gcd(b, a%b);
}
int maxPoints(vector<Point> &points) {
	const int n = points.size();
	int ans = 0;
	for(int i = 0; i < n; i++) {
		map<pair<int, int>, int> m;
		int dup = 1;
		for(int j = i+1; j < n; j++) {
			if(points[i].x == points[j].x && points[i].y == points[j].y) {
				dup++;
				continue;
			}
			int dx = points[j].x - points[i].x;
			int dy = points[j].y - points[i].y;
			int d = gcd(dx, dy);

			m[make_pair(dx/d, dy/d)]++;
		}
		ans = max(ans, dup);
		for(auto &a:m) {
			ans = max(ans, a.second+dup);
		}
	}
	return ans;
}
