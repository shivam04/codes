class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<(1<<n);i++) {
            vector<int> p;
            for(int j=0;j<n;j++) {
                if(i&(1<<j)) {
                    p.push_back(nums[j]);
                }
            }
            ans.push_back(p);
        }
        return ans;
    }
};

//backtracking
class Solution {
public:
    void subsetsUtil(vector<vector<int>> &ans, vector<int> &subset, int idx, vector<int> nums) {
        ans.push_back(subset);
        for(int i=idx; i<nums.size();i++) {
            subset.push_back(nums[i]); 
            subsetsUtil(ans, subset, i+1, nums);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset; 
        subsetsUtil(ans, subset, 0, nums);
        return ans;
    }
};