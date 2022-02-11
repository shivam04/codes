class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(rStart);
        temp.push_back(cStart);
        ans.push_back(temp);
        temp.clear();
        if (rows * cols == 1) return ans;
        for (int k = 1; k < 2*(rows+cols); k += 2) {
            for (int i = 0; i < 4; ++i) { 
                int dk = k + (i / 2);
                for (int j = 0; j < dk; ++j) {
                    rStart += dr[i];
                    cStart += dc[i];
                    if (0 <= rStart && rStart < rows && 0 <= cStart && cStart < cols) {
                        temp.push_back(rStart);
                        temp.push_back(cStart);
                        ans.push_back(temp);
                        temp.clear();
                        if (ans.size() == rows * cols) return ans;
                    }
                }
            }
        }
        return ans;
    }
};