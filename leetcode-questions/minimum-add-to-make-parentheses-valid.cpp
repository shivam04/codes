class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans = 0;
        for(auto c:s) {
            if(c=='(') {
                st.push(c);
            } else {
                if(c==')' and !st.empty() and st.top()=='(') {
                    st.pop();
                } else {
                    ans += 1;
                }
            }
        }
        return st.size() + ans;
    }
};