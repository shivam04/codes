class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s=="")
            return 0;
        unordered_map<char,int> mp;
        mp[s[0]] = 0;
        int cnt = 1, maxLen = 1, pi = -1;
        for (int i=1;i<s.length();i++) {
            if (mp.find(s[i]) != mp.end()) {
                pi = mp[s[i]];
            } else {
                pi = -1;
            }
            if (pi == -1 or i - cnt > pi) {
                cnt++;
            } else {
                maxLen = max(cnt, maxLen);
                cnt = i - pi;
            }
            mp[s[i]] = i;
        }
        
        return max(maxLen, cnt);
    }
};





class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int cnt = 0, maxLen = 0, pi = -1;
        for (int i=0;i<s.length();i++) {
            if (mp.find(s[i]) == mp.end() or i - cnt > mp[s[i]]) {
                cnt++;
            } else {
                maxLen = max(cnt, maxLen);
                cnt = i - mp[s[i]];
            }
            mp[s[i]] = i;
        }
        
        return max(maxLen, cnt);
    }
};