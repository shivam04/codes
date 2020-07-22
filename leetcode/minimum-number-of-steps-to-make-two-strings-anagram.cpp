bool cmp(int a, int b) {
    return a>b;
}
class Solution {
public:
    int minSteps(string s, string t) {
        map<int,int> mp;
        for(int i=0;i<s.length();i++) {
            mp[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++) {
            mp[t[i]-'a']--;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            if(mp[i]  > 0) {
                ans += mp[i];
            }
        }
        return ans;
    }
};