class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        for (int i=0; i<n; i++) {
            while (ans.size() > 0 and ans.back() > nums[i] and (ans.size() + n - i) >= (k+1)) {
                ans.pop_back();
            }
            if (ans.size() < k) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};