int Solution::evalRPN(vector<string> &A) {
    long long ans = 0;
    stack<long long> ss;
    for(string s: A) {
        if(s == "+" or s == "-" or s=="/" or s=="*") {
            long long a = ss.top();
            ss.pop();
            long long b = ss.top();
            ss.pop();
            long long ans = 0;
            if(s=="+") {
                ans = a+b;
            } else if(s=="-") {
                ans = b-a;
            } else if(s=="*") {
                ans = a*b;
            } else if(s=="/") {
                ans = b/a;
            }
            
            ss.push(ans);
        } else {
            ss.push(stoll(s));
        }
    }
    return ss.top();
}
