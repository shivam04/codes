string Solution::smallestPrefix(string A, string B) {
    char p = B[0];
    string ans = "";
    ans.push_back(A[0]);
    int i = 1;
    while(i<A.size()) {
        if(A[i]>=p)
        break;
        ans += A[i];
        i++;
    }
    return ans+p;
}
