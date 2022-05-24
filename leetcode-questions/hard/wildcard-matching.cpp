class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        bool dp[n+1][m+1];
        dp[0][0] = true;
        for(int i=1;i<=n;i++) {
            dp[i][0] = false;
        }
        int h = 1;
        for(int i=1;i<=m;i++) {
            if(p[i-1]=='*' and h==1) {
                dp[0][i] = true;
            }
            else {
                dp[0][i] = false;
                h = 0;
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(s[i-1]==p[j-1] || p[j-1]=='?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if(s[i-1]!=p[j-1] and p[j-1]=='*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};