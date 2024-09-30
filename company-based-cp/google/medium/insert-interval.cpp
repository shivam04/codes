class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> newIntervals;
        while (i < n) {
            if (newInterval[0] < intervals[i][0]) {
                newIntervals.push_back(newInterval);
                newInterval[0] = INT_MAX;
                newInterval[1] = INT_MAX;
            }
            newIntervals.push_back(intervals[i++]);
        }
        if (newInterval[0] < INT_MAX) {
            newIntervals.push_back(newInterval);
        }
        vector<vector<int>> res = {newIntervals[0]};
        for(int i=1;i<newIntervals.size();i++) {
            vector<int> cm = newIntervals[i];
            vector<int> pm = res[res.size()-1];
            if(pm[1] >= cm[0]) {
                vector<int> nm = {pm[0], max(pm[1], cm[1])};
                res[res.size()-1] = nm;
            } else {
                res.push_back(cm);
            }
        }
        return res;
    }
};