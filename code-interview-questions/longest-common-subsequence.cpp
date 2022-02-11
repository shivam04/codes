#include <vector>
using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2) {
  int m = str1.length();
	int n = str2.length();
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++) {
		for(int j=0;j<=n;j++) {
			if(i==0 || j==0) {
				dp[i][j] = 0;
			}
			else if(str1[i-1] == str2[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			}
		}
	}
	int idx = dp[m][n];
	vector<char> lcs(idx);
	int i = m, j = n;
	 while (i > 0 && j > 0) {
		 if(str1[i-1] == str2[j-1]) {
			 lcs[idx-1] = str1[i-1];
			 i--;j--;idx--;
		 }
		 else if(dp[i-1][j] > dp[i][j-1]) {
			 i--;
		 } else {
			 j--;
		 }
	 }
  return lcs;
}
