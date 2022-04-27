vector<int> Solution::flip(string ss) {
    vector<int> ans;
    int n = ss.size();
    int c = 0;
    int A[n];
    for(int i=0;i<n;i++) {
        c += (ss[i]=='1');
        A[i] = (ss[i]=='1') ? -1 : 1;
    }
    if(c==n) {
        return ans;
    }

    int cmax = 0;
    int smax = INT_MIN;
    int s = 0;
    int e = 0;
    int start = 0;
    for(int i=0;i<n;i++) {
        cmax += A[i];
        if(cmax < 0) {
            start = i+1;
            cmax = 0;
        }
        if(cmax > smax) {
            smax = cmax;
            s = start;
            e = i;
        }
    }
    ans.push_back(s+1);
    ans.push_back(e+1);
    return ans;
}
