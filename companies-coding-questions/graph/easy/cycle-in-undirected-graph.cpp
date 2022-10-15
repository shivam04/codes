int isCycle(unordered_map<int, vector<int>> &graph, vector<int> &visit, int s, int parent) {
    visit[s] = 1;
    for(int t: graph[s]) {
        if(visit[t]==0) {
            if(isCycle(graph, visit, t, s))
                return 1;
        } else if(t != parent)
            return 1;
    }
    return 0;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> color(A+1, -1);
    int mod = 1e9+7;
    unordered_map<int, vector<int>> graph;
    for(vector<int> e: B) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    vector<int> visit(A+1, 0);
    for(int i=1;i<=A;i++) {
        if(visit[i]==0) {
            if(isCycle(graph, visit, i, -1))
                return 1;
        }
    }
    return 0;
}
