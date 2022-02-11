#include <vector>
using namespace std;

int firstDuplicateValue(vector<int> array) {
	for(int i=0;i<array.size();i++) {
		int p = abs(array[i])-1;
		if(array[p] < 0) {
			return abs(array[i]);
		}
		array[p] = -1*array[p];
	}
	return -1; 
}
