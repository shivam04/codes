int Solution::solve(vector<int> &A) {
    int ans = INT_MAX;
    unordered_map<int,int> mp;
    for(int i=0;i<A.size();i++) {
        if(mp.find(A[i])!=mp.end()) {
            ans = min(ans, i-mp[A[i]]);
        }
        mp[A[i]]=i;
    }
    return ans == INT_MAX ? -1 : ans;
}