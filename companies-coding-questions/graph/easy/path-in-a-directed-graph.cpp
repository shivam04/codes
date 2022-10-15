int pathExist(unordered_map<int, vector<int>> &g, int s, int t, unordered_map<int, int> &visit) {
    if(s==t) {
        return 1;
    }
    if(visit[s]==1)
        return 0;
    visit[s] = 1;
    for(auto u: g[s]) {
        if(pathExist(g, u, t, visit))
            return 1;
    }
    return 0;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    unordered_map<int, vector<int>> g;
    unordered_map<int, int> visit;
    for(vector<int> e: B) {
        g[e[0]].push_back(e[1]);
    }
    return pathExist(g, 1, A, visit);
}
