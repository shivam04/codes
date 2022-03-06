#include <vector>
using namespace std;
int quickselectUtil(vector<int> array, int s, int e, int position) {
	while(true) {
		if(s>e)
			return -1;
		int pivot = array[e];
		int i = (s - 1);
		for(int j=s;j<e;j++) {
			if (array[j] < pivot) {
				i++;
				swap(array[i], array[j]);
			}
		}
		swap(array[i+1], array[e]);
		int pI = i+1;
		if(pI == position)
			return array[pI];
		if(pI > position) {
			e = pI-1;
		} else {
			s = pI+1;
		}
	}
}

int quickselect(vector<int> array, int k) {
	int position = k-1;
  return quickselectUtil(array, 0, array.size() - 1, position);
}
