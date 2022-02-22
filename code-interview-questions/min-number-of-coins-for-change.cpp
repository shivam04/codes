//O(n*m) O(n*m)
#include <vector>
using namespace std;
map<int,map<int,int>> mp;
int minNumberOfCoinsForChangeUtil(int C, vector<int> denoms, int n) {
	if(C==0)
		return 0;
	if(mp.find(C)!=mp.end() and mp[C].find(n)!=mp[C].end()){
		return mp[C][n];
	}
	int ans = INT_MAX;
	for(int i=0;i<n;i++) {
		if(denoms[i] <= C) {
			int res = minNumberOfCoinsForChangeUtil(C-denoms[i], denoms, n);
			if(res!=INT_MAX and res+1<ans)
				ans = res+1;
		}
	}
	return mp[C][n]=ans;
}

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
	mp.clear();
	int res = minNumberOfCoinsForChangeUtil(n, denoms, denoms.size());
  return res == INT_MAX?-1:res;
}


//O(n*m) O(n)
#include <vector>
using namespace std;
map<int,int> mp;
int minNumberOfCoinsForChangeUtil(int C, vector<int> denoms, int n) {
	if(C==0)
		return 0;
	if(mp.find(C)!=mp.end()){
		return mp[C];
	}
	int ans = INT_MAX;
	for(int i=0;i<n;i++) {
		if(denoms[i] <= C) {
			int res = minNumberOfCoinsForChangeUtil(C-denoms[i], denoms, n);
			if(res!=INT_MAX and res+1<ans)
				ans = res+1;
		}
	}
	return mp[C]=ans;
}

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
	mp.clear();
	int res = minNumberOfCoinsForChangeUtil(n, denoms, denoms.size());
  return res == INT_MAX?-1:res;
}



//O(n*m) O(n)
#include <vector>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
	int m = denoms.size();
	int dp[n+1];
	dp[0] = 0;
	for(int i=1;i<=n;i++) {
		dp[i] = INT_MAX;
	}
	for(int i=1;i<=n;i++) {
		for(int j=0;j<m;j++) {
			if(denoms[j] <= i) {
				int res = dp[i-denoms[j]];
				if(res!=INT_MAX and res+1<dp[i])
					dp[i] = res+1;
			}
		}
	}
	return dp[n]==INT_MAX?-1:dp[n];
}
