int preced(char ch) {
    if(ch == '+' || ch == '-') {
      return 1;           
   }else if(ch == '*' || ch == '/') {
      return 2;           
   }else if(ch == '^') {
      return 3;           
   }else {
      return 0;
   }
}
string Solution::solve(string A) {
    stack<char> s;
    string postfix = "";  
    for(char c: A) {
        if(isalnum(c)) {
            postfix += c;
        } else if(c=='(') {
            s.push(c);
        } else if(c == ')') {
            while(!s.empty() and s.top()!='(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while(!s.empty() && preced(c) <= preced(s.top())) {
                postfix += s.top();      
                s.pop();
            }
            s.push(c);
        }
    }
    while(!s.empty()) {
      postfix += s.top();        
      s.pop();
    }
    return postfix;

}
