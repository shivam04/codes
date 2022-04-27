int Solution::solve(vector<vector<int> > &A, int B) {
    int small = A[0][0];
    int n = A.size();
    int m = A[0].size();
    int large = A[n-1][m-1];
    if(B < small or B > large)
        return -1;
    int i = 0, j = m - 1;
    while(i<n and j>=0) {
        if(A[i][j] == B) {
            if(i>0 and A[i-1][j] == B) {
                i--;
            } else if(j>0 and A[i][j-1] == B) {
                j--;
            } else {
                return (i+1)*1009+j+1;
            }
        }
        else if(A[i][j] > B) {
            j--;
        } else {
            i++;
        }
    }
    return -1;
}
