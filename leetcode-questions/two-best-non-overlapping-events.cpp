class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](auto& a, auto& b) {
           return a[0] < b[0];
        });
        map<int, int> mp;
        int v = events.back()[2];
        map<int,int> m; 
        for(int i = events.size()-1;i>=0;i--) {
            v = max(v,events[i][2]);
            m[events[i][0]] = v; 
        }
        sort(events.begin(),events.end(),[](auto& a, auto& b) {
           return a[1] < b[1];
        });
        int ret = 0; 
        for(int i=0;i<events.size();i++) {
            ret = max(ret, events[i][2]);
            auto ptr = m.upper_bound(events[i][1]);
            if(ptr != m.end()) {
                ret = max(ret, events[i][2] + ptr->second);
            }
        }
        return ret;
    }
};