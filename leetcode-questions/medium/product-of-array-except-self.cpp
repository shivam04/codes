class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = 1;
        int n = nums.size();
        int cz = 0;
        for(int i=0;i<n;i++) {
            if(nums[i]!=0) {
                p*=nums[i];
            } else {
                cz++;
            }
        }
        vector<int> ans(n,0);
        if(cz>=2) {
            return ans;
        }
        for(int i=0;i<n;i++) {
            if(nums[i]==0) {
                ans[i] = p;
            } else {
                if(cz==0) 
                    ans[i] = p/nums[i];
            }
        }
        return ans;
    }
};