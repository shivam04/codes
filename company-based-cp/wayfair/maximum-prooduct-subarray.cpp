class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long currMax = nums[0];
        long long currMin = nums[0];
        long long maxProd = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            long long temp = max({nums[i]*1LL, nums[i]*currMax, 
                    nums[i]*currMin});
            currMin = min({ nums[i] * 1LL, nums[i] * currMax,
                    nums[i] * currMin });
            currMax = temp;
            maxProd = max(maxProd, currMax);
        }
        return maxProd;
    }
};