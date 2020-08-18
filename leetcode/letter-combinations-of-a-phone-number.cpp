class Solution {
public:
    map<int, string> mp;
    void ans(vector<string> &k, string &A, string s, int ss){
        if(ss==A.length()){
            if(s!="")
                k.push_back(s);
            return ;
        }
        for(int j=0;j<mp[A[ss]-48].size();j++){
            ans(k, A, s+mp[A[ss]-48][j], ss+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        mp[0] = "0";
        mp[1] = "1";
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        string s = "";
        vector<string> k;
        ans(k, digits, s, 0);
        return k;
    }
};