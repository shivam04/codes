class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        if(n==2) {
            if(nums[0] > nums[1])
                return 0;
            return 1;
        }
        for(int i=0;i<n;i++){
            if(i==0 and nums[i]>nums[i+1]) {
                return i;
            } else if(i==n-1 and nums[i]>nums[i-1]) {
                return i;
            }else if(i>0 and i < n-1 and nums[i]>nums[i-1] and nums[i]>nums[i+1]) {
                return i;
            }
        }
        return 0;
    }
};