#include <vector>
using namespace std;

int indexEqualsValue(vector<int> array) {
	int n = array.size();
	int l = 0;
	int h = n-1;
	while(l<=h) {
		int mid = (l+h)/2;
		if(array[mid] < mid) {
			l = mid+1;
		} else if(array[mid]==mid and mid==0) {
			return mid;
		} else if(array[mid]==mid and array[mid-1] < mid-1) {
			return mid;
		} else {
			h = mid-1;
		}
	}
  return -1;
}
