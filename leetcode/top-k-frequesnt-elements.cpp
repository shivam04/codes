class Solution {
public:
    vector<int> u;
    unordered_map<int,int> mp;
    int partition(int s, int e, int p) {
        int f = mp[u[p]];
        swap(u[p], u[e]);
        int i = s;
        for(int j=s;j<=e;j++) {
            if(mp[u[j]] < f) {
                swap(u[i], u[j]);
                i++;
            }
        }
        swap(u[i],u[e]);
        return i;
    }
    void quickselect(int s, int e, int k) {
        if(s==e)
            return;
        srand(time(NULL));
        int p = s + rand()%(e-s);
        p = partition(s, e, p);
        if(k==p) {
            return ;
        } else if(k < p) {
            quickselect(s, p-1, k);
        } else {
            quickselect(p + 1, e, k);  
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        mp.clear();
        for(auto x: nums) {
            mp[x]++;
        }
        int n = mp.size();
        int i = 0;
        for(auto it = mp.begin(); it!=mp.end();++it) {
            u.push_back(it->first);
        }
        quickselect(0, n - 1, n - k);
        vector<int> ans;
        for(int i=n-k;i<n;i++) {
            ans.push_back(u[i]);
        }
        return ans;
    }
};