typedef pair<long long, int> PII;
int mod = 1e9+7;
class Graph {
    int V;
    vector<vector<PII>> graph;
    vector<int> visit;
    public:
        Graph(int V) {
            this->V = V;
            graph.resize(V+1);
            visit.resize(V+1, 0);
        }

        void addNode(int u, int v, int w) {
            graph[u].push_back({w,v});
            graph[v].push_back({w,u});
        }

        long long prims(int source) {
            priority_queue<PII, vector<PII>, greater<PII> > Q;
            long long minCost = 0;
            Q.push({0, source});
            while(!Q.empty()) {
                auto p = Q.top();
                Q.pop();
                int x = p.second;
                if(visit[x] == 1) {
                    continue;
                }
                minCost += p.first;
                visit[x] = 1;
                for(auto nei: graph[x]) {
                    int y = nei.second;
                    if(visit[y] == 0) {
                        Q.push(nei);
                    }
                }
            }
            return minCost;
        }
};
int Solution::solve(int A, vector<vector<int> > &B) {
    Graph graph(A);
    for(vector<int> edge: B) {
        graph.addNode(edge[0], edge[1], edge[2]);
    }
    long long minCost = graph.prims(1);
    return minCost%(mod);
}
