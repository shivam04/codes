int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    for(int i=0;i<A.size()-1;i++) {
        if(A[i+1]-A[i]>1 || A[i+1]-A[i]<=0)
            return 0;
    }
    return 1;

}
