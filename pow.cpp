double myPow(double x, int n) {
	if(n < 0) {
		return 1.0 / helper(x, -n);
	} else {
		return helper(x, n);
	}
}

double helper(double x, int n) {
	if (1 == n) {
		return x;
	}
	if(0 == n) {
		return 1;
	}

	double tmp = helper(x, n/2);
	if(n & 0x1) {
		return tmp*tmp*x;
	} else {
		return tmp*tmp;
	}
}
