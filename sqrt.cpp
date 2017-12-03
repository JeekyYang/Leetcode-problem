int mySqrt(int x) {
	if(0 == x || 1 == x) {
		return x;
	}
	int ans = 1;
	for(int i = 1; i < x; i++) {
		int tmp = x/i;
		if(i < tmp) {
			ans = i;	
		} else if(i > tmp) {
			break;
		} else {
			return i;
		}
	}
	return ans;
}

//divide conquer
int mySqrt(int x) {
	if(0 == x || 1 == x) {
		return x;
	}
	return helper(x, 1, x);
}

int helper(int x, int start, int end) {
	int mid = start + (end-start)/2;
	if(start == mid) {
		return mid;
	}

	int tmp = x/mid;
	if(mid < tmp) {
		return helper(x, mid, end);
	} else if(mid > tmp) {
		return helper(x, start, mid);
	} else {
		return mid;
	}
}

//binary search
int sqrt(int x) {
	if(0 == x) return 0;
	if(x < 4) return 1;
	int start = 0, end = x/2;
	while(start < end) {
		int mid = start + (end-start+1)/2;
		if(x/mid == mid) return mid;
		else if(x/mid > mid) {
			start = mid;
		} else {
			end = mid-1;
		}
	}
	return start;
}
