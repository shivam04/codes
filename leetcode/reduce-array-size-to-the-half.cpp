class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++) {
            mp[arr[i]]++;
        }
        vector<pair<int,int> > p;
        for(auto it = mp.begin();it != mp.end(); it++) {
            p.push_back({it->second, it->first});
        }
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());
        int c = 0;
        int s = 0;
        for(int i=0;i<p.size();i++) {
            c++;
            s+=p[i].first;
            if(s>=n/2) {
                return c;
            }
        }
        return c;
    }
};