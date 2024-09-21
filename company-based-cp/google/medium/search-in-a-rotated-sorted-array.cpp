class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[lo] <= nums[mid]) {
                if (target >= nums[lo] and target < nums[mid]) {
                    hi = mid-1;
                } else {
                    lo = mid + 1;
                } 
            } else {
                if (target >= nums[mid] and target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid-1;
                }
            }
        }
        return -1;
    }
};