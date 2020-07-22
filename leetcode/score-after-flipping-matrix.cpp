class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        int ans = 0;
        int ret = (1 << (m - 1)) * n;
        for(int j = 1; j < m; j++) {
            int cnt = 0;
            for(int i = 0; i < n; i++){
                cnt += (A[i][j] == A[i][0]);
            }
            cout<<cnt<<"\n";
            int temp = ((1 << (m - (j + 1))) * max(cnt, n - cnt));
            ret += temp;
        }
        return ret;
    }
};