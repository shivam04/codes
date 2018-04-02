vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int,int> mp;
    vector<int> p;
    for(int i=0;i<A.size();i++){
        int diff = B - A[i];
        if(mp.find(diff)!=mp.end()){
            p.push_back(mp[diff]);
            p.push_back(i+1);
            return p;
        }
        if(mp[A[i]]==0)
        mp[A[i]]=i+1;
    }
    return p;
}
