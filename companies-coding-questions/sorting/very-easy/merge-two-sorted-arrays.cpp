vector<int> Solution::solve(const vector<int> &A, const vector<int> &B) {
    vector<int> C;
    int n = A.size();
    int m = B.size();
    int i=0,j=0;
    while(i<n and j<m) {
        if(A[i]<B[j])
            C.push_back(A[i++]);
        else
            C.push_back(B[j++]);
    }

    while(i<n) {
        C.push_back(A[i++]);
    }

    while(j<m) {
        C.push_back(B[j++]);
    }
    return C;
}
