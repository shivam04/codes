vector<int> Solution::lszero(vector<int> &A) {
    unordered_map<long,int> mp;
    int n = A.size();
    long sum = 0;
    int ans = 0;
    int ansi = -1;
    for(int i=0;i<n;i++) {
        sum += A[i];
        if(sum==0) {
            ans = i+1;
            ansi=0;
            continue;
        }
        if(mp.find(sum)!=mp.end()) {
            if(ans < (i-mp[sum])) {
                ans = i-mp[sum];
                ansi = mp[sum]+1;
            }
        } else {
            mp[sum]=i;
        }
    }
    vector<int> anss;
    if(ansi==-1)
        return {};
    for(int i=ansi;i<ansi+ans;i++) {
        anss.push_back(A[i]);
    }
    return anss;
}
