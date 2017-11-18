bool isPalindromeNumber(int x) {
	if(x < 0) {
		return false;
	}

	int tmp = x;
	int ans = 0;
	while(tmp != 0) {
		ans = ans*10 + tmp%10;
		if(ans < 0) {
			return false;
		}
		tmp = tmp/10;
	}
	return ans == x;
}
