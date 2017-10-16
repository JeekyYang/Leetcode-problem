//search lower and upper limit by binary search

int findLowerLimit(vector<int> &A, int target) {
	const int n = A.size();
	int first = 0, last = n-1;
	while(first < last) {
		int mid = first + (last-first)/2;
		if(A[mid] < target) {
			first = mid+1;
		} else {
			last = mid;
		}
	}
	if(target == A[first]) {
		return first;
	} else {
		return -1;//if not found, return -1
	}
}

int findUpperLimit(vector<int> &A, int target) {
	const int n = A.size();
	int first = 0, last = n-1;
	while(first < last) {
		int mid = first + (last-first+1)/2;
		if(A[mid] > target) {
			last = mid-1;
		} else {
			first = mid;
		}
	}

	if(target == A[last]) {
		return last;
	} else {
		return -1;//if not found, return -1
	}
}
