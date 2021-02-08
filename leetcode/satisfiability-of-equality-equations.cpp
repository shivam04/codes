class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> g[26];
        for(string equation : equations) {
            if(equation[1]=='=') {
                int x = equation[0] - 'a';
                int y = equation[3] - 'a';
                g[x].push_back(y);
                g[y].push_back(x);
            }
        }
        int color[26];
        memset(color, 0, sizeof(color));
        int t = 0;
        for(int i=0;i<26;i++) {
            if(color[i]==0) {
                t++;
                queue<int> q;
                q.push(i);
                while(!q.empty()) {
                    int u = q.front();
                    q.pop();
                    color[u] = t;
                    for(int v : g[u]) {
                        if(color[v]==0) {
                            q.push(v);
                        }
                    }
                }
            }
        }
        for(string equation : equations) {
            if(equation[1]=='!') {
                int x = equation[0] - 'a';
                int y = equation[3] - 'a';
                if(x==y || (color[x] != 0 and color[x] == color[y]))
                    return false;
            }
        }
        return true;
    }
};