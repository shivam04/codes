int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i=0,j=0,k=0;
    int p = A.size();
    int q = B.size();
    int r = C.size();
    int diff = INT_MAX;
    while(i<p and j<q and k<r) {
        int mini = min({A[i], B[j], C[k]});
        int maxi = max({A[i], B[j], C[k]});
        if(maxi - mini < diff) {
            diff = maxi-mini;
        }
        if(A[i]==mini) i++;
        else if(B[j] == mini) j++;
        else k++;
    }
    return diff;
}