int Solution::solve(vector<int> &A, vector<int> &B) {
    vector<pair<int,int>> p;
    int n = A.size();
    for(int i=0;i<n;i++) {
        p.push_back({A[i], B[i]});
    }
    sort(p.begin(),p.end(), [](pair<int,int> a, pair<int,int> b) {
        if(a.first==b.first)
            return a.second < b.second;
        return a.first < b.first;
    });
    map<pair<int,int>,int> mp;
    for(int i=0;i<n;i++) {
        int k = p[i].first;
        vector<int> y;
        while(i<n and p[i].first==k) {
            y.push_back(p[i].second);
            i++;
        }
        i--;
        for(int a=0;a<y.size();a++) {
            for(int b=a+1;b<y.size();b++) {
                mp[{y[a],y[b]}]++;
            }
        }
    }
    int ans = 0;
    for(auto it: mp) {
        int xs = it.second;

        ans += (xs*(xs-1)/2);
    }
    return ans;
}
