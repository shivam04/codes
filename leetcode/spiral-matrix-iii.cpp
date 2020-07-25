class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(r0);
        temp.push_back(c0);
        ans.push_back(temp);
        temp.clear();
        if (R * C == 1) return ans;
        for (int k = 1; k < 2*(R+C); k += 2) {
            for (int i = 0; i < 4; ++i) { 
                int dk = k + (i / 2);
                for (int j = 0; j < dk; ++j) {
                    r0 += dr[i];
                    c0 += dc[i];
                    if (0 <= r0 && r0 < R && 0 <= c0 && c0 < C) {
                        temp.push_back(r0);
                        temp.push_back(c0);
                        ans.push_back(temp);
                        temp.clear();
                        if (ans.size() == R * C) return ans;
                    }
                }
            }
        }
        return ans;
    }
};