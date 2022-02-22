#include <vector>
using namespace std;

vector<int> searchForRange(vector<int> array, int target) {
  int l = lower_bound(array.begin(), array.end(), target) - array.begin();
	int h = upper_bound(array.begin(), array.end(), target) - array.begin() - 1;
	if(array[l] == target and array[h] == target)
		return {l,h};
  return {-1,-1};
}
