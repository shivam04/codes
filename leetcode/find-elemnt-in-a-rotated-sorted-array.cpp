class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        while(l<=h) {
            int mid = (l+h)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[l] <= nums[mid]) {
                if(target>=nums[l] and target<=nums[mid]) {
                    h = mid-1;
                } else {
                    l = mid+1;
                }
                continue;
            }
            if(target>=nums[mid] and target<=nums[h])
                l = mid+1;
            else
                h = mid-1;
        }
        return -1;
    }
};