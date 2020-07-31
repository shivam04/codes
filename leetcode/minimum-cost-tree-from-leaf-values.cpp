class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int dp[n+1][n+1], large[n+1][n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = 1000000007;
                large[i][j]=-1;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++) {
            dp[i][i] = arr[i];
            large[i][i] = arr[i];
            sum += arr[i];
        }
        for(int len = 2; len<=n;len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + large[i][k] * large[k + 1][j]);
                    large[i][j] = max(large[i][k], large[k + 1][j]);
                    //cout<<dp[i][k]<<" "<<dp[k+1][j]<<i<<" "<<j<<" "<<k<<"\n";
                }
            }
        }
        //cout<<dp[0][n-1]<<"\n";
        return dp[0][n - 1] - sum;
    }
};