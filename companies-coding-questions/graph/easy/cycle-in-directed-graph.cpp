bool isCyclic(int s, vector<int> &visit, vector<int> &recStack, unordered_map<int, vector<int>> &g) {
    if(visit[s]==0) {
        visit[s] = 1;
        recStack[s] = 1;
        for(auto t: g[s]) {
            if(!visit[t] and isCyclic(t, visit, recStack, g))
                return true;
            else if(recStack[t])
                return true;
        }
    }
    recStack[s] = 0;
    return false;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> visit(A+1, 0);
    vector<int> recStack(A+1, 0);
    unordered_map<int, vector<int>> mp;
    for(vector<int> e: B) {
        mp[e[0]].push_back(e[1]);
    }
    for(int i = 1; i <=A ; i++) {
        if(!visit[i] and isCyclic(i, visit, recStack, mp))
            return 1;
    }
    return 0;
}
