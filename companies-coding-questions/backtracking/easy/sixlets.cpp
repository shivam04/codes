void findANS(vector<int> &A, int B, int s, int &ans, int sum) {
    if(sum>1000)
        return;
    if(B<0)
        return;
    if(B==0 and sum<=1000) {
        ans++;
        return;
    }
    if(s>=A.size())
        return;
    findANS(A, B-1, s+1, ans, sum+A[s]);
    findANS(A, B, s+1, ans, sum);
}
int Solution::solve(vector<int> &A, int B) {
    int ans = 0;
    findANS(A, B, 0, ans, 0);
    return ans;
}
