class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i'
            || c == 'o' || c == 'u');
    }
    int countFreq(string s){
        int cnt = 0;
        map<char, int> mp;
        int n = s.length();
        int start = 0;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
            while (mp['a'] > 0 && mp['e'] > 0
               && mp['i'] > 0 && mp['o'] > 0
               && mp['u'] > 0) {
                cnt += n-i;
                mp[s[start]]--;
                start++;
            }
        }
        return cnt;
    }
    int countVowelSubstrings(string s) {
        int cnt = 0;
        string t = "";
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                t += s[i];
            } else {
                if (t.length() > 0) {
                    cnt += countFreq(t);
                }
                t = "";
            }
        }
        if (t.length() > 0) {
            cnt += countFreq(t);
        }
        return cnt;
    }
};