int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    int oneP = 0;
    for(int i=0;i<n;i++) {
        if(A[i]==1) {
            oneP = 1;
            break;
        }
    }
    if(oneP == 0) {
        return 1;
    }

    for(int i=0;i<n;i++) {
        if(A[i]<=0 or A[i] > n) {
            A[i] = 1;
        }
    }
    for(int i=0;i<n;i++) {
        A[(A[i]-1)%n] += n;
    }
    for(int i=0;i<n;i++) {
        if(A[i]<=n)
            return i+1;
    }
    return n+1;
}
