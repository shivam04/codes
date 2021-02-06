class Solution {
public:
    bool isInsideGrid(int a,int b, int n, int m) {
        return (a >= 0 && a < n && b >= 0 && b < m);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        multiset<pair<int, pair<int,int>>> s;
        
        int dx[] = {-1, 0, 1, 0}; 
        int dy[] = {0, 1, 0, -1}; 
        s.insert({0,{0,0}});
        int maxi = 0;
        vector<vector<bool>> visit(n+1,vector<bool>(m+1,0));
        while(!s.empty()) {
            pair<int,pair<int,int>> t = *s.begin();
            int x = t.second.first;
            int y = t.second.second;
            s.erase(s.begin()); 
            if(!visit[x][y]) {
                visit[x][y] = 1;
                maxi = max(maxi, t.first);
                if(x==n-1 and y==m-1)
                    return maxi;
                for(int i=0;i<4;i++) {
                    int xx = x + dx[i];
                    int yy = y + dy[i];
                    if(!isInsideGrid(xx, yy,n,m)) {
                        continue;
                    }
                    int diff = abs(heights[xx][yy] - heights[x][y]);
                    s.insert({diff,{xx,yy}});
                }
            }
        }
        return maxi;
    }
};