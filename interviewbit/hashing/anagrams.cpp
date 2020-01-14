vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int> > v;
    unordered_map<string,vector<int>> mp;
    for(int i=0;i<A.size();i++){
        string g = A[i];
        sort(g.begin(),g.end());
        mp[g].push_back(i+1);
    }
    for(auto it=mp.begin();it!=mp.end();++it){
        v.push_back(it->second);
    }
    return v;
}