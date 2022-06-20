//O(n^2)
int palindrome(string s) {
    
    for(int i=0;i<s.size()/2;i++) {
        if(s[i]!=s[s.size()-i-1])
        return 0;
    }
    return 1;
}
int Solution::solve(string A) {
    reverse(A.begin(), A.end());
    int l=A.size();
    if(palindrome(A)==1)
        return 0;
    int c=0;
    while(l--) {
        string s=A.substr(++c);
        if(palindrome(s)==1) {
            break;
        }
    }
    return c;
}


//O(n)
int Solution::solve(string A) {
    string a = A + "#";
    reverse(A.begin(),A.end());
    a += A;
    int N = A.length();
    int n = a.length();
    vector<int> lps(n,0);
    int len = 0;
    int i = 1;
    while(i<n) {
        if(a[len]==a[i]) {
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
    int L = lps[n-1];
    return N-L;
}