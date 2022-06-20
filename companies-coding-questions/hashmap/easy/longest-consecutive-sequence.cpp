int Solution::longestConsecutive(const vector<int> &A) {
    unordered_map<int,int> mp;
    set<int> u;

    for(int n: A) {
        mp[n]++;
        u.insert(n);
    }
    vector<int> unq(u.begin(), u.end());
    int ans = 1;
    int i =0;
    while(i<unq.size()) {
        int j = 0;
        int k = unq[i];
        while(1) {
            int tp = j+k;
            if(mp[tp]==0) break;
            mp[tp]--;
            j++;
        }
        ans = max(ans, j);
        while(i<unq.size() and mp[unq[i]]==0) i++;
    }
    return ans;
}
