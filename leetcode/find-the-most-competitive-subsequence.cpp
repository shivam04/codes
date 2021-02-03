class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> ans;
        for (int i=0; i<N; i++) {
            while (ans.size() > 0 and ans.back() > nums[i] and (ans.size() + N - i) >= (k+1)) {
                ans.pop_back();
            }
            if (ans.size() < k) ans.push_back(nums[i]);
        }
        return ans;
    }
};