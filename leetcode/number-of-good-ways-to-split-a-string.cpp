class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        int pre[n+1],suf[n+1];
        unordered_map<char, int> mp;
        mp[s[0]] = 1;
        pre[0] = 1;
        for(int i=1;i<n;i++) {
            pre[i] = pre[i-1] + (mp[s[i]] == 0);
            mp[s[i]] = 1;
        }
        mp.clear();
        suf[n-1] = 1;
        mp[s[n-1]] = 1;
        for(int i=n-2;i>=0;i--) {
            suf[i] = suf[i+1] + (mp[s[i]] == 0);
            mp[s[i]] = 1;
        }
        int ans = 0;
        for(int i=0; i<n-1; i++) {
            int p = i;
            int q = i+1;
            if(pre[p]==suf[q]) {
                ans++;
            }
        }
        return ans;
    }
};