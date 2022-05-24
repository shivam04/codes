class Solution {
public:
    map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        string key = s1 + "#" + s2;
        if(s1==s2)
            return true;
        if(mp.find(key)!=mp.end())
            return mp[key];
        int n = s1.length();
        bool flag = false;
        for(int k=1;k<n;k++) {
            if(isScramble(s1.substr(0,k), s2.substr(n-k)) 
               and isScramble(s1.substr(k), s2.substr(0,n-k))) {
                flag = true;
                break;
            }
            
            if(isScramble(s1.substr(0,k), s2.substr(0,k)) 
               and isScramble(s1.substr(k), s2.substr(k))) {
                flag = true;
                break;
            }
                
        }
        return mp[key]=flag;
    }
};