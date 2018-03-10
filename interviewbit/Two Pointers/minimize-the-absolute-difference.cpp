int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i = 0,j = 0,k = 0;
    int p = A.size();
    int q = B.size();
    int r = C.size();
    int res = INT_MAX;
    while(i<p and j<q and k<r){
        int mini = min(A[i],min(B[j],C[k]));
        int maxi = max(A[i],max(B[j],C[k]));
        if(maxi-mini<res){
            res = maxi-mini;   
        }
        if(res==0)
        return res;
        if(A[i]==mini)i++;
        else if(B[j]==mini)j++;
        else k++;
    }
    return res;
}