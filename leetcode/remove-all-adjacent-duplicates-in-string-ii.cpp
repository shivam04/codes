class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        int n = s.size();
        for(int i=0;i<n;i++) {
            char x = s[i];
            if(!st.empty() && st.top().second == k) {
                st.pop();
            }
            if(st.empty() || st.top().first != x){
                st.push({x, 1});
            } else {
                st.top().second++;
            }
        }
        string ans = "";
        while(!st.empty()) {
            pair <char, int> temp = st.top();
            st.pop();
            if(temp.second==k) {
                continue;
            }
            while(temp.second--) ans += temp.first;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};