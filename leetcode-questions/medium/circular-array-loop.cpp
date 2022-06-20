class Solution {
public:
    int getIndex(vector<int> nums, int i) {
        int n = nums.size();
        if (i + nums[i] >= 0) {
            return (i + nums[i] +n) % n;
        } else {
            return  (i + nums[i] + 5000*n) % n;
        }
      }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i]==0) continue;
            int slow = i;
            int fast = getIndex(nums, i);
            while(nums[fast]*nums[i]>0 and nums[getIndex(nums,fast)]*nums[i]>0) {
                if(slow==fast) {
                    if(slow == getIndex(nums, slow)) break;
                    return true;
                }
                slow = getIndex(nums, slow);
                fast = getIndex(nums, getIndex(nums,fast));
            }
            slow = i;
            int val = nums[i];
            while (nums[slow] * val > 0) {
                int next = getIndex(nums, slow);
                nums[slow] = 0;
                slow = next;
            }
        }
        return false;
    }
};