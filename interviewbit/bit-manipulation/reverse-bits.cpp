unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    stack<int> s;
    while(A){
        s.push(A&1);
        A/=2;
    }
    int  g = s.size();
    unsigned int k = 0;
    int p = pow(2,32-g);
    while(!s.empty()){
        //cout<<s.top()<<"\n";
        int q = s.top();
        s.pop();
        k += (p*q);
        p*=2;
    }
    return k;
}