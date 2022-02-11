class Solution {
public:
    int minSteps(string s, string t) {
        map<int, int> mp;
        for(char c:s){
            mp[c-'a']+=1;
        }
        
        for(char c:t){
            mp[c-'a']-=1;
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