int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i = 0,j = 0,k = 0;
    int p = A.size();
    int q = B.size();
    int r = C.size();
    int res = INT_MAX;
    while(i<p and j<q and k<r){
        int mini = min(A[i],min(B[j],C[k]));
        /*int maxi = max(A[i],max(B[j],C[k]));*/
        int tt = max(abs(A[i]-B[j]),max(abs(A[i]-C[k]),abs(B[j]-C[k])));
        if(tt<res){
            res = tt;   
        }
        if(res==0)
        return res;
        if(A[i]==mini)i++;
        else if(B[j]==mini)j++;
        else k++;
    }
    return res;
}
