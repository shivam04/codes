int Solution::isValid(string A) {
    stack<char> s;
    int i;
    for(i=0;i<A.length();i++){
        if(A[i]=='('||A[i]=='['||A[i]=='{'){
            s.push(A[i]);
        }else{
            if(s.size()==0)
            return 0;
            char p = s.top();
            s.pop();
            if(p=='(' and A[i]!=')')
            return 0;
            if(p=='[' and A[i]!=']')
            return 0;
            if(p=='{' and A[i]!='}')
            return 0;
        }
    }
    if(s.size()>0)
    return 0;
    return 1;
}
