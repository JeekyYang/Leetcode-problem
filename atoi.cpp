int myAtoi(string s) {
	const int n = s.length();
	int ans = 0;
	int index = 0;
	while(s[index] == ' ') index++;
	
	int sign = 1;
	if(s[index] == '-') {
		sign = -1;
		index++;
	} else if(s[index] == '+') {
		index++;
	}

	while(index < n) {
		if(s[index] < '0' || s[index] > '9') break;

		if(ans > INT_MAX/10 || (ans == INT_MAX && (INT_MAX%10 < s[index]-'0'))) {
			return sign == -1? INT_MIN:INT_MAX;
		}

		ans = ans*10 + s[i]-'0';
		index++;
	}

	return sign*ans;
}
