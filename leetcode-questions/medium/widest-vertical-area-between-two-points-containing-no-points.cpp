class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });

        int n = points.size();
        int cnt = 0;
        for (int i=0;i<n-1;i++) {
            cnt = max(cnt, points[i+1][0] - points[i][0]);
        }
        return cnt;
    }
};