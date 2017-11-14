int maxProfit(vector<int> &prices) {
	if(prices.size() < 2) {
		return 0;
	}

	const int n = prices.size();
	vector<int> f(n, 0);
	vector<int> g(n, 0);

	int curMin = prices[0];
	for(int i = 1; i < n; i++) {
		curMin = min(prices[i], curMin);
		f[i] = max(f[i-1], prices[i]-cirMin);
	}

	int curMax = prices[n-1];
	for(int i = n-2; i >= 0; i--) {
		curMax = max(prices[i], curMax);
		g[i] = max(g[i+1], curMax-prices[i]);
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans = max(ans, f[i] + g[i]);
	}
	return ans;
}
