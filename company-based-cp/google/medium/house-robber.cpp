class Solution {
public:
    unordered_map<int, int> mp;
    int robUtil(vector<int> &nums, int n) {
        if (n < 0) {
            return 0;
        }
        if (n==0) {
            return nums[n];
        }
        if (n==1) {
            return max(nums[n], nums[n-1]);
        }
        if (mp.find(n) != mp.end()) {
            return mp[n];
        }
        return mp[n] = max(nums[n] + robUtil(nums, n-2), robUtil(nums, n-1));
    }
    int rob(vector<int>& nums) {
        mp.clear();
        return robUtil(nums, nums.size() - 1);
    }
};



class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return nums[0];
        }
        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i=2;i<n;i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
};