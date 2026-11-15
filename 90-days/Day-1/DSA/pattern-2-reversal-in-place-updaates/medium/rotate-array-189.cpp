// https://leetcode.com/problems/rotate-array/description/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k %=n;
        int m = n-k;
        for (int i=0; i<m/2;i++) {
            swap(nums[i], nums[m-i-1]);
        }

        for(int i=0;i<k/2;i++) {
            swap(nums[m+i], nums[n-i-1]);
        }

        for (int i=0; i<n/2;i++) {
            swap(nums[i], nums[n-i-1]);
        }
    }
};