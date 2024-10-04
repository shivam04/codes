class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char,int> mp;
        int cnt = 0, maxLen = 0;
        int start = 0;
        for (int i=0;i<s.length();i++) {
            mp[s[i]]++;
            while (mp.size() > k) {
                mp[s[start]]--;
                if (mp[s[start]] == 0) {
                    mp.erase(s[start]);
                }
                start++;
            }
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};