class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        set<int> s;
        for(int i=0;i<edges.size();i++) {
            int q = edges[i][1];
            s.insert(q);
        }
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if(s.find(i) == s.end()) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};