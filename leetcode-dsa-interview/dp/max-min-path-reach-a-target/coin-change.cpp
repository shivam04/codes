class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int maxi = amount+1;
        int dp[amount+1];
        for(int i=0;i<=amount;i++) {
            dp[i] = maxi;
        }
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return dp[amount] >= maxi ? -1 : dp[amount];
    }
};