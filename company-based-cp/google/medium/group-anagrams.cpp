class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        for (string str: strs) {
            string k = str;
            sort(k.begin(), k.end());
            ump[k].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto it: ump) {
            vector<string> anss;
            for (string str: it.second) {
                anss.push_back(str);
            }
            ans.push_back(anss);
        }
        return ans;
    }
};