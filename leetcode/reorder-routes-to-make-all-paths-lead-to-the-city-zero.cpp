class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> graph[n+1];
        map<string,int> mp;
        for(int i=0;i<connections.size();i++) {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
            mp[to_string(connections[i][0]) + "#" + to_string(connections[i][1])] = 1;
        }
        vector<int> visit(n+1);
        for(int i=0;i<=n;i++)
            visit[i]=0;
        queue<int> q;
        q.push(0);
        int c=0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            visit[u] = 1;
            for(auto v: graph[u]) {
                if(!visit[v]) {
                    if(mp[to_string(u)+"#"+to_string(v)]==1)
                        c++;
                    q.push(v);
                }
            }
        }
        return c;
    }
};