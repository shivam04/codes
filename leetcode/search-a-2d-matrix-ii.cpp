class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = 0;
        int n = matrix.size();
        if(n==0)
            return false;
        int m = matrix[0].size();
        if(m==0)
            return false;
        j = m-1;
        while(i<n and j>=0) {
            if(target < matrix[i][j]) {
                j--;
            } else if(target > matrix[i][j]) {
                i++;
            } else {
                return true;
            }
        }
        return false;
    }
};