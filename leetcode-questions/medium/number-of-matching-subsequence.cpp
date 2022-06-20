class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        int n = s.length();
        unordered_map<string, bool> mp;
        for(string word: words) {
            int m = word.size();
            size_t index= -1;
            int j;
            if(mp.find(word)==mp.end()) {
                for(j=0;j<m;j++) {
                    index = s.find(word[j], index+1);
                    if(index==string::npos) {
                        break;
                    }
                }
                mp[word] = (j==m);
            }
            ans += (mp[word]);
        }
        return ans;
    }
};