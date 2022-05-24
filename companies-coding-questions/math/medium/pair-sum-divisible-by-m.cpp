int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int mod = 1e9+7;
    unordered_map<int,long> mp;
    long ans = 0;
    for(int i=0;i<n;i++) {
        int r = A[i]%B;
        ans = (ans%mod + mp[(B-r)%B]%mod)%mod;
        mp[r]++;
    }
    return ans%mod;
}
