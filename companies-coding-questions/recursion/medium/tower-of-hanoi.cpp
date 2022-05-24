void towerOfHanoiUtil(vector<vector<int> > &ans, int n, int a, int b, int c) {
    if(n==0)
        return;
    towerOfHanoiUtil(ans, n-1,a,c,b);
    ans.push_back({n,a,b});
    towerOfHanoiUtil(ans,n-1, c,b,a);
}
vector<vector<int> > Solution::towerOfHanoi(int A) {
    vector<vector<int> > ans;
    towerOfHanoiUtil(ans, A, 1,3,2);
    return ans;
}
