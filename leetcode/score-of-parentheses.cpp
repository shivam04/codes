class Solution {
public:
    int scoreOfParentheses(string S) {
        int bal = 0;
        int ans = 0;
        for(int i=0;i<S.length();i++) {
            if(S[i] == '(')
                bal++;
            else {
                bal--;
                if(S[i-1]=='(')
                    ans += 1<<bal;
            }
        }
        return ans;
    }
};