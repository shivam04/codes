#include <vector>
using namespace std;

int laptopRentals(vector<vector<int>> times) {
  vector<int> startT;
	vector<int> endT;
	for(vector<int> t: times) {
		startT.push_back(t[0]);
		endT.push_back(t[1]);
	}
	sort(startT.begin(), startT.end());
	sort(endT.begin(), endT.end());
	int i = 0, j =0;
	int lapN = 0;
	while(i< times.size()) {
		if(startT[i] >= endT[j]) {
			lapN--;
			j++;
		}
		lapN++;
		i++;
	}
  return lapN;
}
