class Graph {
    int V;
    vector<vector<int>> graph;
    vector<int> visit;
    vector<vector<int>> studentBatches;
    public:
        Graph(int V) {
            this->V = V;
            graph.resize(V+1);
            visit.resize(V+1, 0);
        }

        void addNode(int u, int v) {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> visitNodesInConnection(int source) {
            queue<int> q;
            q.push(source);
            vector<int> batch;
            batch.push_back(source);
            while(!q.empty()) {
                int s = q.front();
                q.pop();
                visit[s] = 1;
                for(int t: graph[s]) {
                    if(visit[t]==0) {
                        batch.push_back(t);
                        visit[t] = 1;
                        q.push(t);
                    }
                }
            }
            return batch;
        }

        void numberOfNodesPresentInConnection() {
            for(int i=1;i<=V;i++) {
                if(visit[i]==0) {
                    studentBatches.push_back(visitNodesInConnection(i));
                }
            }
        }

        vector<vector<int>> getVisitStatus() {
            return studentBatches;
        }
};

int Solution::solve(int A, vector<int> &B, vector<vector<int> > &C, int D) {
    Graph graph = Graph(A);
    for(int i=0;i<C.size();i++) {
        graph.addNode(C[i][0], C[i][1]);
    }
    graph.numberOfNodesPresentInConnection();
    vector<vector<int>> studentsInBatches = graph.getVisitStatus();
    int ans = 0;
    for(auto it: studentsInBatches) {
        int strength = 0;
        for(int student: it) {
            strength += B[student-1];
        }
        ans += (strength>=D);
    }
    return ans;
}
