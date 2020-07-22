class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int i =0, j =0;
        int n = mat.size();
        bool isUp = false; 
        int w;
        int ti=0,tj=0;
        int m = mat[0].size();
        for (int k = 0; k < m * n;) {
            if(!isUp) {
                i = 0;
                j = tj;
                vector<int> v;
                for(;i<n && j<m;i++,j++) {
                    v.push_back(mat[i][j]);
                    k++;
                }
                w = 0;
                i = 0;
                j = tj;
                sort(v.begin(), v.end());
                for(;i<n && j<m;i++,j++) {
                    mat[i][j] = v[w++];
                }
                tj++;
                if(tj==m) {
                    ti++;
                    isUp = !isUp;
                }
            } else {
                j = 0;
                i = ti;
                vector<int> v;
                for(;i<n and j<m;i++,j++) {
                    v.push_back(mat[i][j]);
                    k++;
                }
                w = 0;
                j = 0;
                i = ti;
                sort(v.begin(), v.end());
                for(;i<n and j<m;i++,j++) {
                    mat[i][j] = v[w++];
                }
                ti++;
                if(ti==n)
                    isUp = !isUp;
            }
        }
        return mat;
    }
};