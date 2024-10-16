class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<int> ans;
        vector<vector<int>> yToXs(101);
        for (vector<int>& r : rectangles) {
            yToXs[r[1]].push_back(r[0]);
        }

        for (auto &xs: yToXs) {
            sort(xs.begin(), xs.end());
        }
        
        for (vector<int>& p : points) {
            int count = 0;
            for (int y s= p[1]; y < 101; ++y) {
                vector<int>& xs = yToXs[y];
                count += xs.end() - lower_bound(xs.begin(), xs.end(), p[0]);
            }
            ans.push_back(count);
        }

        return ans;
    }
};