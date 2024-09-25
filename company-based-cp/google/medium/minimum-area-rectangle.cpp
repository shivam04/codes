class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_map<int, bool>> hashMap;
        for (auto point: points) {
            hashMap[point[0]][point[1]] = true;
        }

        int n = points.size();
        int ans = INT_MAX;
        for (int i=0;i<n;i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j=i+1;j<n;j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (x1 == x2 or y1 == y2) {
                    continue;
                }
                if (hashMap[x1].count(y2) and hashMap[x2].count(y1)) {
                    ans = min(ans, abs(x1 - x2) * abs(y1 - y2));
                }
            }
        }
        if (ans == INT_MAX) {  // no solution
            return 0;
        }
        return ans;
    }
};