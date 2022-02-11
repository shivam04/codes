class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        map<int,vector<int>> mp;
        int p = 0;
        for(auto i : groupSizes) {
            mp[i].push_back(p++);
        }
        vector<vector<int>> ans;
        for(auto it: mp) {
            int s = it.first;
            vector<int> nums = it.second;
            int n = nums.size();
            for(int i=0;i<n;) {
                vector<int> anss;
                for(int j=0;j<s;j++) {
                    anss.push_back(nums[i++]);
                }
                ans.push_back(anss);
            }
        }
        return ans;
    }
};