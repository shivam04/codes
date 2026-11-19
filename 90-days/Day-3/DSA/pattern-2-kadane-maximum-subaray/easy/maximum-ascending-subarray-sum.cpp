class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;
        int currentSubarraySum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i-1]) {
                maxSum = max(maxSum, currentSubarraySum);
                currentSubarraySum = 0;
            }
            currentSubarraySum += nums[i];
        }
        return max(maxSum, currentSubarraySum);
    }
};