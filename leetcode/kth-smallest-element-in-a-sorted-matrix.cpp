typedef pair<int,pair<int,int>> ppi;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue <ppi, vector<ppi>, greater<ppi>> pq;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<m;i++) {
            pq.push({matrix[0][i],{0,i}});
        }
        pair<int,pair<int,int>> hr;
        for(int i=0;i<k;i++) {
            hr = pq.top();
            pq.pop();
            int nextval = (hr.second.first < (n-1))? matrix[hr.second.first + 1][hr.second.second]: INT_MAX;
            pq.push({nextval,{hr.second.first+1,hr.second.second}});
        }
        return hr.first;
    }
};