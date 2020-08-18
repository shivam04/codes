class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, large = INT_MAX;
        int i;
        for(i=0;i<nums.size();i++) {
            if(nums[i] <= small) {
                small = nums[i];
            } else if(nums[i] <= large) {
                large = nums[i];
            } else {
                break;
            }
        }
        if(i == nums.size())
            return false;
        return true;
    }
};