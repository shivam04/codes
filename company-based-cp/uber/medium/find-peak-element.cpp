// O(n)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) return i;
        }
        return nums.size() - 1;
    }
};


// O(logn)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l < r) {
            int mid = (l+r)/2;
            if (nums[mid] > nums[mid+1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};