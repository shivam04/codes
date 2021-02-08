class Solution {
public:
    bool isBipartiteUtil(vector<vector<int>>& graph, int s, int color[]) {
        color[s] = 1;
        queue<int> q; 
        q.push(s); 
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v : graph[u]) {
                if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if(color[u]==color[v])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        memset(color, -1, sizeof(color));
        for(int i=0;i<n;i++) {
            if(color[i] == -1) {
                if(!isBipartiteUtil(graph, i, color))
                    return false;
            }
        }
        return true;
    }
};