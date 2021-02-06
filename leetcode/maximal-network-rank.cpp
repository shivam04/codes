class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        bool connected[n+1][n+1];
        int cnt[n+1];
        memset(connected, false, sizeof(connected));
        memset(cnt, 0, sizeof(cnt));
        for(vector<int> road : roads) {
            cnt[road[0]]++;
            cnt[road[1]]++;
            connected[road[0]][road[1]] = true;
            connected[road[1]][road[0]] = true;
        }
        int res = 0;
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                res = max(res, cnt[i] + cnt[j] - (connected[i][j] ? 1 : 0));
            }
        }
        return res;
    }
};