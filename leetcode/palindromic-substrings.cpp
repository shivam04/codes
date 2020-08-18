class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        bool dp[n+1][n+1];
        memset(dp,false,sizeof(dp));
        for(int i=0;i<n;i++) {
            dp[i][i] = true;
        }
        for(int i=0;i<n-1;i++) {
            if(s[i]==s[i+1])
                dp[i][i+1] = true;
        }
        for(int len=3;len<=n;len++) {
            for(int i=0;i<n-len+1;i++) {
                int j = i+len-1;
                if(s[i]==s[j] and dp[i+1][j-1])
                    dp[i][j] = true;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                ans += dp[i][j];
            }
        }
        return ans;
    }
};