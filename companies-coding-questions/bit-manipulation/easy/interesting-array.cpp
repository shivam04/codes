string Solution::solve(vector<int> &A) {
    int n = A.size();
    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(A[i]%2)
            cnt++;
    }
    if(cnt%2==0)
        return "Yes";
    return "No";
}
