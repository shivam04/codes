//O(n^2) // O(n^2)
#include <vector>
using namespace std;

map<int,map<int,int>> mp;
int diskStackingUtil(vector<vector<int>> disks, int n, int p) {
	if(n<0)
		return 0;
	if(mp.find(n)!=mp.end() and mp[n].find(p) != mp[n].end())
		return mp[n][p];
	if(disks[n][0] < disks[p][0] and disks[n][1] < disks[p][1] and disks[n][2] < disks[p][2]) {
		return mp[n][p] = max(disks[n][2] + diskStackingUtil(disks, n-1, n), 
							diskStackingUtil(disks, n-1, p));
	}
	return mp[n][p]=diskStackingUtil(disks, n-1, p);
}
vector<vector<int>> diskStacking(vector<vector<int>> disks) {
  mp.clear();
	int n = disks.size();
	sort(disks.begin(), disks.end(), [](vector<int> &a, vector<int> &b) {
		return a[2] < b[2];
	});
	int res = -1;
	for(int i=n-1;i>=0;i--) {
		mp[i][i] = disks[i][2]+diskStackingUtil(disks, i-1, i);
		res = max(res, mp[i][i]);
	}
	vector<vector<int>> ans;
	for(int i=n-1;i>=0;i--) {
		if(mp[i][i] == res) {
			res -= disks[i][2];
			ans.push_back(disks[i]);
		}
	}
	sort(ans.begin(), ans.end(), [](vector<int> &a, vector<int> &b) {
		return a[2] < b[2];
	});
  return ans;
}


//O(n^2) O(n)

#include <vector>
using namespace std;
bool isValid(vector<vector<int>> disks, int i, int j) {
	return (disks[i][0] > disks[j][0] and disks[i][1] > disks[j][1] and 
					disks[i][2] > disks[j][2]);
}
vector<vector<int>> diskStacking(vector<vector<int>> disks) {
  int n = disks.size();
	sort(disks.begin(), disks.end(), [](vector<int> &a, vector<int> &b) {
		return a[2] < b[2];
	});
	int dp[n];
	dp[0] = disks[0][2];
	int res = dp[0];
	for(int i=1;i<n;i++) {
		dp[i] = disks[i][2];
		for(int j=0;j<i;j++) {
			if(isValid(disks,i,j)) {
				dp[i] = max(dp[i], disks[i][2] + dp[j]);
			}
		}
		res = max(res, dp[i]);
	}
	vector<vector<int>> ans;
	for(int i=n-1;i>=0;i--) {
		if(dp[i]==res) {
			res -= disks[i][2];
			ans.push_back(disks[i]);
		}
	}
	sort(ans.begin(), ans.end(), [](vector<int> &a, vector<int> &b) {
		return a[2] < b[2];
	});
  return ans;
}
