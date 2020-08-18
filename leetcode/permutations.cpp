class Solution {
public:
    void permute(vector<vector<int>> &k, int i, vector<int> nums) {
        if(i==nums.size()) {
            k.push_back(nums);
            return;
        }
        for(int x=i;x<nums.size();x++) {
            swap(nums[i], nums[x]);
            permute(k, i+1, nums);
            swap(nums[i], nums[x]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> k;
        permute(k, 0, nums);
        return k;
    }
};