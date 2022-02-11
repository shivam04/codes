#include <vector>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
	unordered_map<int, vector<vector<int>>> allPairSum;
	vector<vector<int>> ans;
	for(int i=1;i<array.size()-1;i++) {
		for(int j=i+1;j<array.size();j++) {
			int cs = array[i] + array[j];
			int diff = targetSum - cs;
			if(allPairSum.find(diff) != allPairSum.end()) {
				for(vector<int> pair: allPairSum[diff]) {
					pair.push_back(array[i]);
					pair.push_back(array[j]);
					ans.push_back(pair);
				}
			}
		}
		for(int k=0;k<i;k++) {
			int cs = array[i] + array[k];
			if(allPairSum.find(cs)==allPairSum.end()) {
				allPairSum[cs] = vector<vector<int>>{{array[k], array[i]}};
			} else {
				allPairSum[cs].push_back(vector<int>{array[k], array[i]});
			}
		}
	}
	return ans;
}
