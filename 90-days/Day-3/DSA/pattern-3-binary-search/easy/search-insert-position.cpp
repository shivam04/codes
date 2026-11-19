class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int r = nums.size() - 1;
        int l = 0;
        int ans = r+1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if (nums[mid] >= target) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
};


// C++ STL

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return it;
    }
};