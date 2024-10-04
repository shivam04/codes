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




class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int start = 0, maxLen = 0;
        for (int i=0;i<s.length();i++) {
            while (mp[s[i]] == 1) {
                mp[s[start]] = 0;
                start++;
            }
            mp[s[i]] = 1;
            maxLen = max(maxLen, i-start+1);
        }
        
        return maxLen;
    }
};