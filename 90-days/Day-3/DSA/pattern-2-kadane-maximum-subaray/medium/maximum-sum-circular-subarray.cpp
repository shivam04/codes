class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax = 0;
        int curMin = 0;
        int maxSum = nums[0];
        int minSum = nums[0];
        int totalSum = 0;

        for(int num: nums) {
            curMax = max(curMax, 0) + num;
            maxSum = max(maxSum, curMax);

            curMin = min(curMin, 0) + num;
            minSum = min(minSum, curMin);

            totalSum += num;
        }

        if (totalSum == minSum) {
            return maxSum;
        }

        return max(maxSum, totalSum - minSum);
    }
};