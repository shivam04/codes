class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts, ends;
        for (auto i : intervals) {
            starts.push_back(i[0]);
            ends.push_back(i[1]);
        }
        sort(begin(starts), end(starts));
        sort(begin(ends), end(ends));
        int n = intervals.size();
        int ans = 1;
        int confRoomReq = 1;
        int res = 1;
        int i = 1, j = 0;
        while (i < n and j < n) {
            if (starts[i] < ends[j]) {
                confRoomReq++;
                i++;
            } else if (starts[i] >= ends[j]) {
                confRoomReq--;
                j++;
            }
            res = max(res, confRoomReq);
        }
        return res;
    }
};