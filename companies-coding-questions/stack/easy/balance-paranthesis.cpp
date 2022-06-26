int Solution::solve(string A) {
    stack<char> s;
    for(char c: A) {
        if(c=='(' or c=='{' or c=='[') {
            s.push(c);
        } else {
            if(!s.empty()) {
                if(c==']' and s.top()=='[') {
                    s.pop();
                } else if(c=='}' and s.top()=='{') {
                    s.pop();
                } else if(c==')' and s.top()=='(') {
                    s.pop();
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        }
    }
    return s.empty();
}
