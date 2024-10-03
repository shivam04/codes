class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i=0;i<n-2;i++) {
            int j = i+1;
            int k = n-1;
            if (i > 0 and nums[i] == nums[i-1]) {
                continue;
            }
            while (j < k) {
                if (k < n-1 and nums[k] == nums[k+1]) {
                    k--;
                    continue;
                }
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    vector<int> ele;
                    ele.push_back(nums[i]);
                    ele.push_back(nums[j]);
                    ele.push_back(nums[k]);
                    ans.push_back(ele);
                    j++;
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
};