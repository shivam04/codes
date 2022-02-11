class Solution {
public:
    int numberOfSubstrings(string s) {
        int ret = 0;
        map <char, int> m;
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            m[s[i]]++;
            while(m['a'] > 0 && m['b'] > 0 && m['c'] > 0){
            m[s[j]]--;
            j++;
         }
         ret += j;
      }
      return ret;
    }
};