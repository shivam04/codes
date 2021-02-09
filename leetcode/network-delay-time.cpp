class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> g;
        for(vector<int> time : times) {
            g[time[0]].push_back({time[1], time[2]});
        }
        multiset < pair < int , int > > s;
        s.insert({0, k});
        int dist[n+1];
        for(int i=0;i<=n;i++) {
            dist[i] = 1e8;
        }
        dist[k] = 0;
        while(!s.empty()) {
            pair <int , int> p = *s.begin();
            s.erase(s.begin());
            int u = p.second;
            int w = p.first;
            for(auto e : g[u]) {
                int v = e.first; int w = e.second;
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    s.insert({dist[v], v});
                }
            }
        }
        int maxi = 0;
        for(int i=1;i<=n;i++) {
            if(dist[i] == 1e8)
                return -1;
            maxi = max(dist[i], maxi);
        }
        return maxi;
    }
};