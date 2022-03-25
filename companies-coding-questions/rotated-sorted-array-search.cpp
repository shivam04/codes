int findPivot(vector<int> array, int s, int n) {
	int low = s;
	int high = n;
	while(low<=high) {
		int mid = (low + high) / 2;
		if(mid < n and array[mid] > array[mid+1]) {
			return mid+1;
		} else if(array[low] <= array[mid]) {
			low = mid+1;
		} else {
			high = mid-1;
		}
	}
	return 0;
}
int searchElement(vector<int> array, int s, int n, int target) {
	int low = s;
	int high = n;
	while(low<=high) {
		int mid = (low + high) / 2;
		if(array[mid]==target) {
			return mid;
		} else if(array[mid] < target) {
			low = mid+1;
		} else {
			high = mid-1;
		}
	}
	return -1;
}
int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int pivot = findPivot(A, 0, n - 1);
    if(pivot > 0 and A[0]<=B and A[pivot-1] >= B) {
		return searchElement(A, 0, pivot-1, B);
	}
    return searchElement(A, pivot, n-1, B);
}
