class Graph {
    private:
        vector<vector<int>> g;
        vector<int> dist;
        vector<int> visit;
        queue<int> q;
        int n,m;
        int totalN;
    public:
        Graph(int a, int b) {
            n = a;
            m = b;
            totalN = n*m+1;
            dist.resize(totalN, INT_MAX);
            visit.resize(totalN, 0);
            g.resize(totalN);
            int k = 1;
        }

        void createGraph() {
            int k = 1;
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=m;j++) {
                    if (i == n) {
                        if (j!=m) {
                            g[k].push_back(k+1);
                            g[k+1].push_back(k);
                        }
                    } else if (j==m) {
                        g[k].push_back(k+m);
                        g[k+m].push_back(k);
                    } else {
                        g[k].push_back(k+1);
                        g[k+1].push_back(k);
                        g[k].push_back(k+m);
                        g[k+m].push_back(k);
                    }
                    k++;
                }
            }
        }

        void preProcess(vector<vector<int> > &mat) {
            int k = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (mat[i][j] == 1) {
                        dist[k] = 0;
                        visit[k] = 1;
                        q.push(k);
                    }
                    k++;
                }
            }
        }

        void bfs() {
            while (!q.empty()) {
                auto temp = q.front();
                q.pop();
                for(auto nei: g[temp]) {
                    if(visit[nei] == 0) {
                        dist[nei] = min(dist[nei], dist[temp]+1);
                        q.push(nei);
                        visit[nei] = 1;
                    }
                }
            }
        }

        vector<vector<int>> getDist() {
            vector<vector<int>> distance(n);
            int p = 0;
            for (int i = 1, c = 1; i < totalN; i++, c++) {
                distance[p].push_back(dist[i]);
                if(c%m==0) {
                    p++;
                }
            }
            return distance;
        }
};
vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    Graph graph(n, m);
    graph.createGraph();
    graph.preProcess(A);
    graph.bfs();
    return graph.getDist();
}
