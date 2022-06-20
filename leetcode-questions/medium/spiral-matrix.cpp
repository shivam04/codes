class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int i, k = 0, l = 0;
        while (k < m && l < n) {
            for (i = l; i < n; ++i) {
                ans.push_back(matrix[k][i]);
            }
            k++;
            for (i = k; i < m; ++i) {
                ans.push_back(matrix[i][n-1]);
            }
            n--;
            if(k < m) {
                for(i=n-1;i>=l;i--) {
                    ans.push_back(matrix[m-1][i]);
                }
                m--;
            }
            if(l<n) {
                for(i=m-1;i>=k;i--) {
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return ans;
    }
};