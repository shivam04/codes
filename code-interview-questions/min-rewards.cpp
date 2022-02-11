#include <vector>
using namespace std;

int minRewards(vector<int> scores) {
	int n = scores.size();
	vector<int> lReward(n,1);
	vector<int> rReward(n,1);
	for(int i=1;i<n;i++) {
		if(scores[i]<scores[i-1]) {
			lReward[i] = 1;
		} else {
			lReward[i] = lReward[i-1] + 1;
		}
	}
	for(int i=n-2;i>=0;i--) {
		if(scores[i]<scores[i+1]) {
			rReward[i] = 1;
		} else {
			rReward[i] = rReward[i+1] + 1;
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++) {
		ans += max(lReward[i], rReward[i]);
	}
  return ans;
}
