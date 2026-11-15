class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() <= 2)
            return ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++) {
            int l = i+1;
            int r = nums.size()-1;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            while(l<r) {
                if(r < nums.size()-1 and nums[r] == nums[r+1]) {
                    r--;
                    continue;
                }
                if(nums[i] + nums[l] + nums[r] == 0) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    ans.push_back(temp);
                    l++;
                    r--;
                } else if (nums[i] + nums[l] + nums[r] > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};