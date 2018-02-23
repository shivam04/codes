void Solution::reverseWords(string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string g="";
    for(int i=A.length()-1;i>=0;i--){
        string p="";
        while(i>=0 and A[i]!=' '){
            p = A[i]+p;
            i--;
        }
        g=g+" "+p;
    }
    //A = g;
    int i=0;
    while(i<g.length() and g[i]==' '){
        i++;
    }
    A = g.substr(i);
}
