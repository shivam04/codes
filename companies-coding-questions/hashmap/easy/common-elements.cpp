vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    unordered_map<int,int> mp1, mp2;
    for(int n:A) {
        mp1[n]++;
    }

    for(int n:B) {
        mp2[n]++;
    }
    vector<int> ans;
    for(auto it: mp1) {
        int x = it.first;
        int cntA = it.second;
        int cntB = mp2[x];
        int cnt = min(cntA, cntB);
        for(int i=0;i<cnt;i++) {
            ans.push_back(x);
        }
    }
    return ans;
}
