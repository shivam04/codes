class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++) {
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int> > ans;
        for(auto it = mp.begin(); it!=mp.end();++it) {
            int x = it->first;
            vector<int> k = it->second;
            for(int i=0;i<k.size();) {
                vector<int> anss;
                for(int j=0;j<x;j++) {
                    anss.push_back(k[i++]);
                }
                ans.push_back(anss);
            }
        }
        return ans;
    }
};