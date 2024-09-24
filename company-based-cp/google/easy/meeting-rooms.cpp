class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return true;
        }
        sort(intervals.begin(), intervals.end(), [](auto a, auto b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });

        auto prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            auto curr = intervals[i];
            if (prev[1] > curr[0]) {
                return false;
            }
            prev = curr;
        }
        return true;
    }
};