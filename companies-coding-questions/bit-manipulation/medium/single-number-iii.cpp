vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    int xoar = 0;
    for(int i=0;i<n;i++) {
        xoar ^= A[i];
    }
    int x=0,y=0;
    int cb = xoar & ~(xoar-1);
    for(int i=0;i<n;i++) {
        if(A[i]&cb)
            x ^= A[i];
        else
            y ^= A[i];
    }
    vector<int> ans = {x,y};
    sort(ans.begin(), ans.end());
    return ans;
}
