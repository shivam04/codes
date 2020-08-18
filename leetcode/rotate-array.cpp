class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int l = nums.size();
        k = k%l;
        int p = l-k;
        for(int i=0;i<p/2;i++) {
            swap(nums[i], nums[p-i-1]);
        }
        
        for(int i=0;i<k/2;i++) {
            swap(nums[i+p], nums[l-i-1]);
        }
        for(int i=0;i<l/2;i++) {
            swap(nums[i], nums[l-i-1]);
        }
        
    }
};