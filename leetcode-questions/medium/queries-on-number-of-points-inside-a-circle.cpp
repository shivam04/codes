class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for (vector<int> q: queries) {
            int cnt = 0;
            for (vector<int> p: points) {
                float d =  sqrt(pow(q[0]-p[0], 2) + pow(q[1]-p[1], 2));
                cnt += (d <= q[2]);
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};