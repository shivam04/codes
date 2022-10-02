int mod = 1000000007;
unordered_map<int,int> dp;
int solve(int i, string s) {
    if(i==s.length()-1)
        return 1;
    if(s[i] == '0')
        return 0;
    if(dp.find(i) != dp.end())
        return dp[i];
    int ans = solve(i+1, s)%mod;
    if(stoi(s.substr(i,2))<=26) {
        ans = (ans%mod + solve(i+2, s)%mod);
    }
    return dp[i] = ans%mod;
}
int Solution::numDecodings(string A) {
    dp.clear();
    return solve(0, A);
}
