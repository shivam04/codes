//space complexity O(1)
//time complexity O(2^N)
class Solution {
public:
    bool isValid(map<int,int> mp, string word) {
        for(char c: word) {
            mp[c-'a']--;
        }
        for(int i=0;i<26;i++) {
            if(mp[i]<0)
                return false;
        }
        return true;
    }
    int ans(map<int,int> mp, vector<string>& words, vector<int>& score, int i) {
        if(i>=words.size())
            return 0;
        
        if(isValid(mp, words[i])) {
            int inc = 0, exc = 0;
            int cs = 0;
            for(char c: words[i]) {
                cs += score[c-'a'];
                mp[c-'a']--;
            }
            inc = cs + ans(mp, words,score,i+1);
            for(char c: words[i]) {
                mp[c-'a']++;
            }
            exc = ans(mp, words, score,i+1);
            return max(inc, exc);
        }
        return ans(mp, words, score,i+1);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<int,int> mp;
        for(char letter: letters) {
            mp[letter-'a']+=1;
        }
        return ans(mp, words,score,0);
    }
};



//space complexity O(N*X)
//time complexity O(N)
//where X is the size of the largest string in words[] array.
class Solution {
public:
    map<string,int> dp;
    string getKey(map<int,int> mp, int i) {
        string key = "";
        for(auto it: mp) {
            key += (to_string(it.first) + ":" + to_string(it.second) + ",");
        }
        key += to_string(i);
        return key;
    }
    bool isValid(map<int,int> mp, string word) {
        for(char c: word) {
            mp[c-'a']--;
        }
        for(int i=0;i<26;i++) {
            if(mp[i]<0)
                return false;
        }
        return true;
    }
    int ans(map<int,int> mp, vector<string>& words, vector<int>& score, int i) {
        if(i>=words.size())
            return 0;
        string key = getKey(mp,i);
        if(dp.find(key)!=dp.end())
            return dp[key];
        if(isValid(mp, words[i])) {
            int inc = 0, exc = 0;
            int cs = 0;
            for(char c: words[i]) {
                cs += score[c-'a'];
                mp[c-'a']--;
            }
            inc = cs + ans(mp, words,score,i+1);
            for(char c: words[i]) {
                mp[c-'a']++;
            }
            exc = ans(mp, words, score,i+1);
            return dp[key] = max(inc, exc);
        }
        return dp[key] = ans(mp, words, score,i+1);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<int,int> mp;
        for(char letter: letters) {
            mp[letter-'a']+=1;
        }
        return ans(mp, words,score,0);
    }
};