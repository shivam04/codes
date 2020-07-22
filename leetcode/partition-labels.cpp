class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<int,int> last;
        for(int i=0;i<S.length();i++){
            last[S[i]-'a'] = i;
        }
        vector<int> ans;
        int j = 0, a = 0;
        for(int i=0;i<S.length();i++) {
            j = max(j, last[S[i]-'a']);
            if(i==j) {
                ans.push_back(i-a+1);
                a = i+1;
            }
        }
        return ans;
    }
};