class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        if(n==0) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(lb==n || nums[lb] != target) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        } 
        ans.push_back(lb);
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        ans.push_back(ub-1);
        return ans;
    }
};