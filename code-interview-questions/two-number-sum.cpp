#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
	unordered_map<int,int> mp;
	int n = array.size();
  for(int i=0;i<n;i++) {
		int f = targetSum - array[i];
		if(mp.find(f)!=mp.end()) {
			return {f,array[i]};
		}
		mp[array[i]] = 1;
	}
  return {};
}
