double findMedian(int A[], int m, int B[], int n) {
	int total = m+n;
	if (total & 0x1) {
		return double(findKth(A, m, B, n, (total+1)/2));
	} else {
		return 0.5 * double(findKth(A, m, B, n, total/2) + findKth(A, m, B, n, total/2+1));
	}
}

int findKth(int A[], int m, int B[], int n, int k) {
	if (0 == m) return B[k-1];
	if (0 == n) return A[k-1];

	int ia = min(m, k/2);
	int ib = n - ia;

	if (A[ia-1] < B[ib-1]) {
		return findKth(A+ia, m-ia, B, n, k-ia);
	} else if (A[ia-1] > B[ib-1]) {
		return findKth(A, m, B+ib, n-ib, k-ib);
	} else {
		return A[ia-1];
	}
}
