int divide(int dividend, int divisor) {
	long long dividend >= 0? dividend:-(long long)dividend;
	long long divisor >= 0? divisor:-(long long)divisor;

	long long ans = 0;
	while(a >= b) {
		long long c = b;
		for(int i = 0; a >= c; i++) {
			a -= c;
			ans += 1<<i;
			c = c<<1;
		}
	}
	ans = (dividend^divisor)>>31? -ans:ans;
	return (ans > INT_MAX || ans < INT_MIN)? INT_MAX:ans;
}
