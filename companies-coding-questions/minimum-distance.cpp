int Solution::solve(string A) {
    int lastXPos = 1000000;
    int lastOPos = 1000000;
    int ans = 1000000;
    for(int i=0;i<A.length();i++) {
        if(A[i]=='.') {
            continue;
        } else if(A[i]=='x') {
            lastXPos = i;
            ans = min(ans, abs(lastOPos-lastXPos));
        } else {
            lastOPos = i;
            ans = min(ans, abs(lastOPos-lastXPos));
        }
    }
    if(lastOPos==1000000 or lastXPos==1000000)
        return -1;
    return ans;
}
