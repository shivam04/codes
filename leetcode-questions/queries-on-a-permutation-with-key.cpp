class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> P(m+1);
        for(int i=0;i<m;i++){
            P[i] = i+1;
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++) {
            auto it = std::find (P.begin(), P.end(), queries[i]);
            int j = it - P.begin();
            ans.push_back(j);
            P.erase(it);
            P.insert(P.begin(),queries[i]);
            
        }
        return ans;
    }
};