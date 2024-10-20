class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        if (n<=1) {
            return true;
        }

        if (nums[0] == 0) {
            return false;
        }

        int maxReach = nums[0];
        int step = nums[0];
        int jump =1;
        for (int i = 1; i < n; i++) { 
            if (i==n-1) {
                return true;
            }

            maxReach = max(maxReach, i + nums[i]);
            step--;
            if (step == 0) {
                jump++;
                if (i>=maxReach) {
                    return false;
                }

                step = maxReach - i;
            }
        }

        return false;

    }
};