//O(m*n) O(m*n)
#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  int m = denoms.size();
	int dp[m+1][n+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=m;i++) {
		dp[i][0] = 1;
	}
	for(int i=0;i<=n;i++) {
		dp[0][i] = 0;
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			int x = (j-denoms[i-1]>=0) ? dp[i][j-denoms[i-1]] : 0;
			int y = dp[i-1][j];
			dp[i][j] = x+y;
		}
	}
  return dp[m][n];
}



//O(m*n) O(n)
#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  int dp[n+1];
	int m = denoms.size();
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i=0;i<m;i++) {
		for(int j=denoms[i];j<=n;j++) {
			dp[j] += dp[j-denoms[i]];
		}
	}
  return dp[n];
}
