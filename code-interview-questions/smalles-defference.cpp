#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  sort(arrayOne.begin(), arrayOne.end());
	sort(arrayTwo.begin(), arrayTwo.end());
	vector<int> ans;
	int i=0,j=0;
	int n = arrayOne.size();
	int m = arrayTwo.size();
	int diffMin = 1000000;
	while(i<n && j<m) {
		int diff = abs(arrayOne[i]-arrayTwo[j]);
		if(diff < diffMin) {
			ans.clear();
			diffMin = diff;
			ans.push_back(arrayOne[i]);
			ans.push_back(arrayTwo[j]);
		} else if(arrayOne[i]<arrayTwo[j]) {
			i++;
		} else {
			j++;
		}
	}
  return ans;
}
