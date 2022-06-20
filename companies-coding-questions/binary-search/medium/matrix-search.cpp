//O(n)
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n = A.size();
    int m = A[0].size();
    int i = 0,j=m-1;
    while(i<n and j>=0) {
        if(A[i][j]==B)
            return true;
        if(B < A[i][j]) 
            j--;
        else i++;
    }
    return 0;
}

//O(log(n))
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n = A.size();
    int m = A[0].size();
    int l = 0, r = m * n - 1;
    while(l!=r) {
        int mid = (l + r - 1) >> 1;
        if (A[mid / m][mid % m] < B)
            l = mid + 1;
        else
            r = mid;
    }
    return A[r / m][r % m]==B;
}