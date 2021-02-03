class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='(') {
                stk.push("(");
            } else if(s[i]==')') {
                string temp = stk.top();
                stk.pop();
                if(temp== "(") {
                    continue;
                }
                if(!stk.empty() and stk.top()[0]=='(') {
                    stk.pop();
                }
                reverse(temp.begin(), temp.end());
                if(!stk.empty() and stk.top()[0]!='(') {
                    temp = stk.top() + temp;
                    stk.pop();
                }
                stk.push(temp);
            } else {
                string temp = "";
                temp = temp + s[i];
                if(!stk.empty() and stk.top()[0] != '(') {
                    temp = stk.top() + temp;
                    stk.pop();
                    stk.push(temp);
                } else {
                    stk.push(temp);
                }
            }
        }
        return stk.top();
    }
};