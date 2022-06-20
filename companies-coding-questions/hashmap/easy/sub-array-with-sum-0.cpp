int Solution::solve(vector<int> &A) {
    unordered_map<long,int> mp;
    mp[0] = 1;
    int n = A.size();
    long sum = 0;
    for(int i=0;i<n;i++) {
        sum += A[i];
        if(mp.find(sum)!=mp.end())
            return 1;
        mp[sum]=1;
    }
    return 0;
}
