class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp_l(n, 1);
        vector<int> dp_c(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j]) {
                    continue;
                }
                if (dp_l[i] < dp_l[j] + 1) {
                    dp_l[i] = dp_l[j] + 1;
                    dp_c[i] = dp_c[j];
                } else if (dp_l[i] == dp_l[j] + 1) {
                    dp_c[i] += dp_c[j];
                }
            }
        }
        int maxi = *max_element(dp_l.begin(), dp_l.end());
        int count = 0;
        for (int i=0; i<n;i++) {
            if (maxi == dp_l[i]) {
                count += dp_c[i];
            }
        }
        return count;
    }
};