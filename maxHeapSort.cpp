void maxHeapify(int A[],int n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < n && A[left] > A[largest]) {
        largest = left;
    }
    if (right < n && A[right] > A[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(A[largest], A[i]);
        maxHeapify(A, n, largest);
    }
}

void buildMaxHeap(int A[], int n) {
    int i = (n-1) / 2;
    while (i >= 0) {
        maxHeapify(A, n, i);
        i--;
    } 
}

void maxHeapSort(int A[], int n) {
    buildMaxHeap(A, n);
    for ( int i = n-1; i > 0; i--) {
        std::swap(A[0], A[i]);
        maxHeapify(A, i, 0);
    }
}
