int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<int> prefix(n,0), suffix(n,0);
    prefix[0] = A[0];
    suffix[n-1] = A[n-1];
    for(int i=1;i<n;i++) {
        prefix[i] += (prefix[i-1] + A[i]);
    }

    for(int i=n-2;i>=0;i--) {
        suffix[i] += (suffix[i+1] + A[i]);
    }

    int maxSum = INT_MIN;
    for(int i=0;i<B;i++) {
        int p = n-B+i+1;
        int q = 0;
        if(p<n) {
            q = suffix[p];
        }
        //cout<<i<<" "<<p<<" "<<(q+prefix[i])<<"\n";
        maxSum = max(maxSum, prefix[i] + q);
    }

    for(int i=n-1;i>=n-B;i--) {
        int p = B - (n-i) - 1;
        int q = 0;
        if(p>=0) {
            q = prefix[p];
        }
        //cout<<i<<" "<<p<<" "<<(q+suffix[i])<<"\n";
        maxSum = max(maxSum, suffix[i] + q);
    }

    return maxSum;
}
