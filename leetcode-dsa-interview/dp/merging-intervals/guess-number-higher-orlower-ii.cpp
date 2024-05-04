class Solution {
public:
    unordered_map<int, unordered_map<int,int>> dp;
    int anss(int x, int y) {
        if (y <= x) {
            return 0;
        }
        if (dp.find(x) != dp.end() and dp[x].find(y) != dp[x].end()) {
            return dp[x][y];
        }
        int mini = INT_MAX, res;
        for(int i=x;i<=y;i++) {
            res = max(anss(x,i-1), anss(i+1, y)) + i;
            mini = min(mini, res);
        }
        return dp[x][y]=mini;
    }
    int getMoneyAmount(int n) {
        int ans = anss(1, n);
        return ans;
    }
};


//DP
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int len=2;len<=n;len++) {
            for(int start=1;start<=n-len+1;start++) {
                int ans = INT_MAX;
                int end = start+len-1;
                for(int piv=start;piv<end;piv++) {
                    int res = piv + max(dp[start][piv-1], dp[piv+1][end]);
                    ans = min(ans,res);
                }
                dp[start][end] = ans;
            } 
        }
        return dp[1][n];
    }
};