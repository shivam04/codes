class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int> > ans;
        int n = A.size();
        int m = B.size();
        vector<int> point;
        int i = 0, j = 0;
        while(i<n and j<m) {
            int f = max(A[i][0], B[j][0]);
            int s = min(A[i][1], B[j][1]);
            point.push_back(f);
            point.push_back(s);
            if(f<=s)
                ans.push_back(point);
            point.clear();
            if(A[i][1] < B[j][1])
                i++;
            else
                j++;
        }
        return ans;
    }
};