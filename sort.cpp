/*quick sort*/
int partition(int A[], int p, int r) {
	int i = p-1;
	int x = A[r];
	for (int j = p; j < r; j++) {
		if (A[j] < x) {
			swap(A[++i], A[j]);
	}

	swap(A[i+1], A[r]);
	return i+1;
}

void quickSort(int A[], int p, int r) {
	if (p < r) {
		int pivot = partition(A, p, r);
		quickSort(A, p, pivot-1);
		quickSort(A, pivot+1, r);
	}
}

/*max heap sort*/
void maxHeapify(int A[], int heapsize, int i) {
	int left = 2*i + 1;
	int right = 2*i + 2;
	int largest = i;

	if (left < heapsize && A[left] > A[largest]) {
		largest = left;
	}
	if (right < heapsize && A[right] > A[largest]) {
		largest = right;
	}

	if (largest != i) {
		swap(A[largest], A[i]);
		maxHeapify(A, heapsize, largest);
	}
}

void buildMaxheap(int A[], int heapsize) {
	int i = (heapsize-1)/2;
	while(i>0) {
		maxHeapify(A, heapsize, i);
		i--;
	}
}

void maxHeapSort(int A[], int heapsize) {
	buildMaxHeap(A, heapsize);
	for(int i=heapsize-1; i>0;i--) {
		swap(A[i],A[0]);
		maxHeapify(A,i,0);
	}
}

/*merge sort*/
void merge(vector<int> &A, int p, int q, int r) {
	int len1 = q-p+1;
	int len2= r-q;
	vector<int> left(len1+1);
	vector<int> right(len2+1);

	for (int i = 0; i < len1; i++) {
		left[i] = A[p+i];
	}
	for(int j = 0; j < len2; j++) {
		right[j] = A[q+1+j];
	}

	int i = j = 0;
	for (int k = p; k < r+1; k++) {
		if (left[i] < right[j]) {
			A[k] = A[i++];
		} else {
			A[k] = A[j++];
		}
	}
}

void msort(vector<int> &A, int p, int r) {
	if (p < r) {
		int q = p + (r-p)/2;
		msort(A, p, q);
		msort(A, q+1, r);
		merge(A, p, q, r);
	}
}
