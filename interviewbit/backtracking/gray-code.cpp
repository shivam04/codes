vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> b;
    b.push_back("0");
    b.push_back("1");
    vector<int> k;
    for (int i = 2; i <= A; i = i+1)
    {
        int m = b.size();
        for (int j = m-1 ; j >= 0 ; j--)
            b.push_back(b[j]);
        for (int j = 0 ; j < m ; j++)
            b[j] = "0" + b[j];
        for (int j = m ; j < 2*m ; j++)
            b[j] = "1" + b[j];
    }
    for(int i=0;i<b.size();i++){
        int p = 1;
        int num = 0;
        for(int j=b[i].length()-1;j>=0;j--){
            num = num + (b[i][j]-48)*p;
            p*=2;
        }
        k.push_back(num);
    }
    return k;
}