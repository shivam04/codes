class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cS = 0;
        int rC[m+1];
        int cC[n+1];
        memset(rC, 0, sizeof(rC));
        memset(cC, 0, sizeof(cC));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    cS++;
                    rC[i]++;
                    cC[j]++;
                }
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    if(rC[i]==1 and cC[j]==1) {
                        cS--;
                    }
                }
            }
        }
        return cS;
    }
};