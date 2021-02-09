class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if(n<=2 || s[0]=='b' || s[0]=='c') {
            return false;
        }
        stack<char> st;
        for(int i=0;i<n;i++) {
            if(s[i]=='c') {
                if(!st.empty()) {
                    if(st.top() != 'b') 
                        return false;
                    st.pop();
                }
                if(!st.empty()) {
                    if(st.top() != 'a') 
                        return false;
                    st.pop();
                }
            } else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};