typedef pair<string, int> PAIR;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(string s: words) {
            mp[s]++;
        }

        struct cmp {
            bool operator()(const PAIR a, const PAIR b) {
                if (a.second == b.second) {
                    return a.first > b.first;
                }
                return a.second < b.second;
            };
        };
        
        priority_queue<PAIR, vector<PAIR>, cmp> pq(mp.begin(), mp.end());
        vector<string> ans;
        while(k--) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};