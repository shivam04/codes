vector<int> Solution::solve(vector<vector<int> > &A) {
    unordered_map<int,int> mp;
    unordered_map<int, stack<int>> s;
    vector<int> ans;
    int maxF = 0;
    for(vector<int> a: A) {
        int t = a[0];
        int x = a[1];
        if(t==1) {
            mp[x]++;
            int p = mp[x];
            s[p].push(x);
            maxF = max(maxF, mp[x]);
            ans.push_back(-1);
        } else {
            int p = s[maxF].top();
            ans.push_back(p);
            mp[p]--;
            s[maxF].pop();
            if(s[maxF].empty())
                maxF--;
        }
    }
    return ans;
}
