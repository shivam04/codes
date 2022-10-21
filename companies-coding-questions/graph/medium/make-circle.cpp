class Graph {
    int V;
    vector<vector<int>> graph;
    vector<int> ino;
    vector<int> visit;
    public:
        Graph(int V) {
            this->V = V;
            graph.resize(V);
            ino.resize(V, 0);
            visit.resize(V, 0);
        }
        void addEdge(int a, int b) {
            graph[a].push_back(b);
            ino[b]++;
        }

        void dfs(int s) {
            visit[s] = 1;
            for(int t : graph[s]) {
                if(!visit[t])
                    dfs(t);
            }
        }

        Graph getTranspose() {
            Graph gr(V);
            for(int i=0;i<V;i++) {
                for(int s: graph[i]) {
                    gr.addEdge(s, i);
                }
            }
            return gr;
        }

        bool isSC() {
            int n;
            for (n = 0; n < V; n++) {
                if(graph[n].size() > 0)
                    break;
            }
            dfs(n);
            for(int i=0;i<V;i++) {
                if(graph[i].size()>0 and !visit[i])
                    return false;
            }
            Graph gr = getTranspose();
            gr.dfs(n);
            for (int i = 0; i < V; i++) {
                if (graph[i].size() > 0 && !visit[i])
                    return false;
            }
            return true;
        }

        bool isEulerCircuit() {
            if(!isSC())
                return false;
            for(int i=0;i<V;i++) {
                if(graph[i].size() != ino[i])
                    return false;
            }
            return true;
        }
};
int Solution::solve(vector<string> &A) {
    Graph graph(26);
    for(string a : A) {
        graph.addEdge(a[0] - 'a', a.back() - 'a');
    }
    return graph.isEulerCircuit();
}
