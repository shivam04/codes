int Solution::solve(vector<int> &A) {
    map<int,int> mp;
    int n = A.size();
    for(int i=0;i<n;i++) {
        mp[A[i]] = i;
    }
    vector<int>temp = A;
    int ans = 0;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++) {
        if(A[i] != temp[i]) {
            ans++;
            int init = A[i];
            swap(A[i],A[mp[temp[i]]]);
            mp[init] = mp[temp[i]];
            mp[temp[i]] = i;
        }
    }
    return ans;
}
