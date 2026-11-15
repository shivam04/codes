class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = -DBL_MAX;
        long sum = 0;
        for(int i=0;i<k;i++) {
            sum += nums[i];
        }
        ans = (double)sum/ (double)k;
        for (int i=k;i<nums.size();i++) {
            sum = sum -  nums[i-k];
            sum += nums[i];
            ans = max(ans, (double)sum/ (double)k);
        }
        return ans;
    }
};