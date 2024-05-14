class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        if (totalSum%2 != 0) {
            return 0;
        }
        int subSetSum = totalSum/2;
        int n = nums.size();
        bool dp[n + 1][subSetSum + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<=subSetSum;j++) {
                if (nums[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = (dp[i-1][j]) or (dp[i-1][j-nums[i-1]]);
                }
            }
        }
        return dp[n][subSetSum];
    }
};