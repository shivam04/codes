class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int jumps[n+1];
        if(n==1 and nums[0]==0)
            return true;
        if(nums[0]==0)
            return false;
        jumps[0] = 0;
        for(int i=1;i<n;i++) {
            jumps[i] = INT_MAX;
            for(int j=0;j<i;j++) {
                if(i <= j+nums[j] and jumps[j] != INT_MAX)
                    jumps[i] = min(jumps[i], jumps[j]+1);
            }
        }
        return !(jumps[n-1]==INT_MAX);
    }
};

//optimize O(n)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)
            return true;
        if(nums[0]==0)
            return false;
        int maxReach = nums[0];
        int step = nums[0];
        int jump =1;
        int i = 1;
        for (i = 1; i < n; i++) { 
            if(i==n-1)
                return true;
            maxReach = max(maxReach, i + nums[i]); 
            step--;
            if(step==0) {
                jump++;
                if(i>=maxReach)
                    return false;
                step = maxReach - i; 
            }
        }
        return false;
    }
};