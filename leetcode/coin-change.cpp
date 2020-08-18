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
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if(i >= coins[j]) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] >= maxi ? -1 : dp[amount];
    }
};