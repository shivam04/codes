//using z algorithm
int Solution::solve(string A) {
    string s = A;
    int n = s.length();
    vector<int> Z(n,0);
    int L = 0, R = 0;
    for(int i=1;i<n;i++) {
        if(i>R) {
            L=R=i;
            while (R < n && s[R-L] == s[R]) {
                R++;
            }
            Z[i] = R-L; 
            R--;
        } else {
            int k = i-L;
            if(Z[k] < R-i+1) {
                Z[i] = Z[k];
            } else {
                L = i;
                while(R<n && s[R-L]==s[R]) {
                    R++;
                }
                Z[i] = R-L;
                R--;
            }
        }
    }
    for(int i=0;i<n;i++) {
        if(Z[i]==n-i)
            return i;
    }
    return n;
}

//using lps
int Solution::solve(string A) {
    string s = A;
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
    return n - lps[n-1];
}