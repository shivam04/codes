class Solution {
public:
    int getMinWordFreq(string word) {
        int counter[26] = {0};
        for (char c : word) {
            counter[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (counter[i] != 0) {
                return counter[i];
            }
        }
        return 0;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> list;
        for (string word : words) {
            list.push_back(getMinWordFreq(word));
        }
        vector<int> ans;
        sort(list.begin(), list.end());
        int len = list.size();
        for (string query : queries) {
            int minCount = getMinWordFreq(query);
            int idx = upper_bound(list.begin(), list.end(), minCount) - list.begin();
            ans.push_back(len-idx);
        }
        return ans;
    }
};