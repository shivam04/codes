unordered_map<int, int> mp;
int ans(int n, int p) {
    if(n<0)
        return 0;
    if(n<=3) {
        return n;
    }
    if(mp.find(n) != mp.end())
        return mp[n];
    int anss = INT_MAX;
    for(int i=1;i<=p;i++) {
        int g = n-i*i;
        if(g<0)
            continue;
        anss = min(anss,(ans(g, sqrt(g))+1));
    }
    return mp[n]=anss;
}
int Solution::countMinSquares(int A) {
    mp.clear();
    return ans(A, sqrt(A));
    return mp[A];
}
