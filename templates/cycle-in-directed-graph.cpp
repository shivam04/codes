class Graph {
    int V;
    list<int>* adj;
    bool isCyclicUtil(int v, bool visited[], bool* rs);

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool* rs) {
    if (!visited[v]) {
        visited[v] = true;
        rs[v] = true;
        for(auto u: adj[v]) {
            if (!visited[u] && isCyclicUtil(u, visited, rs)) {
                return true;
            } else if (rs[u]) {
                return true;
            }
        }
    }

    rs[v] = false;
    return false;
}

bool Graph::isCyclic() {
    bool* visited = new bool[V];
    bool* recStack = new bool[V];

    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i] && isCyclicUtil(i, visited, recStack)) {
            return true;
        }
    }
    return false;
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses);
        vector<int> graph[numCourses];

        for(vector<int> prerequisite: prerequisites) {
            int a = prerequisite[1];
            int b = prerequisite[0];
            g.addEdge(a, b);
        }

        return !g.isCyclic();
    }
};