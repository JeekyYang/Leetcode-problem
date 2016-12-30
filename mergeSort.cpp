void merge(int A[], int p, int q, int r) {
	int len1 = q-p+1;
	int len2 = r-q;

	vector<int> left(len1+1);
	vector<int> right(len2+1);

	left[len1] = right[len2] = INT_MAX;

	for(int i = 0; i < len1-1; i++) {
		left[i] = A[p+i];
	}
	for(int j = 0; j < len2-1; j++) {
		right[j] = A[q+1+j];
	}

	int i=j=0;
	for(int k = p; k < r+1; k++) {
		if (left[i] < right[j]) {
			A[k] = left[i++];
		} else {
			A[k] = right[j++];
		}
	}
}

void msort(int A[], int p, int r) {
	if (p < r) {
		int q = p + (r-p)/2;
		msort(A, p, q);
		msort(A, q+1, r);
		merge(A, p, q, r);
	} 
}
