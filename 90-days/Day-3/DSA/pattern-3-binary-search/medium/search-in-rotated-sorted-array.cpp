class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r = nums.size() - 1;
        int l = 0;
        while (l<=r) {
            int mid = l + (r-l)/2;
            if (nums[mid] == target) {
                return mid;
            }

            // left half sorted
            if (nums[mid] >= nums[l]) {
                // if target in this sorted aray
                if (target >= nums[l] and target < nums[mid]) {
                    r = mid-1;
                } else {
                    // o.w. in second sorted array
                    l = mid + 1;
                }
            } 
            // right half sorted 
            else {
                 // if target in this sorted aray
                if (target > nums[mid] and target <= nums[r]) {
                    l = mid + 1;
                } else {
                    // o.w. in first sorted array
                    r = mid-1;
                }
            }
        }
        return -1;
    }
};