class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> runningSum(nums.size(), 0);

        runningSum[0] = nums[0];
        for(int i=1;i<nums.size();i++) {
            runningSum[i] = runningSum[i-1] + nums[i];
        }

        return runningSum;
    }
};