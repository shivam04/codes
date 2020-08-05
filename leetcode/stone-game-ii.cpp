//memoization
class Solution {
public:
    int prefixSum[105];
    int dp[105][210][2];
    int stoneGameIIUtil(vector<int> piles, int s, int m, int n, int p) {
        if(s>=n)
            return 0;
        if(dp[s][m][p]!=-1)
            return dp[s][m][p];
        int q;
        if(p) {
            q = -1;
            for(int x=1;x<=min(2*m, n);x++) {
                if(s+x>n)
                    break;
                int g = s>0 ? prefixSum[s-1] : 0;
                int w = (prefixSum[s+x-1] - g);
                q = max(q, w + stoneGameIIUtil(piles, s+x, max(x,m), n ,1-p));
            }
        } else {
            q = INT_MAX;
            for(int x=1;x<=min(2*m, n);x++) {
                if(s+x>n)
                    break;
                if(q == INT_MAX)
                    q = stoneGameIIUtil(piles, s+x, max(x,m), n ,1-p);
                else  
                    q = min(q, stoneGameIIUtil(piles, s+x, max(x,m), n ,1-p));
            }
        }
        return (dp[s][m][p] = q==INT_MAX?0:q);
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int n = piles.size();
        memset(prefixSum, 0 ,sizeof(prefixSum));
        prefixSum[0] = piles[0];
        for(int i=1;i<n;i++) {
            prefixSum[i] = prefixSum[i-1] + piles[i];
        }
        return stoneGameIIUtil(piles, 0, 1, n, 1);
    }
};