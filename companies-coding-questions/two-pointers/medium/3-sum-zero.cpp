vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    set<vector<int>> anss;
    for(int i=0;i<n-2;i++) {
        int k = 0 - A[i];
        int l = i+1;
        int r = n-1;
        while(l<r) {
            if(A[l]+A[r]==k) {
                anss.insert({A[i], A[l], A[r]});
                l++;
                r--;
            } else if(A[l] + A[r] < k) {
                l++;
            } else {
                r--;
            }
        }
    }
    vector<vector<int> > ans(anss.begin(), anss.end());
    return ans;
}
