class Solution {
public:
    set<vector<int>> ans;
    void answers(vector<int>& A, int s, int sum, int target, vector<int> anss) {
        if(sum==target) {
            ans.insert(anss);
        }
        if(sum > target)
            return;
        if(s>=A.size())
            return;
        int x = sum + A[s];
        answers(A, s+1, sum, target,anss);
        anss.push_back(A[s]);
        answers(A, s, x, target,anss);
        anss.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        answers(candidates, 0, 0, target, {});
        vector<vector<int>> ansss;
        for(auto a: ans) {
            ansss.push_back(a);
        }
        return ansss;
    }
};