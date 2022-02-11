class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> g[n];
        for(vector<int> edge: edges) {
            g[edge[0]-1].push_back(edge[1]-1);
            g[edge[1]-1].push_back(edge[0]-1);
        }
        vector<pair<int,int>> dist(n, {1000000000, 1000000000});
        vector<bool> vis(n, false);
        multiset < pair < int , int > > s;
        s.insert({0,0});
        while(!s.empty()) {
            pair<int,int> p = *s.begin();
            s.erase(s.begin());
            int x = p.second; int currTime = p.first;
            if(dist[x].second < currTime) continue; 
            int wait = 0;
            if((currTime/change)%2==1) {
                wait = change - (currTime%change);
            }
            int nextTime  = wait + time + currTime;
            for(auto e: g[x]) {
                if(dist[e].first > nextTime) {
                    dist[e].first = nextTime;
                    s.insert({nextTime, e});
                } else if(dist[e].second > nextTime and dist[e].first < nextTime) {
                    dist[e].second = nextTime;
                    if(e==n-1) return nextTime;
                    s.insert({nextTime, e});
                }
            }
        }
        return -1;
    }
};