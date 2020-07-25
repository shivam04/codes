class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int prefix[n+1];
        memset(prefix, 0 ,sizeof(prefix));
        vector<int> ans;
        for(int i=1;i<=n;i++) {
            prefix[i] = prefix[i-1]^arr[i-1];
        }
        for(int i=0;i<queries.size();i++) {
            int l = queries[i][0]+1;
            int r = queries[i][1]+1;
            ans.push_back(prefix[r]^prefix[l-1]);
        }
        return ans;
    }
};