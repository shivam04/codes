class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i=0;i<nums.size();i++) {
            int remainingTarget = target - nums[i];
            if (mp.find(remainingTarget) != mp.end()) {
                return {mp[remainingTarget], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};