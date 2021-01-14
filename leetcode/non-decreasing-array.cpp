class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int p = -1;
        int n = nums.size();
        for(int i=0;i<n-1;i++) {
            if(nums[i] > nums[i+1]) {
                if(p != -1)
                    return false;
                p = i;
            }
        }
        return (p == -1 or p==0 or p==n-2 or nums[p-1] <= nums[p+1] or nums[p]<=nums[p+2]);
    }
};