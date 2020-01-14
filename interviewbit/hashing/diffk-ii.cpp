int Solution::diffPossible(const vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        int sum = A[i]+B;
        int diff = A[i]-B;
        if(mp.find(diff)!=mp.end())
            return 1;
        if(mp.find(sum)!=mp.end())
            return 1;
        mp[A[i]]=i;
    }
    return 0;
}