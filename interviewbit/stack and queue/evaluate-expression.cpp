int Solution::evalRPN(vector<string> &A) {
    stack<int> s;
    int i;
    for(i=0;i<A.size();i++){
        if(A[i]!="+" and A[i]!="-" and A[i]!="*" and A[i]!="/"){
            s.push(stoi(A[i]));
        }else{
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            int k;
            if(A[i]=="+"){
                k  = a+b;
            }else if(A[i]=="-"){
                k = b-a;
            }else if(A[i]=="*"){
                k = a*b;
            }else if(A[i]=="/"){
                k = b/a;
            }
            s.push(k);
        }
    }
    return s.top();
}
