class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        int dp[n1+2][n2+2];
        int p1[n1+2];
        int p2[n2+2];
        p1[0] = int(s1[0]);
        for(int i=1;i<n1;i++) {
            p1[i] = p1[i-1] + int(s1[i]);
        }
        p2[0] = int(s2[0]);
        for(int i=1;i<n2;i++) {
            p2[i] = p2[i-1] + int(s2[i]);
        }
        dp[0][0] = 0;
        for(int i=1;i<=n1;i++) {
            dp[i][0] = p1[i-1]; 
        }
        for(int i=1;i<=n2;i++) {
            dp[0][i] = p2[i-1]; 
        }
        for(int i=1;i<=n1;i++) {
            for(int j=1;j<=n2;j++) {
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(int(s1[i-1]) + dp[i-1][j], int(s2[j-1]) + dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};