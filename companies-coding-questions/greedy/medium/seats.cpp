int Solution::seats(string A) {
    vector<int> position;
    int n = A.size();
    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(A[i]=='x') {
            position.push_back(i-cnt);
            cnt++;
        }
    }
    if(cnt==n or cnt==0)
        return 0;
    int midi = position[(cnt-1)/2];
    int ans = 0;
    int mod = 10000003;
    for(int i=0;i<position.size();i++) {
        ans = (ans%mod + (abs(position[i]-midi))%mod)%mod;
    }
    return ans;
}
