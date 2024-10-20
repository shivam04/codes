class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if (nums[0] == 0 || n<=1) {
            return 0;
        }

        int maxReach = nums[0];
        int step = nums[0];
        int jump =1;
        for (int i = 1; i < n; i++) { 
            if (i==n-1) {
                return jump;
            }

            maxReach = max(maxReach, i + nums[i]);
            step--;
            if (step == 0) {
                jump++;
                if (i>=maxReach) {
                    return -1;
                }

                step = maxReach - i;
            }
        }

        return jump;

    }
};