unordered_map<int, int> mp;
int mod = 1000000007;
int ans(int n, int p) {
    if(n<0)
        return 0;
    if(n<=1) {
        return 1;
    }
    if(mp.find(n) != mp.end())
        return mp[n];
    int anss = 0;
    for(int i=1;i<=min(n,p);i++) {
        anss = (anss%mod + (ans(n-i, 6))%mod)%mod;
    }
    return mp[n]=anss%mod;
}
int Solution::solve(int A) {
    mp.clear();
    return ans(A, 6);
    return mp[A];
}
