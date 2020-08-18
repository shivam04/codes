class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0)
            return s;
        int n = s.length();
        int dp[n][n];
        int ml = 1;
        int mi = 0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) {
            dp[i][i] = 1;
        }
        for(int i=0;i<n-1;i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = 1;
                ml = 2;
                mi = i;
            }
        }
        for(int len = 3; len<=n;len++) {
            for(int i=0;i<n-len+1;i++) {
                int j = i+len-1;
                if(s[i] == s[j] and dp[i+1][j-1]) {
                    dp[i][j] = 1;
                    if(len > ml) {
                        ml = len;
                        mi = i;
                    }
                }
            }
        }
        return s.substr(mi, ml);
    }
};