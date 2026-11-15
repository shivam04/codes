class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num: nums) {
            mp[num] += 1;
        }
        vector<pair<int, int>> data;
        vector<int> ans;
        for(auto it: mp) {
            data.push_back({it.first, it.second});
        }
        sort(data.begin(), data.end(), [](auto a, auto b) {
            return a.second > b.second;
        });

        for(int i=0;i<k;i++) {
            ans.push_back(data[i].first);
        }
        return ans;
    }
};