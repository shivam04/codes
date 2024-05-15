//O(N^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int lis[n];
        lis[0] = 1;

        for (int i=1;i<n;i++) {
            lis[i] = 1;
            for(int j=0;j<i;j++) {
                if (nums[i] > nums[j] and lis[i] < lis[j] + 1) {
                    lis[i] = lis[j] + 1;
                }
            }
        }
        return *max_element(lis, lis+n);
    }
};


//O(NlogN)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            } else {
                int low = lower_bound(ans.begin(), ans.end(),nums[i]) - ans.begin();
                ans[low] = nums[i];
            }
        }
        return ans.size();
    }
};