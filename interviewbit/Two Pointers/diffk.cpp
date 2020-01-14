int Solution::diffPossible(vector<int> &A, int B) {
    int n=A.size();
    int p=0,q=0;
    while(q<n){
        if(q==p)
            q++;
        else if(A[q]-A[p]==B && q!=p)
            return 1;
        else if(A[q]-A[p]>B)
            p++;
        else if(A[q]-A[p]<B)
            q++;
    }
    return 0;
}