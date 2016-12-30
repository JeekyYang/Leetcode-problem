int remove(int A[], int n, int k) {
	if (n < k+1) {
		return n;
	}

	int index = k;
	for(int i = k; i < n; i++) {
		if (A[i] != A[i-k]) {
			A[index++] = A[i];
		}
	}
	return index;
}
