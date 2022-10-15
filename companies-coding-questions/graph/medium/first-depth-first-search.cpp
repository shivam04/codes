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
   
int Solution::solve(vector<int> &A, const int B, const int C) {
    unordered_map<int, vector<int>> g;
    unordered_map<int, int> visit;
    for(int i=0;i<A.size();i++) {
        g[A[i]].push_back(i+1);
    }
    return pathExist(g, C, B, visit);
}
