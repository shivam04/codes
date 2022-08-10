int Solution::candy(vector<int> &A) {
    vector<int> l,r;
    int n = A.size();
    l.resize(n,1);
    for(int i=1;i<A.size();i++) {
        if(A[i]>A[i-1]) {
            l[i] = l[i-1]+1;
        } 
    }

    

    r.resize(n,1);
    r[n-1] = 1;
    for(int i=n-2;i>=0;i--) {
        if(A[i]>A[i+1]) {
            r[i] = r[i+1]+1;
        }
    }

    int sum = 0;

    for(int i=0;i<n;i++) {
        sum += max(l[i],r[i]);
    }
    return sum;

}
