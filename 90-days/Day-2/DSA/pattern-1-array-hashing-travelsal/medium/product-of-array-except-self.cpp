class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix, suffix;
        prefix.push_back(1);
        int pre=1;
        for(int num: nums) {
            pre*=num;
            prefix.push_back(pre);
        }
        int suf=1;
        int n = nums.size();
        suffix.resize(n+1);
        suffix[n]=1;
        for(int i=n-1;i>=0;i--) {
            suf*=nums[i];
            suffix[i] = suf;
        }
        vector<int> ans;
        for(int i=1;i<=n;i++) {
            ans.push_back(prefix[i-1]*suffix[i]);
        }
        return ans;
    }
};