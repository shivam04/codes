bool check(string s) {
    for (int i = 0; i + 1 < s.size(); ++i)
        if (abs(s[i] - s[i + 1]) == 1)
            return false;
    return true;
}
int Solution::solve(string A) {
    string odd = "", even = "";
    for(int i=0;i<A.size();i++) {
        if(A[i]%2) {
            odd += A[i];
        } else {
            even += A[i];
        }
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    if(check(odd+even)) {
        return 1;
    }
    if(check(even+odd)) {
        return 1;
    }
    return 0;
}