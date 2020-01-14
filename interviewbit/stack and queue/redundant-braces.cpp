int Solution::braces(string A) {
    stack<char> s;
    int flag=0,flag1=0;
    int n = A.length();
    for(int i=0;i<A.length();i++){
        char c = A[i];
        if(c == '(' || c == '+' || c == '-' || c == '*' || c == '/'){ 
            s.push(c); 
        }else if(c == ')'){ 
            if(s.top() == '('){ 
                return 1; 
            }else{ 
                while(!s.empty() && s.top() != '('){ 
                    s.pop(); 
                } 
                s.pop(); 
            } 
        }  
    }
    return 0;
}
