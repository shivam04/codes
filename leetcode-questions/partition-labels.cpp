class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<int,int> last;
        for(int i=0;i<s.length();i++) {
            last[s[i]-'a'] = i;
        }
        vector<int> ans;
        int j = 0, a = 0;
        for(int i=0;i<s.length();i++) {
            j = max(j, last[s[i]-'a']);
            if(i==j){
                ans.push_back(i-a+1);
                a = i+1;
            }
        }
        return ans;
    }
};