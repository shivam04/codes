map<char,int> mp;
bool cmp(char a, char b) {
    return mp[a]<mp[b];
}
class Solution {
public:
    string customSortString(string S, string T) {
        mp.clear();
        for(int i=0;i<S.length();i++) {
            if(mp[S[i]] == 0)
                mp[S[i]] = i;
        }
        sort(T.begin(), T.end(), cmp);
        return T;
    }
};