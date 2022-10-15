class Graph {
    int V;
    vector<pair<int, int>> *graph;
    public:
        Graph(int V) {
            this->V = V;
            graph = new vector<pair<int,int>>[V+1];
        }

        void addEdge(int u, int v, int w) {
            graph[u].push_back({w,v});
        }

        void modelGraphWithEdgeWeight(vector<vector<int> > &edges) {
            for (vector<int> edge: edges) {
                addEdge(edge[0], edge[1], 0);
                addEdge(edge[1], edge[0], 1);
            }
        }

        vector<int> shortestPath(int source) {
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
            vector<int> dist(V+1, INT_MAX);
            dist[source] = 0;
            minHeap.push({0, source});
            while(!minHeap.empty()) {
                auto temp = minHeap.top();
                minHeap.pop();
                int x = temp.second; int wei = temp.first;
                for(auto nei: graph[x]) {
                    int y = nei.second;
                    int weight = nei.first;
                    if(dist[y] > dist[x] + weight) {
                        dist[y] = dist[x] + weight;
                        minHeap.push({dist[y], y});
                    }
                }
            }
            return dist;
        }

        int getMinEdgeReversal() {
            vector<int> dist = shortestPath(1);
            if (dist[V]==INT_MAX)
                return -1;
            return dist[V];
        }
};
int Solution::reverseEdges(int A, vector<vector<int> > &B) {
    Graph g(A);
    g.modelGraphWithEdgeWeight(B);
    return g.getMinEdgeReversal();
}