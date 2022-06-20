class Solution {
public:
    vector<vector<int>> result; 
    int n;

    void combination(int ind,int target,vector<int> &nums,vector<int> ans)  {
        if(target==0) {
        result.push_back(ans);
            return ;
        }

        for(int i=ind;i<n;i++) {
            if(i>ind && nums[i]==nums[i-1]) continue;

            if(nums[i]>target)
            break;

            ans.push_back(nums[i]);
            combination(i+1,target-nums[i],nums,ans);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<int> ans;
        sort(candidates.begin(),candidates.end());
        combination(0,target,candidates,ans);

        return result;
    }
};