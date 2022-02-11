#include <vector>
using namespace std;

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
  vector<int> seq(array.size(), INT_MIN);
	vector<int> sums = array;
	int maxSumIdx = 0;
	for(int i=0;i<array.size();i++) {
		int c = array[i];
		for(int j=0;j<i;j++) {
			int o = array[j];
			if(o < c && sums[j] + c >= sums[i]) {
				sums[i] = sums[j] + c;
				seq[i] = j;
			}
		}
		if(sums[i] >= sums[maxSumIdx]) {
			maxSumIdx = i;
		}
	}
	vector<vector<int>> ans = {{}, {}};
	ans[0].push_back(sums[maxSumIdx]);
	int ci = maxSumIdx;
	while(ci != INT_MIN) {
		ans[1].insert(ans[1].begin(), array[ci]);
		ci = seq[ci];
	}
  return ans;
}
