#include <vector>
using namespace std;

vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
	int W = capacity;
	int n = items.size();
  int dp[W+1][n+1];
	vector<int> ans;
	for(int i=0;i<=W;i++) {
			dp[i][0] = 0;
	}
	for(int i=0;i<=n;i++) {
			dp[0][i] = 0;
	}
	for(int i=1;i<=W;i++) {
			for(int j=1;j<=n;j++) {
					if(items[j-1][1]>i) {
							dp[i][j] = dp[i][j-1];
					} else {
							dp[i][j] = max(items[j-1][0] + dp[i-items[j-1][1]][j-1], dp[i][j-1]);
					}
			}
	}
	int res = dp[W][n];
	int w = W;
	for(int i=n;i>0 and res>0;i--) {
		if(res == dp[w][i-1])
			continue;
		else {
			ans.push_back(i-1);
			res -= items[i-1][0];
			w -= items[i-1][1];
		}
	}
  return {
      {dp[W][n]},   // total value
      ans, // item indices
  };
}
