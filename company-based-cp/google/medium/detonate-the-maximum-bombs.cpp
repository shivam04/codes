class Solution {
public:
    auto getDistance(vector<int> bomb, vector<int> recentBomb) {
        return hypotl(bomb[0]-recentBomb[0], bomb[1]-recentBomb[1]);
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int maxDenoted = 0;
        int n = bombs.size();
        vector<int> g[n];
        for (int i = 0; i < n; ++i) { 
            int cntDenoted = 0;
            for (int j = i+1; j < n; ++j) {
                auto& p1 = bombs[i];
                auto& p2 = bombs[j];
                auto dist = getDistance(p1, p2);
                if (dist <= p1[2]) {
                    g[i].push_back(j);
                }
                if (dist <= p2[2]) {
                    g[j].push_back(i);
                }
            }
            maxDenoted = max(maxDenoted, cntDenoted);
        }
        int ans = 0;
        bool vis[n];
        for (int k=0;k<n;k++) {
            memset(vis, false, sizeof(vis));
            queue<int> q;
            q.push(k);
            vis[k] = true;
            int cnt = 0;
            while (!q.empty()) {
                int i = q.front();
                q.pop();
                ++cnt;
                for (int j : g[i]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }
                if (cnt == n) {
                    return n;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};