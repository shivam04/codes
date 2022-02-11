class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++) {
            int p = abs(nums[i])-1;
            if(nums[p] > 0) {
                nums[p] = -1*nums[p];
            } else {
                ans.push_back(p+1);
            }
        }
        return ans;
    }
};