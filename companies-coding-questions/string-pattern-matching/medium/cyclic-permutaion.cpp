int Solution::solve(string A, string B) {
    string s = A + "#" + B + B;
    s.pop_back();
    int n = s.length();
    vector<int> lps(n,0);
    int len = 0;
    int i = 1;
    while(i<n) {
        if(s[len]==s[i]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len>0) {
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        ans += (A.length()==lps[i]);
    }
    return ans;
}
