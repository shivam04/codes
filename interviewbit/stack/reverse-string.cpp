string Solution::reverseString(string A) {
    stack<char> s;
    int i;
    for(i=0;i<A.length();i++){
        s.push(A[i]);
    }
    A = "";
    while(!s.empty()){
        A = A+s.top();
        s.pop();
    }
    return  A;
}
