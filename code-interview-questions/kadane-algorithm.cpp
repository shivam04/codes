#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
  int maxEndingHere = array[0];
	int maxSoFar = array[0];
	for(int i=1;i<array.size();i++) {
		int num = array[i];
		maxEndingHere = max(num, maxEndingHere + num);
		maxSoFar = max(maxSoFar, maxEndingHere);
	}
  return maxSoFar;
}
