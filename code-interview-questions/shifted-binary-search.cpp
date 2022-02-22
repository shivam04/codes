//O(logn) //O(1)
#include <vector>
using namespace std;
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

int shiftedBinarySearch(vector<int> array, int target) {
	int n = array.size();
  int pivot = findPivot(array, 0, n - 1);
	if(pivot > 0 and array[0]<=target and array[pivot-1] >= target) {
		return searchElement(array, 0, pivot-1, target);
	}
	return searchElement(array, pivot, n-1, target);
}


