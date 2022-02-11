class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        bool isUp = false; 
        int w,i,j;
        int ti=0,tj=0;
        for (int k = 0; k < m * n;) {
            if(!isUp) {
                i = 0;
                j = tj;
                vector<int> v;
                for(;i<n && j<m;i++,j++) {
                    v.push_back(mat[i][j]);
                    k++;
                }
                sort(v.begin(), v.end());
                w = 0;
                i = 0;
                j = tj;
                for(;i<n && j<m;i++,j++) {
                    mat[i][j] = v[w++];
                }
                tj++;
                if(tj==m){
                    isUp = !isUp;
                    ti++;
                }
            } else {
                i = ti;
                j = 0;
                vector<int> v;
                for(;i<n && j<m;i++,j++) {
                    v.push_back(mat[i][j]);
                    k++;
                }
                sort(v.begin(), v.end());
                w = 0;
                i = ti;
                j = 0;
                for(;i<n && j<m;i++,j++) {
                    mat[i][j] = v[w++];
                }
                ti++;
                if(ti==n){
                    isUp = !isUp;
                    tj++;
                }
            }
        }
        return mat;
    }
};