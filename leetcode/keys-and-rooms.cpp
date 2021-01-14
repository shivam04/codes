class Solution {
public:
    vector<int> g[1001];
    bool visit[1001];
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        for(int i=0;i<n;i++) {
            vector<int> room = rooms[i];
            for(int v: room) {
                g[i].push_back(v);
            }
            visit[i] = false;
        }
        bool flag = false;
        for(int i=0;i<n;i++) {
            if(!visit[i]) {
                if(!flag) {
                    dfs(i);
                    flag = true;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
    void dfs(int s) {
        visit[s] = true;
        for(int v: g[s]) {
            if(!visit[v]) {
                dfs(v);
            }
        }
    }
};