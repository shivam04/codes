class Solution {
public:
    int n;
    vector<string> words;
    map<string, vector<string>> prefixHashTable;
    void buildPrefixTable() {
        for(auto word: words) {
            for (int i=1;i<=n;i++) {
                string prefix = word.substr(0, i);
                vector<string> prefixList = prefixHashTable[prefix];
                prefixList.push_back(word);
                prefixHashTable[prefix] = prefixList;
            }
        }
    }
    bool isPrefix(string word, string prefix) {
        int n = prefix.size();
        for (int i=0;i<n;i++) {
            if (prefix[i] != word[i]) {
                return false;
            }
        }
        return true;
    }
    
    void wordSquaresUtil(int step, vector<string> &wordSq,  vector<vector<string>> &ans) {
        if (n == step) {
            ans.push_back(wordSq);
        }

        string prefix = "";

        for (string word: wordSq) {
            prefix += word[step];
        }

        vector<string> wordsWithPrefix = prefixHashTable[prefix];
        for (auto word: wordsWithPrefix) {
            wordSq.push_back(word);
            wordSquaresUtil(step+1, wordSq, ans);
            wordSq.pop_back();
        }
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        n = words[0].length();
        this->words = words;
        buildPrefixTable();
        vector<vector<string>> ans;
        for (auto word: words) {
            vector<string> wordSq;
            wordSq.push_back(word);
            wordSquaresUtil(1, wordSq, ans);
        }
        return ans;
    }
};