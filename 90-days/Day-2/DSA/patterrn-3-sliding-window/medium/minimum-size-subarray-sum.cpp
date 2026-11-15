class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int l = 0, r = 0, sumOfCurrentWindow = 0;
        for(int r=0;r<nums.size();r++) {
            sumOfCurrentWindow += nums[r];
            while (sumOfCurrentWindow >= target) {
                minLen = min(minLen, r - l + 1);
                sumOfCurrentWindow-=nums[l];
                l++;
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};