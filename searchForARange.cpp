vector<int> searchRange(vector<int> &A, int target) {
	vector<int> ans(2, -1);
	const int n = A.size();
	if(n == 0) return ans;

	int first = 0, last = n-1;
	while(first < last) {
		int mid = first + (last-first)/2;
		if(A[mid] > target) {
			first = mid+1;
		} else {
			last = mid;
		}
	}

	if(target == A[first]) {
		ans[0] = first;
	}

	last = n-1;
	while(first < last) {
		int mid = first + (last-first+1)/2;
		if(A[mid] > target) {
			last = mid-1;
		} else {
			first = mid;
		}
	}

	if(target == A[last]) {
		ans[1] = last;
	}

	return ans;
}
