class Solution {
public:
    int search(vector<int>& nums, int target) {
        int h = nums.size()-1;
        int l = 0;
        while(l<=h) {
            int mid = l + (h-l)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[l] <= nums[mid]) {
                if(nums[l]<=target and target<nums[mid]) {
                    h = mid-1;
                } else {
                    l = mid+1;
                }
            } else {
                if(nums[mid] < target and target<=nums[h]) {
                    l = mid+1;
                } else {
                    h = mid-1;
                }
            }
            
        }
        return -1;
    }
};