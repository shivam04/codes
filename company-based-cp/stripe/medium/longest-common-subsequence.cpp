class Solution {
public:
    unordered_map<int, unordered_map<int, int>> memo;
    int longestCommonSubsequenceUtil(string text1, string text2, int n, int m) {
        if (n < 0 or m < 0) {
            return 0;
        }
        if (memo.find(n) != memo.end() and memo[n].find(m) != memo[n].end()) {
            return memo[n][m];
        }
        if (text1[n] == text2[m]) {
            return memo[n][m] = 1 + longestCommonSubsequenceUtil(text1, text2, n-1, m-1);
        }
        return memo[n][m] = max(longestCommonSubsequenceUtil(text1, text2, n-1, m), 
        longestCommonSubsequenceUtil(text1, text2, n, m-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memo.clear();
        return longestCommonSubsequenceUtil(text1, text2, text1.size()-1, text2.size()-1);
    }
};



class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
       int n = text1.size();
       int m = text2.size();

       int dp[n+1][m+1];
       memset(dp ,0, sizeof(dp));

       for (int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
       }
       return dp[n][m];
    }
};