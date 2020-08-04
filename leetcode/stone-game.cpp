//memoization
class Solution {
public:
    int dp[505][505][2];
    int stoneGameUtil(vector<int>& piles, int s, int e, int p) {
        if(s>e)
            return 0;
        if(s==e) {
            if(p==0)
                return 0;
            else
                return piles[s];
        }
        if(dp[s][e][p]!=-1)
            return dp[s][e][p];
        if(p==0)
            return dp[s][e][p] = min(stoneGameUtil(piles,s+1,e,1), stoneGameUtil(piles,s,e-1,1));
        return dp[s][e][p] = max(piles[s] + stoneGameUtil(piles,s+1,e,0), piles[e]+stoneGameUtil(piles,s,e-1,0));
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum = 0;
        memset(dp,-1,sizeof(dp));
        sum = accumulate(piles.begin(), piles.end(), sum);
        int ans = max(piles[0] + stoneGameUtil(piles, 1 , n-1, 0), piles[n-1] + stoneGameUtil(piles, 0, n-2, 0));
        int w = sum-ans;
        return ans>w;
    }
};


//dp table

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int dp[n+1][n+1][2];
        int sum = 0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) {
            dp[i][i][1] = piles[i];
        }
        sum = accumulate(piles.begin(), piles.end(), sum);
        for(int len=2;len<=n;len++) {
            for(int i=0,j = len - 1; j < n; i++,j++) {
                dp[i][j][0] = min(dp[i+1][j][1], dp[i][j-1][1]);
                dp[i][j][1] = max(piles[i] + dp[i+1][j][0], piles[j] + dp[i][j-1][0]);
            }
        }
        
        int ans = dp[0][n-1][1];
        cout<<ans<<"\n";
        int w = sum-ans;
        return ans>w;
    }
};

//optimized O(1)

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};