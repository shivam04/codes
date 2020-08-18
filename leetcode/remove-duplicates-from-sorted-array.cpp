class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1)
            return nums.size();
        int c = 1;
        int a = nums[0];
        for(int i=1;i<nums.size();i++) {
            if(nums[i] != a) {
                c++;
                a = nums[i];
            }
        }
        a = nums[0];
        int j = 1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i] != a) {
                a = nums[i];
                nums[j++] = a;
            }
        }
        return c;
    }
};