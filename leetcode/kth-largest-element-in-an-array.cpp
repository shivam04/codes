class Solution {
public:
    int partition(int s, int e, vector<int> &nums) {
        int x = nums[e];
        int i = s;
        for(int j=s;j<=e;j++) {
            if(nums[j] > x) {
                swap(nums[i++], nums[j]);
            }
        }
        swap(nums[i], nums[e]);
        return i;
    }
    int kthLargetst(vector<int>& nums, int s, int e ,int k) {
        if(k > 0 and k <= (e-s+1)) {
            int p = partition(s, e, nums);
            if(p-s == k-1)
                return nums[p];
            if(p-s > k-1) {
                return kthLargetst(nums, s, p-1, k);
            }
            return kthLargetst(nums, p+1, e, k - p + s - 1);
        }
        return INT_MIN;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return kthLargetst(nums, 0 , n-1, k);
    }
};