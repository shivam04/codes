/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool doesOverlap(Interval a, Interval b) {
    return (min(a.end, b.end) >= max(a.start, b.start));
}
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> ans;
    int n = intervals.size();
    if (n == 0) {
        ans.push_back(newInterval);
        return ans;
    }
    if (newInterval.end < intervals[0].start ||
            newInterval.start > intervals[n - 1].end) {
        if (newInterval.end < intervals[0].start)
            ans.push_back(newInterval);
 
        for (int i = 0; i < n; i++)
            ans.push_back(intervals[i]);
 
        if (newInterval.start > intervals[n - 1].end)
            ans.push_back(newInterval);
 
        return ans;
    }

    if (newInterval.start <= intervals[0].start &&
        newInterval.end >= intervals[n - 1].end){
        ans.push_back(newInterval);
        return ans;
    }
    bool overlap = true;
    for (int i = 0; i < n; i++) {
        overlap = doesOverlap(intervals[i], newInterval);
        if(!overlap) {
            ans.push_back(intervals[i]);
            if (i < n &&
                newInterval.start > intervals[i].end &&
                newInterval.end < intervals[i + 1].start)
                ans.push_back(newInterval);
            continue;
        }
        Interval temp;
        temp.start = min(newInterval.start,intervals[i].start);
        while (i < n && overlap) {
            temp.end = max(newInterval.end, intervals[i].end);
            if (i == n - 1)
                overlap = false;
            else
                overlap = doesOverlap(intervals[i + 1],
                                          newInterval);
            i++;
        }
        i--;
        ans.push_back(temp);
    }
    return ans;
}
