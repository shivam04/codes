//O(n*k) //O(n)
using namespace std;

int staircaseTraversal(int height, int maxSteps) {
  vector<int> dp(height+1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2;i<=height;i++) {
		for(int j=1;j<=min(maxSteps,i);j++) {
			dp[i] = dp[i] + dp[i-j];
		}
	}
  return dp[height];
}



//O(n) O(n)
using namespace std;

int staircaseTraversal(int height, int maxSteps) {
  int dp[height+1];
	dp[0] = 1;
	int cW = 0;
	for(int i=1;i<=height;i++) {
		int s = i-maxSteps-1;
		int e = i-1;
		if(s>=0)
			cW -= dp[s];
		cW += dp[e];
		dp[i] = cW;
	}
  return dp[height];
}
