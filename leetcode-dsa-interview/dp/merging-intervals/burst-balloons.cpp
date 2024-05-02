class Solution {
public:
    int getNum(vector<int>& nums, int i, int sz) {
        if (i>=sz) {
            return 1;
        }

        if (i < 0) {
            return 1;
        }

        return nums[i];
    }
    vector<int> getNewNums(int j, vector<int> &nums) {
        vector<int> newNums;
        for(int i=0;i<nums.size();i++) {
            if (i!=j) {
                newNums.push_back(nums[i]);
            }
        }
        return newNums;
    }
    int anss(vector<int> &nums, int l, int r, vector<vector<int>> &dp) {
        if (r-l < 0) {
            return 0;
        }
        if (dp[l][r]!=-1) {
            return dp[l][r];
        }
        int maxCoin = 0;
        for(int i=l;i<=r;i++) {
            int gain = nums[l-1]*nums[i]*nums[r+1];
            int remaining = anss(nums, l, i-1, dp) + anss(nums, i+1, r, dp);
            maxCoin = max(maxCoin, gain+remaining);
        }
        return dp[l][r]=maxCoin;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return anss(nums, 1,n-2,dp);
    }
};